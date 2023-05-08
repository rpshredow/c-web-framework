#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iostream>

#include "Cycle.h"
#include "HttpRequest.h"

#define PORT 8080
void Cycle::startServer() {
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Only this line has been changed. Everything is same.
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket"); 
        exit(EXIT_FAILURE);
    }
    

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    int b = bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    
    if ( b < 0 )
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    int l = listen(server_fd, 10);

    if ( l < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        printf("+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);

        std::string str(buffer);

        HttpRequest request(str);
        std::string uri = "/";
        if(uri.find(request.getUri()) != std::string::npos){
            write(new_socket, hello, strlen(hello));
            continue;
        }

        // std::cout << request.getUri() << std::endl;

        // printf("%s\n", buffer);
        char *response = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 12\n\nResource Not Found";
        write(new_socket , response , strlen(response));
        printf("-------------Hello message sent------------\n\n");
        close(new_socket);
    }
}
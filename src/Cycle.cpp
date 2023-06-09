#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>

#include "Cycle.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "MySql.h"
// #include "Model/PersonModel.h"

int new_socket;

void get(std::string uri, HttpRequest request, HttpResponse response) {
    if(uri.find(request.getUri()) != std::string::npos){
        // const char *res = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 4\n\nHome";
        response.setMessage("Home Page");
        std::string resp = response.getResponse();
        char * res = &resp[0];
        write(new_socket, res, strlen(res));
        std::cout << res << std::endl;
    }
}

#define PORT 8080
void Cycle::startServer() {
    int server_fd; 
    // long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
        
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

    MySql query;
    query.connectToDatabase();

    while(1)
    {
        printf("Waiting for new connection\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[4096] = {0};
        // valread = read( new_socket , buffer, 4096);
        read( new_socket , buffer, 4096);

        std::string request_raw(buffer);

        HttpResponse response;
        HttpRequest request(request_raw);

        // get("/", request, response);

        std::string uri = "/persons";
        if(uri.find(request.getUri()) != std::string::npos){
            // const char *res = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 4\n\nHome";
            

            std::string output = "";

            std::vector<PersonModel> myVector = query.getAll();
            for(const auto& obj : myVector) {
                output += "ID: " + std::to_string(obj.getId()) + ", Name: " + obj.getName() + ", Surname: " + obj.getSurname() + ", Email: " + obj.getEmail() + ", Password: " + obj.getPassword() + '\n'; 
            }

            response.setMessage(output);
            std::string resp = response.getResponse();
            char * res = &resp[0];
            write(new_socket, res, strlen(res));
            // std::cout << res << std::endl;
            close(new_socket);
            continue;
        }

        uri = "/hello";
        if(uri.find(request.getUri()) != std::string::npos){
            //const char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
            response.setMessage("Hello, World!");
            std::string resp = response.getResponse();
            char * res = &resp[0];
            write(new_socket, res, strlen(res));
            close(new_socket);
            continue;
        }

        // std::cout << request.getUri() << std::endl;

        // printf("%s\n", buffer);
        const char *resp = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 18\n\nResource not found";
        write(new_socket , resp , strlen(resp));
        close(new_socket);
    }
}

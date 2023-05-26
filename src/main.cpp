// Server side C program to demonstrate HTTP Server programming
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iostream>

#include "Cycle.h"

#define PORT 8080
int main(int argc, char const *argv[])
{
    Cycle app;

    app.startServer();

    return 0;
}
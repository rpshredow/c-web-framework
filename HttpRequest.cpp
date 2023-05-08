#include "HttpRequest.h"

#include <iostream>
#include <sstream>
#include <string>

HttpRequest::HttpRequest(std::string raw_request) : raw_request(raw_request){
    PopulateData();
}

void HttpRequest::PrintRawData() {
    std::cout << raw_request << std::endl;
}

void HttpRequest::PopulateData() {
    std::string str = raw_request;
    std::string::size_type pos = str.find('\n'); // Find first newline character
    if (pos != std::string::npos) {
        str = str.substr(0, pos); // Extract substring up to newline
    }

    std::stringstream ss(str);
    std::string array[3];
    std::string word;
    int i = 0;

    while (ss >> word) {
        array[i] = word;
        i++;
    }

    method = array[0];
    uri = array[1];
    httpVersion = array[2];
}

std::string HttpRequest::getMethod() {
    return method;
}

std::string HttpRequest::getUri() {
    return uri;
}

std::string HttpRequest::getHttpVersion() {
    return httpVersion;
}
#include "HttpRequest.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

HttpRequest::HttpRequest(std::string raw_request) : raw_request(raw_request){
    PopulateData();
}

void HttpRequest::PrintRawData() {
    std::cout << raw_request << std::endl;
}

void HttpRequest::PopulateData() {
    std::string request_data = raw_request;
    std::istringstream iss(request_data);
    std::vector<std::string> lines;
    std::string line;

    while(std::getline(iss, line)) {
        lines.push_back(line);
    }

    std::stringstream ss(lines[0]);
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
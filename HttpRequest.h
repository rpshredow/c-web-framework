#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <map>

class HttpRequest {
    public: 
        HttpRequest();
        HttpRequest(std::string raw_request);
        std::string getMethod();
        std::string getUri();
        std::string getHttpVersion();

    private:
        std::string method;
        std::string uri;
        std::string httpVersion;
        std:: string raw_request;
        std::map<std::string, std::string> headerElements;
        void PrintRawData();
        void PopulateData();
        
};

#endif
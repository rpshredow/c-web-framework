#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>

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
        void PrintRawData();
        void PopulateData();
        
};

#endif
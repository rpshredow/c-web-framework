#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>

class HttpResponse {
    public: 
        HttpResponse();
        std::string getResponse();
        void setMessage(std::string message);
        void setContentType(std::string type);
        void setStatusCode(int code);
    private:
        std::string httpVersion;
        int status_code;
        std::string status_text;
        std::string content_type;
        int content_length;
        std::string message_body;
};

#endif
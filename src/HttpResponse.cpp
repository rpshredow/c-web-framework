#include "HttpResponse.h"

#include <string>
#include <iostream>

HttpResponse::HttpResponse(){
    httpVersion = "HTTP/1.1";
    status_code = 200;
    status_text = "OK";
    content_type = "text/plain";
    content_length = 0;
    message_body = "";
}

std::string HttpResponse::getResponse() {
    std::string response = httpVersion + " " + std::to_string(status_code) + " ";
        response += status_text + "\r\nContent-Type: " + content_type;
        response += "\r\nContent-Length: " + std::to_string((message_body.size() * sizeof(char)));
        response += "\r\n\r\n" + message_body;

    return response;
}

void HttpResponse::setMessage(std::string message) {
    message_body = message;
}

void HttpResponse::setContentType(std::string type) {
    content_type = type;
}

void HttpResponse::setStatusCode(int code) {
    status_code = code;

    switch (code)
    {
    case 100:
        status_text = "Continue";
        break;
    case 101:
        status_text = "Switching Protocols";
        break;
    case 102:
        status_text = "Processing";
        break;
    case 103:
        status_text = "Early Hints";
        break;
    case 201:
        status_text = "Created";
        break;
    case 202:
        status_text = "Accepted";
        break;
    case 203:
        status_text = "Non-Authoritative Information";
        break;
    case 204:
        status_text = "No Content";
        break;
    case 205:
        status_text = "Reset Content";
        break;
    case 206:
        status_text = "Partial Content";
        break;
    case 207:
        status_text = "Multi-Status";
        break;
    case 208:
        status_text = "Already Reported";
        break;
    case 226:
        status_text = "Already Reported";
        break;
    case 300:
        status_text = "Multiple Choices";
        break;
    case 301 :
        status_text = "Moved Permanently";
        break;
    case 302:
        status_text = "Found";
        break;
    case 303:
        status_text = "See Other";
        break;
    case 304:
        status_text = "Not Modified";
        break;
    case 305:
        status_text = "Use Proxy";
        break;
    case 307:
        status_text = "Temporary Redirect";
        break;
    case 308:
        status_text = "Permanent Redirect";
        break;
    case 400:
        status_text = "Bad Request";
        break;
    case 401:
        status_text = "Unauthorized";
        break;
    case 402:
        status_text = "Payment Required";
        break;
    case 403:
        status_text = "Forbidden";
        break;
    case 404:
        status_text = "Not Found";
        break;
    case 405:
        status_text = "Method Not Allowed";
        break;
    case 406:
        status_text = "Not Acceptable";
        break;
    case 407:
        status_text = "Proxy Authentication Required";
        break;
    case 408:
        status_text = "Request Timeout";
        break;
    case 409:
        status_text = "Conflict";
        break;
    case 410:
        status_text = "Gone";
        break;
    case 411:
        status_text = "Length Required";
        break;
    case 412:
        status_text = "Precondition Failed";
        break;
    case 413:
        status_text = "Payload Too Large";
        break;
    case 414 :
        status_text = "URI Too Long";
        break;
    case 415:
        status_text = "Unsupported Media Type";
        break;
    case 416:
        status_text = "Range Not Satisfiable";
        break;
    case 417:
        status_text = "Expectation Failed";
        break;
    case 418:
        status_text = "I'm a teapot";
        break;
    case 421:
        status_text = "Misdirected Request";
        break;
    case 422:
        status_text = "Unprocessable Content";
        break;
    case 423:
        status_text = "Locked";
        break;
    case 424:
        status_text = "Failed Dependency";
        break;
    case 425:
        status_text = "Too Early";
        break;
    case 426:
        status_text = "Upgrade Required";
        break;
    case 428:
        status_text = "Precondition Required";
        break;
    case 429:
        status_text = "Too Many Requests";
        break;
    case 431:
        status_text = "Request Header Fields Too Large";
        break;
    case 451:
        status_text = "Unavailable For Legal Reasons";
        break;
    case 500:
        status_text = "Internal Server Error";
        break;
    case 501:
        status_text = "Not Implemented";
        break;
    case 502:
        status_text = "Bad Gateway";
        break;
    case 503:
        status_text = "Service Unavailable";
        break;
    case 504:
        status_text = "Gateway Timeout";
        break;
    case 505:
        status_text = "HTTP Version Not Supported";
        break;
    case 506:
        status_text = "Variant Also Negotiates";
        break;
    case 507:
        status_text = "Insufficient Storage";
        break;
    case 508:
        status_text = "Loop Detected";
        break;
    case 510:
        status_text = "Not Extended";
        break;
    case 511:
        status_text = "Network Authentication Required";
        break;
 
    
    default:
        break;
    }
}
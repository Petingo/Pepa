#ifndef PEPA_HTTP_RESPONSE
#define PEPA_HTTP_RESPONSE

#include <string.h>
#include <stdlib.h>
#include <Arduino.h>

namespace pepa{

class HttpResponse
{
public:
    int contentLength;
    int status;
    String data;

    HttpResponse() = default;
    HttpResponse(String response);

    ~HttpResponse() = default;

private:
    void parsePlainText(String response);
};

}


//void HttpResponse::ParseHTML(const char* response) {
//    body = "";
//
//    String buf = "";
//    String key = "", value = "";
//
//    int i = 0;
//    int respLen = strlen(response);
//
//    // for(int i = 0; i < respLen; i++){
//    //     Serial.print(String("(") + String(int(response[i])) + String(")") + String(response[i]) + String("/"));
//    // }
//
//    // consume HTTP
//    while(i < respLen && response[i] != ' '){
//        i++;
//    }
//    i++; // consume space
//
//    // parse status
//    while(i < respLen && response[i] != ' '){
//        buf += response[i];
//        i++;
//    }
//    status = atoi(buf.c_str());
//    i++;
//
//    // parse remain char in the first line
//    while(i < respLen && response[i] != '\r'){
//        i++;
//    }
//    i++; i++; // consume '\r\n'
//
//    // parse header key-value pairs
//    while(i < respLen && response[i] != '\r'){
//        // response body starts
//        if (response[i] == '\r'){
//            i++;
//            break;
//        }
//
//        // parse key
//        while(i < respLen && response[i] != ':'){
//            key += response[i];
//            i++;
//        }
//        i++; // consume ':'
//        i++; // consume space
//
//        // parse value
//        while(i < respLen && response[i] != '\r'){
//            value += response[i];
//            i++;
//        }
//        i++; i++; // consume '\r\n'
//
//        if (key == String("Content-Length")){
//            contentLength = atoi(value.c_str());
//        }
//
//        key = "";
//        value = "";
//    }
//
//    i++; i++; // consume '\r\n'
//
//    while(i < respLen){
//        body += response[i];
//        i++;
//    }
//
//    printf("body: %s\n", body.c_str());
//
//}

#endif
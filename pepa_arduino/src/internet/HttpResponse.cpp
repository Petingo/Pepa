#include "HttpResponse.h"

namespace pepa {

HttpResponse::HttpResponse(bool succeed) : succeed(succeed) {
    // do nothing
    Serial.println("Construct empty HttpResponse");
}

HttpResponse::HttpResponse(String &response) : succeed(true) {
    Serial.println("Start parsing response...");
    parseHeader(response);
    parsePlainText(response);
}

void HttpResponse::parseHeader(String &response) {
    int i = 0;
    String key = "", value = "";

    // parse status (HTTP/1.1 200 OK)
    while (i < response.length() && response[i] != ' ') i++;
    i++;
    while (i < response.length() && response[i] != ' ') {
        value += response[i];
        i++;
    }
    status = atoi(value.c_str());
    while (i < response.length() && response[i] != '\n') i++;
    i++;

    // parse key-value pair in header
    while (true) {
        key = "";
        value = "";

        bool hasKey = true;
        // parse key
        while (i < response.length() && response[i] != ':') {
            if (response[i] == '\n') {
                i++; // consume '\n'
                hasKey = false;
                break;
            }
            key += response[i];
            i++;

        }
        if (!hasKey) break;

        i++;
        i++;// consume ': '
        // parse value
        while (i < response.length() && response[i] != '\r' && response[i] != '\n') {
            value += response[i];
            i++;
        }
        i++; // consume '\n'

        if (key == "Content-Length") {
            contentLength = atoi(value.c_str());
        } else if (key == "Content-Type") {
            if (value.startsWith("text/plain")) {
                contentType = TEXT_PLAIN;
            } else if (value.startsWith("application/json")) {
                contentType = APPLICATION_JSON;
            } else {
                contentType = UNKNOWN;
            }
        }

        if (i < response.length() && response[i] == '\r') {
            i++; // consume '\r'
        }
        if (i < response.length() && response[i] == '\n') {
            i++; // consume '\n'
        }
    }

    // header end, current i is the start of body
    response.remove(0, i);

    // trim the response
    response.trim();
}

void HttpResponse::parsePlainText(String &response) {
    content = response;
}

String HttpResponse::toString() {
    String str = "";
    str += "Status=" + String(status) + "\n";
    str += "Content-Length=" + String(contentLength) + "\n";
    str += "Content-Type=" + String(contentType) + "\n";
    str += "Content=" + content;
    return str;
}

}
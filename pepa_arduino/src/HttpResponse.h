#ifndef PEPA_HTTP_RESPONSE
#define PEPA_HTTP_RESPONSE

#include <stdlib.h>
#include <Arduino.h>

namespace pepa{

class HttpResponse
{
public:
    enum ContentType {
        TEXT_PLAIN,
        APPLICATION_JSON,
        UNKNOWN
    };

    bool succeed;

    int contentLength;
    int status;
    ContentType contentType;
    String content;

    HttpResponse(bool succeed);
    HttpResponse(String& response);

    ~HttpResponse() = default;

    String toString();

private:
    void parseHeader(String& response);
    void parsePlainText(String& response);
};

}

#endif
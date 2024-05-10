#ifndef PEPA_HTTP_RESPONSE
#define PEPA_HTTP_RESPONSE

#include <stdlib.h>
#include <Arduino.h>

namespace pepa{

/**
 * @brief: The class for parsing the HTTP response from the server
 */
class HttpResponse
{
public:
    enum ContentType {
        TEXT_PLAIN,
        APPLICATION_JSON,
        UNKNOWN
    };

    HttpResponse(bool succeed);
    HttpResponse(String& response);

    ~HttpResponse() = default;

    String toString();

public:
    bool succeed;

    int contentLength;
    int status;
    ContentType contentType;
    String content;

private:
    void parseHeader(String& response);
    void parsePlainText(String& response);
};

}

#endif
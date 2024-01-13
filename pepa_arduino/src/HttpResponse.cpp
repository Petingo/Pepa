#include "HttpResponse.h"

namespace pepa
{

HttpResponse::HttpResponse(String response) {
    parsePlainText(response);
}

void HttpResponse::parsePlainText(String response)
{
    data = response;
    Serial.println(String(response));
}

}
#include <WiFi.h>

#include "HttpResponse.h"

HttpResponse httpGet(WiFiClient client, const char* host, int port, const char* path) {
    if (client.connect(host, port)) {
        // Make a HTTP request:
        client.println("GET " + String(path) + " HTTP/1.1");
        client.println("Host: " + String(host));
        client.println("Connection: close");
        client.println();
    } else {
        Serial.println("Connection to server failed");
    }

    int maxloops = 0;

    //wait for the server's reply to become available
    while (!client.available() && maxloops < 1000)
    {
        maxloops++;
        delay(10); //delay 1 msec
    }
    
    if (client.available() > 0)
    {
        //read back one line from the server
        HttpResponse response(client.readStringUntil(EOF).c_str());
        return response;
    } else {
        return HttpResponse();
    }
}
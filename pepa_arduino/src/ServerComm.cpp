#include "ServerComm.h"

namespace pepa
{

void ServerComm::init(){
    WiFiConnection::Connect();
    client.setCACert(m_rootCA);
}

void ServerComm::updateTime(ESP32Time &rtc) {
    HttpResponse resp = httpGet(m_pathTime);
    Serial.println("Response: " + resp.data);
}

HttpResponse ServerComm::httpGet(String path) {
    if (client.connect(m_host.c_str(), m_port)) {
        // Make a HTTP request:
        client.println("GET " + path + " HTTP/1.1");
        client.println("Host: " + m_host);
        client.println("Connection: close");
        client.println();
    } else {
        Serial.println("Connection to server failed");
    }

    // wait for the server's reply to become available
    int counter = 0;
    while (!client.available() && counter < 1000)
    {
        counter++;
        delay(10);
    }

    if (client.available() > 0)
    {
        //read back one line from the server
        HttpResponse response(client.readStringUntil(EOF));
        return response;
    } else {
        return HttpResponse();
    }
}

}
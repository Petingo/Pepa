#include "ServerComm.h"

namespace pepa
{

void ServerComm::init(){
    WiFiConnection::Connect();
    // clientSec.setCACert(m_rootCA);
}

void ServerComm::updateTime(ESP32Time &rtc) {
    HttpResponse resp = httpGet(m_pathTimestamp);

    // for debug
    if(!resp.succeed){
        Serial.println("Failed to get timestamp from server");
        rtc.setTime(1705266901l);
        return;
    }
    rtc.setTime(atoll(resp.content.c_str()) + 3600); // convert from UTC to CET
}

HttpResponse ServerComm::httpGet(const String& path) {
    if (!client.connect(m_host.c_str(), m_port)) {
        Serial.println("Connection to server failed");
        return HttpResponse(false);
    }

    // Make a HTTP request:
    client.println("GET https://" + m_host + path + " HTTP/1.1");
    client.println("Host: " + m_host);
    client.println("Connection: close");
    client.println();

    // wait for the server's reply to become available
    int counter = 0;
    while (!client.available() && counter < 1000)
    {
        counter++;
        delay(10);
    }

    if (client.available() <= 0) return HttpResponse(false);

    //read back one line from the server
    String rawResponse = client.readStringUntil(EOF);
    return HttpResponse(rawResponse);
}

}
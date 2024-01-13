#include "WiFiConnection.h"

namespace pepa {

const char* WiFiConnection::SSID = "Petingo";
const char* WiFiConnection::PWD = "meowmeow";

void WiFiConnection::Connect() {
    Serial.print("Waiting for WiFi...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PWD);

    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("Successfully connected to " + String(SSID) + " with IP " + WiFi.localIP().toString());
}

} // pepa
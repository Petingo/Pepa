#include "WiFiConnection.h"

namespace pepa {

const char* WiFiConnection::SSID = "Petingo";
const char* WiFiConnection::PWD = "meowmeow";

void WiFiConnection::Connect() {
    Serial.print("Connecting to WiFi...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PWD);

    int count = 0;
    while(WiFi.status() != WL_CONNECTED && count < 3) {
        Serial.print(".");
        delay(500);
    }
    Serial.println();

    if(WiFi.status() != WL_CONNECTED) {
        Serial.println("Failed to connect to WiFi");
        return;
    }

    Serial.println("Successfully connected to " + String(SSID) + " with IP " + WiFi.localIP().toString());
}

} // pepa
#include <WiFi.h>

const char* ssid = "Andy's iPhone";
const char* pwd  = "meowmeow";

void ConnectToWifi(){
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Waiting for WiFi...");

    WiFi.mode(WIFI_STA); //設置WiFi模式
    WiFi.begin(ssid, pwd);

    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("Connected");
}
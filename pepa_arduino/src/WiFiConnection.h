#ifndef PEPA_WIFICONNECTION_H
#define PEPA_WIFICONNECTION_H

#include <WiFi.h>

namespace pepa {

class WiFiConnection
{
public:
    static const char* SSID;
    static const char* PWD;
    static void Connect();
};

} // pepa

#endif //PEPA_WIFICONNECTION_H

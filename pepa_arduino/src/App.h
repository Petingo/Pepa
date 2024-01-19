#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <Arduino.h>

#include "3rdparty/ESP32Time/ESP32Time.h"
#include "EInk/DEV_Config.h"
#include "EInk/EPD.h"
#include "EInk/GUI_Paint.h"
#include "CustomPaint.h"
#include "ServerComm.h"
#include "GUI/GUI.h"

namespace pepa
{   
class App
{
public:
    App() = default;
    ~App() = default;

    void init();
    void loopUpdate();

    void displayTest1();
    void getNextDepartureTime();

private:
    void m_getCurrentTimeString(char* buffer);

public:
    GUI gui;

private:
    ServerComm m_serverComm;
    ESP32Time m_rtc;
};

} // namespace pepa

#endif
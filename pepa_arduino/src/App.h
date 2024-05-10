#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <Arduino.h>

#include "3rdparty/ESP32Time/ESP32Time.h"
#include "EInk/DEV_Config.h"
#include "EInk/EPD.h"
#include "EInk/GUI_Paint.h"
#include "gui/CustomPaint.h"
#include "internet/ServerComm.h"
#include "GUI/GUI.h"

namespace pepa
{

class App
{
public:
    App() = default;
    ~App() = default;

    /**
     * @brief: Initialize the app, including the GUI, server communication, and RTC
     */
    void init();

    /**
     * @brief: Called in the Arduino loop, update the info and refresh the screen
     */
    void loopUpdate();


    // below are the functions for testing
    void getNextDepartureTime();
    void displayTest1();

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
#include "App.h"
#include "WiFiConnection.h"
#include "TimetableInstance.h"

namespace pepa
{

App::App()
{

}

void App::init()
{
    DEV_Module_Init();

    gui.init();
    m_rtc.setTime(1705266901l);

//    gui.draw();
    // Init server communication
//    m_serverComm.init();
//    m_serverComm.updateTime(m_rtc);
//    Serial.println("Current time: " + m_rtc.getDateTime());

    // Init timetables
    // initAllTimetables();

    // test
    // getNextDepartureTime();
}

void App::loopUpdate() {
    char timeString[6];
    sprintf(timeString, "%02d:%02d", m_rtc.getMinute(), m_rtc.getSecond());
    gui.timeBlock.setText(timeString);

    gui.draw();
}

void App::m_getCurrentTimeString(char* buffer) {
    sprintf(buffer, "%02d:%02d", m_rtc.getHour(true), m_rtc.getMinute());
}

void App::displayTest1()
{
    gui.draw();

//    printf("Goto Sleep...\r\n");
//    EPD_3IN7_Sleep();

//    char timeString[6];
//    sprintf(timeString, "%02d:%02d", m_rtc.getHour(true), m_rtc.getMinute());
//    Paint_DrawString_EN(10, 10, timeString, &Font24, BLACK, WHITE);
//    Paint_DrawString_EN(10, 36, "19.6C 34%", &Font16, WHITE, GRAY3);
//
//    // Create test todo list
//    String todoList[4] = {
//            "1.Meow",
//            "2.This is a very long long long long todo list we should be able to wrap it to the next line",
//            "3.I hope this one works",
//            "4.AVeryLongVocabularyShouldBeCutUntilItFillTheScreen"
//    };
//
//    uint16_t anchorX = 10, anchorY = 100;
//    for (int i = 0; i < 4; i++) {
//        anchorY = drawWrappedString(anchorX, anchorY, todoList[i].c_str(), &Font16, WHITE, BLACK);
//        anchorY += 24;
//    }

//    gui.draw();
//     EPD_3IN7_4Gray_Display(gui.m_displayBuffer);

//     gui.draw();
}

void App::getNextDepartureTime()
{
    int hour, minute;
    s_bus24.getNextDepartureTime(2, 7, 33, false, hour, minute);
    Serial.println("Next departure time: " + String(hour) + ":" + String(minute));
    delay(50);

    s_bus24.getNextDepartureTime(2, 9, 0, false, hour, minute);
    Serial.println("Next departure time: " + String(hour) + ":" + String(minute));
    delay(50);

    s_bus24.getNextDepartureTime(2, 3, 2, false, hour, minute);
    Serial.println("Next departure time: " + String(hour) + ":" + String(minute));
    delay(50);

    s_bus24.getNextDepartureTime(2, 23, 2, false, hour, minute);
    Serial.println("Next departure time: " + String(hour) + ":" + String(minute));
}

} // namespace pepa
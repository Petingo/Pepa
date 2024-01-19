#include "App.h"
#include "internet/WiFiConnection.h"
#include "timetable/TimetableInstance.h"

namespace pepa
{

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
    sprintf(timeString, "%02d:%02d", m_rtc.getHour(true), m_rtc.getSecond());
    gui.timeBlock.setText(timeString);

    char bus24TimeString[6] = "13/28";
    gui.bus24TimeBlock.setText(bus24TimeString);

    char bus2TimeString[6] = " 5/ 9";
    gui.bus2TimeBlock.setText(bus2TimeString);

    char bus1TimeString[6] = "<1/16";
    gui.bus1TimeBlock.setText(bus1TimeString);

    char bus25WTimeString[6] = "<1/16";
    gui.bus25WTimeBlock.setText(bus25WTimeString);

    char bus25ETimeString[6] = "<1/16";
    gui.bus25ETimeBlock.setText(bus25ETimeString);

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
#include "App.h"
#include "WiFiConnection.h"
#include "TimetableInstance.h"

namespace pepa
{

App::App()
{
    m_displaySize = ((EPD_3IN7_WIDTH % 4 == 0) ? (EPD_3IN7_WIDTH / 4) : (EPD_3IN7_WIDTH / 4 + 1)) * EPD_3IN7_HEIGHT;

    if ((m_displayBuffer = (uint8_t *)malloc(m_displaySize)) == NULL) {
        Serial.println("Failed to apply for black memory...\r\n");
    }
}

void App::init()
{
    DEV_Module_Init();

    Serial.println("Init E-paper...");
    EPD_3IN7_4Gray_Init();
    EPD_3IN7_4Gray_Clear();

    delay(50);

    Paint_NewImage(m_displayBuffer, EPD_3IN7_WIDTH, EPD_3IN7_HEIGHT, 0, WHITE);
    Paint_SetScale(4);
    Paint_Clear(WHITE);

    // Init server communication
    m_serverComm.init();
    m_serverComm.updateTime(m_rtc);

    // test
    initAllTimetables();
    getNextDepartureTime();
}

void App::displayTest1()
{
    char timeString[6];
    sprintf(timeString, "%02d:%02d", 11, 33);

    Paint_DrawString_EN(10, 10, timeString, &Font24, WHITE, BLACK);
    Paint_DrawString_EN(10, 36, "19.6C 34%", &Font16, WHITE, GRAY3);

    // // Create test todo-list
    String todoList[] = {
        "1.Meow",
        "2.Buy eggs",
        "3.Buy bread",
        "4.Buy butter",
        "5.This is a very long long long long todo list we should be able to wrap it to the next line",
        "6.I hope this one works",
        "7.WWWWWWWWWWWWWHHHHHHHHHHHAAAAAAAATTTTTTTTTT"};

    uint16_t anchorX = 10, anchorY = 100;
    for (int i = 0; i < 7; i++) {
        anchorY = drawWrappedString(anchorX, anchorY, todoList[i].c_str(), &Font16, WHITE, BLACK);
        anchorY += 24;
    }

    EPD_3IN7_4Gray_Display(m_displayBuffer);
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
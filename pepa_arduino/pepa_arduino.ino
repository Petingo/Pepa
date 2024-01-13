#include "src/App.h"

void setup() {
    pepa::App app = pepa::App();
    app.init();
    
    app.displayTest1();
    
    // ConnectToWifi();
    // Sync time with server
    // Serial.println("Sync time with server...");
    // HttpResponse time = httpGet(client, host, port, pathGetTime);
    // Serial.println(time.body);

    // int year=2023, month=11, day=11, hour=11, minute=11, second=11;
    // sscanf(time.body.c_str(), "%d/%d/%d %d:%d:%d", year, month, day, hour, minute, second);
    // rtc.setTime(timeResponse.body.toInt() + 3600); // covert to UTC+1
    // Serial.println("Time is set to: " + rtc.getDateTime());
}

void loop() {
    // Paint_SelectImage(BlackImage);
    // Paint_SetScale(2);
    // Paint_Clear(WHITE);

    // PAINT_TIME sPaint_time;
    // sPaint_time.Sec = rtc.getSecond();
    // sPaint_time.Min = rtc.getMinute();
    // sPaint_time.Hour = rtc.getHour();
    // Paint_ClearWindows(0, 300, 80, 479, WHITE);
    // Paint_DrawTime(20, 300, &sPaint_time, &Font20, WHITE, BLACK);

    // printf("Part refresh...\r\n");
    // EPD_3IN7_1Gray_Display(BlackImage);
    // // EPD_3IN7_1Gray_Display_Part(BlackImage, 0, 0, 279, 180);
    // DEV_Delay_ms(500);
    
    // Serial.println("Current time: " + rtc.getDateTime());
    // delay(5000);
}

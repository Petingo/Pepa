#include "src/App.h"

pepa::App app = pepa::App();

void setup() {
    app.init();
}

void loop() {
     Serial.println("loop");
     app.loopUpdate();
     EPD_3IN7_Sleep();
     delay(5000);

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

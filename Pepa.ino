#include "src/custom_paint.h"

#include <stdlib.h>
// #include <WiFi.h>
#include <ESP32Time.h>

#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"

// #include "src/WiFIConnection.h"
// #include "src/http/HttpRequest.h"
// #include "src/http/HttpResponse.h"

// // ESP32Time rtc;
// WiFiClient client;

// API
const char host[] = "http://europe-west6-pepa-404619.cloudfunctions.net";
const int port = 80;

const char pathGetTime[] = "getTime";

// E-paper
// Create a new image cache
UBYTE *BlackImage;

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.println("Begin setup");
    
    
    // ConnectToWifi();

    // // Sync time with server
    // Serial.println("Sync time with server...");
    // HttpResponse time = httpGet(client, host, port, pathGetTime);
    // Serial.println(time.body);

    int year = 2023, month=11, day=11, hour=11, minute=11, second=11;
    // sscanf(time.body.c_str(), "%d/%d/%d %d:%d:%d", year, month, day, hour, minute, second);

    

    // rtc.setTime(timeResponse.body.toInt() + 3600); // covert to UTC+1
    // Serial.println("Time is set to: " + rtc.getDateTime());
    
    Serial.println("Init E-paper...");
    // Setup E-paper
    DEV_Module_Init();
    EPD_3IN7_4Gray_Init();
    EPD_3IN7_4Gray_Clear();
    DEV_Delay_ms(500);

    UWORD Imagesize = ((EPD_3IN7_WIDTH % 4 == 0)? (EPD_3IN7_WIDTH / 4 ): (EPD_3IN7_WIDTH / 4 + 1)) * EPD_3IN7_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        Serial.println("Failed to apply for black memory...\r\n");
        while(1);
    }

    Paint_NewImage(BlackImage, EPD_3IN7_WIDTH, EPD_3IN7_HEIGHT, 180, WHITE);
    Paint_SetScale(4);
    Paint_Clear(WHITE);

    // Paint_DrawString_EN(10, 150, "GRAY1 with black background", &Font24, BLACK, GRAY1);
    char timeString[6];
    sprintf(timeString, "%02d:%02d", hour, minute);

    Paint_DrawString_EN(10, 10, timeString, &Font24, WHITE, BLACK);
    Paint_DrawString_EN(10, 36, "19.6C 34%", &Font16, WHITE, GRAY3);

    // // Create test todo-list
    String todoList[] = {
        "Hello Kai",
        "2.Buy eggs",
        "3.Buy bread",
        "4.Buy butter",
        "5.This is a very long long long long todo list we should be able to wrap it to the next line",
        "6.I hope this one works",
        "7.WWWWWWWWWWWWWHHHHHHHHHHHAAAAAAAATTTTTTTTTT"
    };

    UWORD anchorX = 10, anchorY = 100;
    for(int i = 0; i < 7; i++){
        anchorY = DrawWrappedString(anchorX, anchorY, todoList[i].c_str(), &Font16, WHITE, BLACK);
        anchorY += 24;
    }

    EPD_3IN7_4Gray_Display(BlackImage);

    
    

    // // Drawing on the image, partial display
    // //1.Select Image
    // printf("SelectImage:BlackImage\r\n");
    // Paint_SelectImage(BlackImage);
    // Paint_SetScale(4);
    // Paint_Clear(WHITE);

    // // 2.Drawing on the image
    // printf("Drawing:BlackImage\r\n");
    // Paint_DrawPoint(10, 80, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    // Paint_DrawPoint(10, 90, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
    // Paint_DrawPoint(10, 100, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    // Paint_DrawLine(20, 70, 70, 120, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawLine(70, 70, 20, 120, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawRectangle(20, 70, 70, 120, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(80, 70, 130, 120, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    // Paint_DrawCircle(45, 95, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    // Paint_DrawCircle(105, 95, 20, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    // Paint_DrawLine(85, 95, 125, 95, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    // Paint_DrawLine(105, 75, 105, 115, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    // Paint_DrawNum(10, 33, 123456789, &Font12, BLACK, WHITE);
    // Paint_DrawNum(10, 50, 987654321, &Font16, WHITE, BLACK);

    // // Paint_DrawString_EN(0, 0, WiFi.localIP().toString().c_str(), &Font12, BLACK, WHITE);

    // printf("EPD_Display\r\n");
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

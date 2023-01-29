#include <stdlib.h>
#include <WiFi.h>
#include <ESP32Time.h>

#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "WiFIConnection.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

ESP32Time rtc;
WiFiClient client;

// API
const char host[] = "hs.petingo.ch";
const int port = 5566;

const char pathTime[] = "/time";

void setup() {
    Serial.begin(115200);
    delay(10);
    
    ConnectToWifi();

    Serial.println("Sync time with server...");
    HttpResponse timeResponse = httpGet(client, host, port, pathTime);
    rtc.setTime(timeResponse.body.toInt() + 3600); // covert to UTC+1
    Serial.println("Time is set to: " + rtc.getDateTime());

    // printf("EPD_3IN7_test Demo\r\n");
    // DEV_Module_Init();

    // printf("e-Paper Init and Clear...\r\n");
    // EPD_3IN7_4Gray_Init();
    // EPD_3IN7_4Gray_Clear();
    // DEV_Delay_ms(500);

    // //Create a new image cache
    // UBYTE *BlackImage;

    // UWORD Imagesize = ((EPD_3IN7_WIDTH % 4 == 0)? (EPD_3IN7_WIDTH / 4 ): (EPD_3IN7_WIDTH / 4 + 1)) * EPD_3IN7_HEIGHT;
    // if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    //     printf("Failed to apply for black memory...\r\n");
    //     while(1);
    // }

    // printf("Paint_NewImage\r\n");
    // Paint_NewImage(BlackImage, EPD_3IN7_WIDTH, EPD_3IN7_HEIGHT, 0, WHITE);
    // Paint_SetScale(4);
    // Paint_Clear(WHITE);
    

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
    // EPD_3IN7_4Gray_Display(BlackImage);
    // DEV_Delay_ms(4000);
}


// 



void loop() {
  Serial.println("Current time: " + rtc.getDateTime());
  delay(5000);
}

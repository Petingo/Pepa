#include "GUI.h"

namespace pepa
{

void Block::clear() {
    Paint_ClearWindows(xStart, yStart, xEnd, yEnd, bgColor);
}

FixedTextBlock::FixedTextBlock(uint16_t xStart, uint16_t yStart,
                               sFONT font, uint16_t textLength,
                               uint16_t textColor, uint16_t bgColor,
                               char* text):
        Block(xStart, yStart, xStart + font.Width * textLength, yStart + font.Height, bgColor),
        font(font), textLength(textLength), textColor(textColor) {
    if(text != nullptr) {
        this->text = text;
    } else {
        this->text = (char *) malloc(textLength + 1);
        memset(this->text, 0, textLength + 1);
    }
}

FixedTextBlock::~FixedTextBlock() {
    if(text != nullptr) {
        free(text);
    }
}

void FixedTextBlock::draw() {
    clear();
    Paint_DrawString_EN(xStart, yStart, text, &font, textColor, bgColor);
}

GUI::GUI() {
    m_displaySize = ((EPD_3IN7_WIDTH % 4 == 0) ? (EPD_3IN7_WIDTH / 4) : (EPD_3IN7_WIDTH / 4 + 1)) * EPD_3IN7_HEIGHT;
    if ((m_displayBuffer = (uint8_t *) malloc (m_displaySize)) == NULL) {
        Serial.println("Failed to apply for black memory...\r\n");
    }
}

GUI::~GUI() {
    free(m_displayBuffer);
}

void GUI::init()
{
    Serial.println("Init E-paper...");
    EPD_3IN7_4Gray_Init();
    EPD_3IN7_4Gray_Clear();
    DEV_Delay_ms(500);

    Paint_NewImage(m_displayBuffer, EPD_3IN7_WIDTH, EPD_3IN7_HEIGHT, 270, WHITE);
    Paint_SelectImage(m_displayBuffer);
    Paint_SetScale(4);
    Paint_Clear(WHITE);

    EPD_3IN7_1Gray_Init();       //init 1 Gray mode
    EPD_3IN7_1Gray_Clear();
    Paint_SelectImage(m_displayBuffer);
    Paint_SetScale(2);
}

void GUI::draw() {
    Serial.println("GUI::draw");

//    Paint_Clear(WHITE);

    timeBlock.draw();
//    Paint_ClearWindows(10, 10, 95, 34, WHITE);
//    Paint_DrawString_EN(10, 10, "Test2", &Font24, BLACK, WHITE);

    EPD_3IN7_1Gray_Display(m_displayBuffer);
}

}
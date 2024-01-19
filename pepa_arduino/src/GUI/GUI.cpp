#include "GUI.h"

namespace pepa
{
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

        char bus24LabelString[3] = "24";
        bus24LabelBlock = FixedTextBlock(18, 50, Font20, 2, WHITE, BLACK, bus24LabelString);
        bus24TimeBlock = FixedTextBlock(54, 50, Font20, 5, BLACK, WHITE);
        bus24LabelBlock.setMargin(4, 10, 0, 10);
        bus24LabelBlock.draw();

        char bus2LabelString[2] = "2";
        bus2LabelBlock = FixedTextBlock(25, 80, Font20, 1, WHITE, BLACK, bus2LabelString);
        bus2TimeBlock = FixedTextBlock(54, 80, Font20, 5, BLACK, WHITE);
        bus2LabelBlock.setMargin(4, 17, 0, 17);
        bus2LabelBlock.draw();

        char bus1LabelString[2] = "1";
        bus1LabelBlock = FixedTextBlock(25, 110, Font20, 1, WHITE, BLACK, bus1LabelString);
        bus1TimeBlock = FixedTextBlock(54, 110, Font20, 5, BLACK, WHITE);
        bus1LabelBlock.setMargin(4, 17, 0, 17);
        bus1LabelBlock.draw();

        char bus25WLabelString[4] = "25<";
        bus25WLabelBlock = FixedTextBlock(11, 140, Font20, 3, WHITE, BLACK, bus25WLabelString);
        bus25WTimeBlock = FixedTextBlock(54, 140, Font20, 5, BLACK, WHITE);
        bus25WLabelBlock.setMargin(4, 3, 0, 3);
        bus25WLabelBlock.draw();

        char bus25ELabelString[4] = "25>";
        bus25ELabelBlock = FixedTextBlock(11, 170, Font20, 3, WHITE, BLACK, bus25ELabelString);
        bus25ETimeBlock = FixedTextBlock(54, 170, Font20, 5, BLACK, WHITE);
        bus25ELabelBlock.setMargin(4, 3, 0, 3);
        bus25ELabelBlock.draw();

        EPD_3IN7_1Gray_Display(m_displayBuffer);
    }

    void GUI::draw() {
        timeBlock.draw();
        bus24TimeBlock.draw();
        bus1TimeBlock.draw();

        EPD_3IN7_1Gray_Display(m_displayBuffer);
    }

}
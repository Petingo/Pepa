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
    // init the fixed elements
    EPD_3IN7_4Gray_Init();
    EPD_3IN7_4Gray_Clear();

    Paint_NewImage(m_displayBuffer, EPD_3IN7_WIDTH, EPD_3IN7_HEIGHT, 270, WHITE);
    Paint_SelectImage(m_displayBuffer);
    Paint_SetScale(4);
    Paint_Clear(WHITE);

    char tempMoistString[] = "25C 34%";
    tempMoistBlock.setText(tempMoistString);
    tempMoistBlock.draw();

    char bus24LabelString[] = "24";
    bus24LabelBlock = FixedTextBlock(18, 90, Font20, 2, WHITE, GRAY4, bus24LabelString);
    bus24TimeBlock = FixedTextBlock(64, 90, Font20, 5, BLACK, WHITE);
    bus24LabelBlock.setMargin(4, 10, 0, 10);
    bus24LabelBlock.draw();

    char bus2LabelString[] = "2";
    bus2LabelBlock = FixedTextBlock(25, 120, Font20, 1, WHITE, GRAY4, bus2LabelString);
    bus2TimeBlock = FixedTextBlock(64, 120, Font20, 5, BLACK, WHITE);
    bus2LabelBlock.setMargin(4, 17, 0, 17);
    bus2LabelBlock.draw();

    char bus1LabelString[] = "1";
    bus1LabelBlock = FixedTextBlock(25, 150, Font20, 1, WHITE, GRAY4, bus1LabelString);
    bus1TimeBlock = FixedTextBlock(64, 150, Font20, 5, BLACK, WHITE);
    bus1LabelBlock.setMargin(4, 17, 0, 17);
    bus1LabelBlock.draw();

    char bus25WLabelString[] = "25<";
    bus25WLabelBlock = FixedTextBlock(11, 180, Font20, 3, WHITE, GRAY4, bus25WLabelString);
    bus25WTimeBlock = FixedTextBlock(64, 180, Font20, 5, BLACK, WHITE);
    bus25WLabelBlock.setMargin(4, 3, 0, 3);
    bus25WLabelBlock.draw();

    char bus25ELabelString[] = "25>";
    bus25ELabelBlock = FixedTextBlock(11, 210, Font20, 3, WHITE, GRAY4, bus25ELabelString);
    bus25ETimeBlock = FixedTextBlock(64, 210, Font20, 5, BLACK, WHITE);
    bus25ELabelBlock.setMargin(4, 3, 0, 3);
    bus25ELabelBlock.draw();

    EPD_3IN7_4Gray_Display(m_displayBuffer);
    DEV_Delay_ms(500);

    // init for partial update, which support only black & white
    EPD_3IN7_1Gray_Init();
    EPD_3IN7_1Gray_Clear();
    Paint_SelectImage(m_displayBuffer);
    Paint_SetScale(2);
}

void GUI::draw() {
    timeBlock.draw();
    bus24TimeBlock.draw();
    bus2TimeBlock.draw();
    bus1TimeBlock.draw();
    bus25WTimeBlock.draw();
    bus25ETimeBlock.draw();

    EPD_3IN7_1Gray_Display(m_displayBuffer);
}

}
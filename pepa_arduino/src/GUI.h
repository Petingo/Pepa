#ifndef PEPA_GUI_H
#define PEPA_GUI_H

#include "eink/EPD.h"
#include "eink/fonts.h"
#include "eink/GUI_Paint.h"

namespace pepa
{

class Block {
public:
    Block() = default;
    Block(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd, uint16_t bgColor) :
        xStart(xStart), yStart(yStart), xEnd(xEnd), yEnd(yEnd), bgColor(bgColor) {}

    void clear();

public:
    uint16_t xStart = 0;
    uint16_t yStart = 0;
    uint16_t xEnd = 0;
    uint16_t yEnd = 0;
    uint16_t bgColor = WHITE;

};

class FixedTextBlock : public Block {
public:
    FixedTextBlock() = default;
    FixedTextBlock(uint16_t xStart, uint16_t yStart,
                   sFONT font, uint16_t textLength,
                   uint16_t textColor, uint16_t bgColor,
                   char* text = nullptr);
    ~FixedTextBlock();

    void setText(char* text) { strncpy(this->text, text, textLength); }
    void draw();

public:
    sFONT font;
    uint16_t textLength;
    uint16_t textColor;
    char* text;
};

class GUI {
public:
    GUI();
    ~GUI();

    FixedTextBlock timeBlock = FixedTextBlock(10, 10, Font24, 5, BLACK, WHITE);

    void init();
    void draw();

private:
    uint8_t *m_displayBuffer;
    uint16_t m_displaySize;
};

}


#endif
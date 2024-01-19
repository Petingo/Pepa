#include "FixedTextBlock.h"

namespace pepa {

    FixedTextBlock::FixedTextBlock(uint16_t xStart, uint16_t yStart,
                                   sFONT font, uint16_t textLength,
                                   uint16_t textColor, uint16_t bgColor,
                                   char text[]):
            Block(xStart, yStart, xStart + font.Width * textLength, yStart + font.Height, bgColor),
            font(font), textLength(textLength), textColor(textColor) {

        this->text = (char *) malloc(textLength + 1);
        memset(this->text, 0, textLength + 1);

        if(text != nullptr){
            strncpy(this->text, text, textLength);
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

    FixedTextBlock& FixedTextBlock::operator=(const FixedTextBlock& other){
        if(this != &other) {
            Block::operator=(other);
            font = other.font;
            textLength = other.textLength;
            textColor = other.textColor;

            if(text != nullptr) {
                free(text);
            }
            text = (char *) malloc(textLength + 1);
            memset(text, 0, textLength + 1);
            strncpy(text, other.text, textLength);
        }
        return *this;
    }

} // pepa
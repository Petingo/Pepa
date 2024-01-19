#ifndef PEPA_FIXEDTEXTBLOCK_H
#define PEPA_FIXEDTEXTBLOCK_H

#include "Block.h"

namespace pepa {

    class FixedTextBlock : public Block {
    public:
        FixedTextBlock() = default;
        FixedTextBlock(uint16_t xStart, uint16_t yStart,
                       sFONT font, uint16_t textLength,
                       uint16_t textColor, uint16_t bgColor,
                       char text[] = nullptr);
        ~FixedTextBlock();

        void setText(char text[]) {
            strncpy(this->text, text, textLength);
        }
        virtual void draw() override;

        FixedTextBlock& operator=(const FixedTextBlock& other);

    public:
        sFONT font;
        uint16_t textLength;
        uint16_t textColor;
        char* text = nullptr;
    };

} // pepa

#endif //PEPA_FIXEDTEXTBLOCK_H

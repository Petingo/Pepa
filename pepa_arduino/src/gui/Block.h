#ifndef PEPA_BLOCK_H
#define PEPA_BLOCK_H

#include <stdint.h>

#include "../eink/fonts.h"
#include "../eink/GUI_Paint.h"

namespace pepa {

    class Block {
    public:
        Block() = default;
        Block(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd, uint16_t bgColor) :
                xStart(xStart), yStart(yStart), xEnd(xEnd), yEnd(yEnd), bgColor(bgColor) {}

        virtual void draw();

        void clear();
        void setMargin(uint16_t top, uint16_t right, uint16_t bottom, uint16_t left);

    public:
        uint16_t xStart = 0;
        uint16_t yStart = 0;
        uint16_t xEnd = 0;
        uint16_t yEnd = 0;
        uint16_t bgColor = WHITE;
        uint16_t margin[4];

    };

} // pepa

#endif //PEPA_BLOCK_H

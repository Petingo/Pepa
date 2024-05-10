#ifndef PEPA_BLOCK_H
#define PEPA_BLOCK_H

#include <stdint.h>

#include "../3rdparty/eink/fonts.h"
#include "../3rdparty/eink/GUI_Paint.h"

namespace pepa {

/**
 * @brief: The base class for all the elements to be drawn on the screen, which defines
 *         the boundary & backgroud of the element
 */
class Block {
public:
    Block() = default;
    Block(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd, uint16_t bgColor) :
            xStart(xStart), yStart(yStart), xEnd(xEnd), yEnd(yEnd), bgColor(bgColor) {}

    /**
     * @brief: Redraw the element on the screen
     */
    virtual void draw();

    /**
     * @brief: Clear the area of the element on the screen
     */
    void clear();

    /**
     * @brief: Set the margin of the element
     * 
     * @param: top, top margin pixel
     * @param: right, right margin pixel
     * @param: bottom, bottom margin pixel
     * @param: left, left margin pixel
     */
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

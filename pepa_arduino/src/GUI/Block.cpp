//
// Created by Petingo on 2024/1/18.
//

#include "Block.h"

namespace pepa {

    void Block::clear() {
        Paint_ClearWindows(xStart - margin[3],
                           yStart - margin[0],
                           xEnd + margin[1],
                           yEnd + margin[2], bgColor);
    }

    void Block::setMargin(uint16_t top, uint16_t right, uint16_t bottom, uint16_t left) {
        margin[0] = top;
        margin[1] = right;
        margin[2] = bottom;
        margin[3] = left;
    }

} // pepa
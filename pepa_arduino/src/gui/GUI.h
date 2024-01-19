#ifndef PEPA_GUI_H
#define PEPA_GUI_H

#include "Block.h"
#include "FixedTextBlock.h"
#include "../eink/EPD.h"
#include "../eink/fonts.h"
#include "../eink/GUI_Paint.h"

namespace pepa
{
    class GUI {
    public:
        GUI();
        ~GUI();

        FixedTextBlock timeBlock = FixedTextBlock(10, 12, Font24, 5, BLACK, WHITE);
        FixedTextBlock tempMoistBlock = FixedTextBlock(10, 40, Font20, 7, GRAY3, WHITE);

        FixedTextBlock bus24LabelBlock;
        FixedTextBlock bus24TimeBlock;

        FixedTextBlock bus2LabelBlock;
        FixedTextBlock bus2TimeBlock;

        FixedTextBlock bus1LabelBlock;
        FixedTextBlock bus1TimeBlock;

        FixedTextBlock bus25WLabelBlock;
        FixedTextBlock bus25WTimeBlock;

        FixedTextBlock bus25ELabelBlock;
        FixedTextBlock bus25ETimeBlock;

        void init();
        void draw();

    private:
        uint8_t *m_displayBuffer;
        uint16_t m_displaySize;
    };

}


#endif
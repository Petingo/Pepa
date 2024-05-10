#ifndef PEPA_GUI_H
#define PEPA_GUI_H

#include "Block.h"
#include "FixedTextBlock.h"
#include "../3rdparty/eink/EPD.h"
#include "../3rdparty/eink/fonts.h"
#include "../3rdparty/eink/GUI_Paint.h"

namespace pepa
{

    /**
     * @brief: The GUI class that contains all the elements to be drawn on the screen
     */
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

        /**
         * @brief: Initialize the GUI, creating all the instances of the elements
         */
        void init();

        /**
         * @brief: Redraw all the elements on the screen
         */
        void draw();

    private:
        uint8_t *m_displayBuffer;
        uint16_t m_displaySize;
    };

}


#endif
#ifndef APP_H
#define APP_H

#include <stdint.h>

#include "lib/DEV_Config.h"
#include "lib/EPD.h"
#include "lib/GUI_Paint.h"
#include "CustomPaint.h"

class App
{
public:
    App();
    ~App() = default;
    void init();
    void displayTest1();
    void displayTest2();

private:
    uint8_t *m_displayBuffer;
    uint16_t m_displaySize;
};

#endif
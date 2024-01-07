#ifndef APP_H
#define APP_H

#include <stdint.h>

#include "EInk/DEV_Config.h"
#include "EInk/EPD.h"
#include "EInk/GUI_Paint.h"
#include "CustomPaint.h"

namespace pepa
{   
class App
{
public:
    App();
    ~App() = default;
    void init();
    void displayTest1();
    void displayTest2();
    
    void getNextDepartureTime();

private:
    uint8_t *m_displayBuffer;
    uint16_t m_displaySize;
};

} // namespace pepa

#endif
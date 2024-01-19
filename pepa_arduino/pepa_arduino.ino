#include "src/App.h"

pepa::App app = pepa::App();

void setup() {
    app.init();
}

void loop() {
     app.loopUpdate();
    //  EPD_3IN7_Sleep();
     delay(5000);
}

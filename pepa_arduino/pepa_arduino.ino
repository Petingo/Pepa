#include "src/App.h"

pepa::App app = pepa::App();

void setup() {
    app.init();
}

void loop() {
    app.loopUpdate();
    delay(5000);
}

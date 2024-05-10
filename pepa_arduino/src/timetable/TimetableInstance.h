#ifndef TIMETABLE_INSTANCE_H
#define TIMETABLE_INSTANCE_H

#include "Timetable.h"

namespace pepa
{

// Timetable instances
// For each bus line, there should be a timetable instance, e.g. s_bus24, with an init function, e.g. initBus24()
// The corresponding init function should be called in initAllTimetables()

extern Timetable s_bus24;
void initBus24();

void initAllTimetables();

}

#endif
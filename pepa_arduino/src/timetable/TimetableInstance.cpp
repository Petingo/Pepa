#include "Timetable.h"
#include "TimetableInstance.h"

namespace pepa
{

Timetable s_bus24;

void initAllTimetables(){
    initBus24();
}

void initBus24(){
    int tableWeekday[24][10] = {
        {11, -1}, // 0
        {-1},     // 1
        {-1},     // 2
        {-1},     // 3
        {-1},     // 4
        {-1},     // 5
        {22, 31, 43, 56, -1}, // 6
        {11, 25, 40, 55, -1}, // 7
        {10, 25, 40, 55, -1}, // 8
        {10, 24, 39, 54, -1}, // 9
        {-1},  // 10
        {-1},  // 11
        {-1},  // 12
        {-1},  // 13
        {-1},  // 14
        {-1},  // 15
        {-1},  // 16
        {-1},  // 17
        {-1},  // 18
        {-1},  // 19
        {-1},  // 20
        {-1},  // 21
        {-1},  // 22
        {-1}   // 23
    };

    memcpy(s_bus24.tableWeekday, tableWeekday, sizeof(tableWeekday));
}


} // namespace pepa
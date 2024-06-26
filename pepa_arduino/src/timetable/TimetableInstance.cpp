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
        {4, 11, -1}, // 0
        {-1},     // 1
        {-1},     // 2
        {-1},     // 3
        {-1},     // 4
        {-1},     // 5
        {22, 31, 43, 56, -1}, // 6
        {11, 25, 40, 55, -1}, // 7
        {10, 25, 40, 55, -1}, // 8
        {10, 24, 39, 54, -1}, // 9
        { 9, 23, 37, 50, -1},  // 10
        { 6, 21, 34, 51, -1},  // 11
        { 6, 20, 36, 51, -1},  // 12
        { 4, 21, 36, 50, -1},  // 13
        { 6, 21, 35, 51, -1},  // 14
        { 6, 20, 35, 50, -1},  // 15
        { 5, 18, 29, 42, 56, -1},  // 16
        { 4, 19, 34, 49, -1},  // 17
        { 4, 19, 35, 50, -1},  // 18
        { 5, 19, 35, 50, -1},  // 19
        { 5, 20, 34, 50, -1},  // 20
        { 5, 18, 35, 50, -1},  // 21
        { 5, 20, 35, 50, -1},  // 22
        { 5, 21, 36, 51, -1}   // 23
    };

    memcpy(s_bus24.tableWeekday, tableWeekday, sizeof(tableWeekday));
}


} // namespace pepa
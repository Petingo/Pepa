#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "3rdparty/ESP32Time/ESP32Time.h"

namespace pepa
{

class Timetable
{
public:
    Timetable() = default;
    ~Timetable() = default;

    void getNextDepartureTime(
        int currentDayOfWeek, int currentHour, int currentMin, bool isHoliday,
        int& outHour, int& outMinute);

    int tableWeekday[24][10];
    int tableSaturday[24][10];
    int tableSunday[24][10];

private:
    bool m_getFirstDepartureOfTheDay(int dayOfWeek, int& hour, int& minute);
    int (*m_getTableOfTheDay(int dayOfWeek))[10];
};  

} // namespace pepa
#endif
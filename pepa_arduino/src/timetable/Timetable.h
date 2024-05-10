#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "../3rdparty/ESP32Time/ESP32Time.h"

namespace pepa
{

class Timetable
{
public:
    Timetable() = default;
    ~Timetable() = default;

    /**
     * @brief: Get the next departure time of the bus
     */
    void getNextDepartureTime(
        int currentDayOfWeek, int currentHour, int currentMin, bool isHoliday,
        int& outHour, int& outMinute);

    // There're up to 9 departure times in an hour, the last element should be filled with -1
    int tableWeekday[24][10];
    int tableSaturday[24][10];
    int tableSunday[24][10];

private:
    /**
     * @brief: Get the first departure time of the day
     */
    bool m_getFirstDepartureOfTheDay(int dayOfWeek, int& hour, int& minute);

    /**
     * @brief: Get the timetable of the day
     */
    int (*m_getTableOfTheDay(int dayOfWeek))[10];
};  

} // namespace pepa
#endif
#include "Timetable.h"

namespace pepa
{
int (*Timetable::m_getTableOfTheDay(int dayOfWeek))[10] {
    // Sunday
    if(dayOfWeek == 6) {
        return tableSunday;
    }
    // Saturday
    else if (dayOfWeek == 5) {
        return tableSaturday;
    }
    // Weekday
    return tableWeekday;
}

bool Timetable::m_getFirstDepartureOfTheDay(int dayOfWeek, int& outHour, int& outMinute)
{
    bool succeed = false;
    dayOfWeek = dayOfWeek % 7;

    int (*targetTable)[10] = m_getTableOfTheDay(dayOfWeek);

    for(int i = 0 ; i < 24 ; i ++){
        if(targetTable[i][0] != -1){
            succeed = true;
            outHour = i;
            outMinute = targetTable[i][0];
            break;
        }
    }

    return succeed;
}

void Timetable::getNextDepartureTime(
    int dayOfWeek, int hour, int minute, bool isHoliday,
    int& outHour, int& outMinute)
{
    if (isHoliday) dayOfWeek = 6;
    int (*targetTable)[10] = m_getTableOfTheDay(dayOfWeek);

    // Find the next departure time
    bool found = false;

    // First check if in the same hour, there's one later than the current minute
    for(int i = 0 ; i < 10 ; i++){
        if(targetTable[hour][i] == -1){
            break;
        }
        if(targetTable[hour][i] > minute){
            found = true;
            outHour = hour;
            outMinute = targetTable[hour][i];
            break;
        }
    }
    if(found) return;
    
    // Starting from the next hour, find the first departure time
    for(int i = hour + 1 ; i < 24 ; i ++){
        if(targetTable[i][0] == -1) continue;

        found = true;
        outHour = i;
        outMinute = targetTable[i][0];
        break;
    }
    if(found) return;

    // No more departure time today, find the first departure time of the next day
    m_getFirstDepartureOfTheDay((dayOfWeek + 1) % 7, outHour, outMinute);
}

}

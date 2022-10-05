#include "date.h"

Date::Date(int y, int m, int d):
    year(y),
    month(m),
    day(d)
{
}

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

bool Date::operator <(const Date &d) const
{
    if (year<d.year)
        return true;
    else if (year==d.year && month<d.month)
        return true;
    else if (year==d.year && month==d.month && day<d.day)
        return true;
    return false;
}

#ifndef DATE_H
#define DATE_H


class date
{
    int year;
    int month;
    int day;
public:
    date(int y, int m, int d):year(y), month(m),day(d){}
    int getYear() const;
    int getMonth() const;
    int getDay() const;
};

#endif // DATE_H

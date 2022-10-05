#ifndef DATE_H
#define DATE_H


class Date
{
    int year, month, day;
public:
    Date(int y, int m, int d);
    int getYear() const;
    int getMonth() const;
    int getDay() const;

	// Kell, mert egy map-hez használjuk kulcsként
    bool operator <(const Date &d) const;
};

#endif // DATE_H

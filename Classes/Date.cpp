#include "Date.h"

using namespace std;

Date::Date(string date) : s_date(date) {
    int count = 0;
    while (count != 6) {
        int index;
        string s;
        for (int i = 0; i < date.length(); i++) {
            if (date[i] == '/' || date[i] == ':') {
                s = date.substr(0,i);
                date.erase(0,i+1);
                break;
            }
            else if (date[i] == ' ') {
                s = date.substr(0,i);
                date.erase(0,i+1);
                break;
            }
            if (i == date.length()-1)
                s = date;
        }
        switch (count) {
            case 0:
                day = stoi(s, nullptr);
                count++;
                break;
            case 1:
                month = stoi(s, nullptr);
                count++;
                break;
            case 2:
                year = stoi(s, nullptr);
                count++;
                break;
            case 3:
                hour = stoi(s, nullptr);
                count++;
                break;
            case 4:
                minute = stoi(s, nullptr);
                count++;
                break;
            case 5:
                second = stoi(s, nullptr);
                count++;
                break;
        }
    }
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    hour = 0;
    minute = 0;
    second = 0;
}

int Date::getYear() const {return year;}

int Date::getMonth() const {return month;}

int Date::getDay() const {return day;}

int Date::getHour() const {return hour;}

int Date::getMinute() const {return minute;}

int Date::getSecond() const {return second;}

string Date::getInfo() const {return s_date;}

bool Date::operator==(Date d1) const {
    return year == d1.getYear() && month == d1.getMonth() && day == d1.getDay() && hour == d1.hour && minute == d1.minute && second == d1.second;
}

bool Date::operator>(Date d1) const {
    if (year > d1.getYear())
        return true;
    else if (year == d1.getYear()) {
        if (month > d1.getMonth())
            return true;
        else if (month == d1.getMonth()) {
            if (day > d1.getDay())
                return true;
            else if (day == d1.getDay()){
                if (hour > d1.getHour())
                    return true;
                else if (hour == d1.getHour()) {
                    if (minute > d1.getMinute()) {
                        return true;
                    }
                    else if (minute == d1.getMinute())
                        if (second >= d1.getSecond())
                            return true;
                }
            }
        }
    }
    return false;
}

bool Date::operator<(Date d1) const {
    if (year < d1.getYear())
        return true;
    else if (year == d1.getYear() && month < d1.getMonth())
        return true;
    else if (year == d1.getYear() && month == d1.getMonth() && day < d1.getDay())
        return true;
    else if (year == d1.getYear() && month == d1.getMonth() && day == d1.getDay() && hour < d1.getHour())
        return true;
    else if (year == d1.getYear() && month == d1.getMonth() && day == d1.getDay() && hour == d1.getHour() && minute < d1.getMinute())
        return true;
    else if (year == d1.getYear() && month == d1.getMonth() && day == d1.getDay() && hour == d1.getHour() && minute == d1.getMinute() && second < d1.getSecond())
        return true;
    return false;
}

bool Date::dayEqual(Date d1) const {
    return year == d1.getYear() && month == d1.getMonth() && day == d1.getDay();
}

int Date::operator-(const Date &d1) {
    int min1 = (d1.getYear()-1)*365*1440 + (d1.getMonth()-1)*30.4375*1440 + (d1.getDay()-1)*1440 + (d1.getHour()-1)*60 + d1.getMinute();
    int min = (year-1)*365*1440 + (month-1)*30.4375*1440 + (day-1)*1440 + (hour-1)*60 + minute;
    return min - min1;
}
#ifndef AEDA2020_PORTAGENS_DATE_H
#define AEDA2020_PORTAGENS_DATE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * The Date class is a class that provides a date that can
 * be used and/or compared to other dates
 *
 * When initialized, the user inputs a string in the format
 * "day/month/year hour:minute:second" that is then converted to
 * corresponding variables that will be used later on.
 *
 * @param s_date corresponds to the string inputted by the user when they initialize
 * the Date class and is in the format referred above
 */
class Date {
    string s_date;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    /**
     * @brief Constructor of date class, initializes date to be equal to the string provided
     * @param date string that provides the date in the following format: "day/month/year hour:minute:second"
     */
    Date(string date);

    Date(int year, int month, int day);

    /**
     * @return 'year' attribute
     */
    int getYear() const;

    /**
     * @return 'month' attribute
     */
    int getMonth() const;

    /**
     * @return 'day' attribute
     */
    int getDay() const;

    /**
     * @return 'hour' attribute
     */
    int getHour() const;

    /**
     * @return 'minute' attribute
     */
    int getMinute() const;

    /**
     * @return 'second' attribute
     */
    int getSecond() const;

    /**
     * @return current info - \n
     * info is the string provided when one initializes the constructor \n
     * info has the following format: "day/month/year hour:minute:second"
     */
    string getInfo() const;

    /**
     * @brief Overloads the '==' operator to be able to know if two different dates are the same
     * @param d1 Object of class Date to compare the current object to
     * @return true if the year, month, day, hour, minute, second are the same on both objects, false otherwise
     */
    bool operator==(Date d1) const;

    /**
     * @brief overloads the '>' operator to be able to know if one date is after the other
     * @param d1 Object of class Date to compare the current object to
     * @return true if current date is after the date of object d1, false otherwise
     */
    bool operator>(Date d1) const;

    bool operator<(Date d1) const;  // only used with the BST!!!
                                    // just compare year, month and day !!
    bool dayEqual(Date d1) const;      // only used with BST!!!
                                    // just compare year, month and day !!
    int operator-(Date const& d1);
};


#endif //AEDA2020_PORTAGENS_DATE_H

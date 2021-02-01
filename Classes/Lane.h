
#ifndef AEDA2020_PORTAGENS_LANE_H
#define AEDA2020_PORTAGENS_LANE_H

#include "Employee.h"
#include "Utils.h"
#include <string>
#include <sqlite3.h>

extern sqlite3* db;
extern sqlite3_stmt* stmt;

using namespace std;

/**
 * The class Lane is a class that has information about each lane
 *
 * Each Lane has a unique number, 'lane_number', that identifies it, and can be
 * a green lane ('green_lane' attribute)
 */
class Lane {
protected:
    int lane_number;
    bool green_lane;
public:
    /**
     * Initializes a new Lane object with the input provided by the user
     * @param lane_number sets 'lane_number'
     * @param green_lane sets 'green_lane'
     */
    Lane(int lane_number, bool green_lane);

    /**
     * Default constructor. \n
     * Initializes a Lane object with 'lane_number' attribute set to 0, and the object isn't a green lane
     */
    Lane();

    /**
     * @return current 'lane_number'
     */
    int getLaneNumber() const;

    /**
     * @return current 'green_lane'
     */
    bool getGreenLane() const;

    /**
     * @return current
     */
    virtual Employee * getEmployee() const;

    /**
     * @return string with info in the following format:
     * 'lane_number' + " - " + 'green_lane'
     */
    virtual string getInfo() const;

    /**
     * @return string with info in the following format:
     * "Lane Number: " + 'lane_number' + " - Greenlane: " + 'green_lane';
     */
    virtual string showLane() const;

    /**
     * @param new_lane_number sets 'lane_number'
     */
    void setLaneNumber(int new_lane_number);

    /**
     * @param e
     */
    virtual void setEmployee(Employee* e) {};

    /**
     * @brief Overloads the '==' operator to be able to know if two different Lane objects are the same
     * @param l2 is the object of class Lane to compare the current object to
     * @return true if both Lane objects have the same 'lane_number' and 'green_lane', false otherwise
     */
    bool operator==(const Lane &l2) const;
};



/**
 * The class LaneEmployee is a class derived publicly from Lane class.
 * It has information about each lane's employee.
 *
 * Every lane has a Employee assigned to it.
 * LaneEmployee is an Employee which has a lane assigned, 'lane_number',
 * and can be in a green lane or not ('green_lane')
 *
 * @param employee is the Employee assigned to the corresponding Lane.
 */
class LaneEmployee : public Lane {
    Employee* employee;
public:
    /**
     * Initializes 'lane_number', 'green_lane' and 'employee' attributes
     * as the values inputted by the user when the constructor is called
     * @param lane_number sets 'lane_number'
     * @param green_lane sets 'green_lane'
     * @param e sets 'employee'
     */
    LaneEmployee(int lane_number, bool green_lane, Employee* e);

    /**
     * @param e sets 'employee'
     */
    void setEmployee(Employee* e);

    /**
     * @return current Employee
     */
    Employee * getEmployee() const;

    /**
     * @return string with info in the following format:
     * 'lane_number' + " - " + 'green_lane' + " - " + "Employee Name: " + 'name' + " - " + "Employee Code: " +  'code'
     */
    string getInfo() const;

    /**
     * @return string with info in the following format:
     * "Lane Number: " + 'lane_number' + " - Greenlane: " + 'green_lane' + " - " + "Employee Name: " + 'name' + " - " + "Employee Code: " +  'code';
     */
    string showLane() const;
};


#endif //AEDA2020_PORTAGENS_LANE_H

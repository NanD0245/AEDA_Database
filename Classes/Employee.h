#ifndef AEDA2020_PORTAGENS_EMPLOYEE_H
#define AEDA2020_PORTAGENS_EMPLOYEE_H

#include <string>

using namespace std;

/**
 * The class Employee is a class that has basic information about a worker
 *
 * Each Employee has a name and a code, which are used to identify them
 * 
 */
class Employee {
    string name;
    int code;
public:

    /**
     * @brief Constructor of Employee class
     * @param name is a string that will be the 'name' variable that belongs to the class \n
     * name can't be an empty string and is different from every other Employee
     * @param code is an integer that will be the 'code' variable that belongs to the class \n
     * code is a unique number that identifies each Employee
     */
    Employee(string name, int code);

    /**
     * @return 'name' attribute
     */
    string getName() const;

    /**
     * @return 'code' attribute
     */
    int getCode() const;

    /**
     * @return string with the format: 'name' + " - " + 'code'
     */
    string getInfo();

    /**
     * @return string with the format: "Employee Name: " + 'name' + " - " + "Employee Code: " +  'code'
     */
    string showEmployee();

    /**
     * @param new_name sets 'name' attribute (can't be an empty string nor equal to any other name)
     */
    void setName(const string new_name);
};


#endif //AEDA2020_PORTAGENS_EMPLOYEE_H

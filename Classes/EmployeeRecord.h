#ifndef AEDA2020_PORTAGENS_EMPLOYEES_H
#define AEDA2020_PORTAGENS_EMPLOYEES_H

#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * Employees class is a class that aggregates different workers.
 *
 * Each worker's information is stored in their corresponding Employee object,
 * which is then processed in the vector 'employees' using Employees' methods.
 *
 * @param employees contains all the different workers (objects from Employee class)
 * @param code is a number that changes whenever a new worker(Employee object) is added to the vector,
 * so each Employee has a unique code that identifies them
 */
class EmployeeRecord {
    vector<Employee *> employees;
    static int code;
public:
    /**
     * The constructor of Employees class initializes the 'employees' container as empty
     */
    EmployeeRecord();

    /**
     * @return 'code' attribute
     */
    int getCode() const;

    /**
     * @param code sets 'code' attribute
     */
    void setCode(int code);

    /**
     * @return the number of employees already in the 'employees' container
     */
    int getNumEmployees() const;

    /**
     * Finds and provides Employee object according to its code
     * @param code is a unique number that identifies the Employee object
     * @return the Employee object that has the code 'code' if it exists, nullptr otherwise
     */
    Employee * getEmployee(int code);

    /**
     * Finds and provides Employee object according to its name
     * @param name is a unique string that identifies the Employee object
     * @return the Employee object that has the name 'name' if it exists, nullptr otherwise
     */
    Employee * getEmployee(string name);

    /**
     * Finds and provides Employee object according to its index
     * @param i is the index , in the vector 'employee', of the worker (Employee object)
     * @return the Employee object that has the index 'i' if it exists, nullptr otherwise
     */
    Employee * getEmployeeIndex(int i);

    /**
     * Checks if Employee with the name 'name' exists in the vector 'employees'
     * @param name is the string that a Employee object in 'employees' vector may have
     * @return false if an Employee with name 'name' already exists in the container, true otherwise
     */
    bool checkEmployeeName(string name);

    /**
     * addEmployee function creates and adds a worker (that isn't already in the 'employees' container)
     * to the container 'employees', with the desired name and the corresponding code
     * In this case, the code isn't set by the user, it is automatically assigned
     * @param name is a unique string (no other worker can have the same name)
     * that will be the name of the new Employee object
     * @return false if an Employee object with the same name already exists in the 'employees' vector,
     * true otherwise (it succeeded in adding the object)
     */
    bool addEmployee(string name);

    /**
     * addEmployee function adds a worker (that isn't already in the 'employees' container)
     * to the container 'employees'
     * @param e is an object of Employee class to add to vector 'employees'
     * @return false if an Employee object with the same name already exists in the 'employees' vector,
     * true otherwise (it succeeded in adding the object)
     */
    bool addEmployee(Employee * e);

    /**
     * removeEmployee function removes a worker making use of its index in the
     * vector 'employee'
     * @param i is the index, in the vector 'employee', of the worker to remove from the container
     * @return false if the Employee object that has the index 'i' exists and is removed, nullptr otherwise
     */
    bool removeEmployee(int i);
};



#endif //AEDA2020_PORTAGENS_EMPLOYEES_H

#include "EmployeeRecord.h"

using namespace std;

int EmployeeRecord::code = 0;

EmployeeRecord::EmployeeRecord() {
    employees.clear();
}

int EmployeeRecord::getCode() const {return code;}

void EmployeeRecord::setCode(int code) {this->code = code;}

int EmployeeRecord::getNumEmployees() const {return employees.size();}

Employee * EmployeeRecord::getEmployee(int code) {
    for (size_t i=0 ; i < employees.size(); i++) {
        if (employees[i]->getCode() == code)
            return employees[i];
    }
    return nullptr;
}

Employee * EmployeeRecord::getEmployee(string name) {
    for (size_t i=0 ; i < employees.size(); i++) {
        if (employees[i]->getName() == name)
            return employees[i];
    }
    return nullptr;
}

Employee * EmployeeRecord::getEmployeeIndex(int i) {
    if (i < employees.size())
        return employees[i];
    return nullptr;
}

bool EmployeeRecord::checkEmployeeName(string name) {
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i]->getName() == name)
            return false;
    }
    return true;
}

bool EmployeeRecord::addEmployee(string name) {
    for (size_t i = 0; i < employees.size(); i++)
        if (employees[i]->getName() == name)
            return false;
    auto *e1 = new Employee(name, code);
    employees.push_back(e1);
    code++;
    return true;
}

bool EmployeeRecord::addEmployee(Employee * e){
    for (size_t i = 0; i < employees.size(); i++)
        if (employees[i]->getName() == e->getName())
            return false;
    employees.push_back(e);
    return true;
}

bool EmployeeRecord::removeEmployee(int i) {
    if (i>=employees.size())
        return false;
    employees.erase(employees.begin()+i);
    return true;
}

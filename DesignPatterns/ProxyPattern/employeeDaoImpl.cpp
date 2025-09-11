#include <iostream>
#include "header/employeeDapImpl.h"

using namespace std;

EmployeeDaoImpl:: EmployeeDaoImpl(int id, string name, string department, double salary, UserRole role) : id(id), name(name), department(department), salary(salary), role(role) {}

void EmployeeDaoImpl :: getEmployeeInfo() {
    cout << "Employee Info: Name: " << name << ", Department: " << department << endl;
}

void EmployeeDaoImpl :: createEmployeeInfo() {
    cout << "Employee " << name << " has been created in the system." << endl;
}

void EmployeeDaoImpl::updateSalary(double newSalary) {
    this->salary = newSalary;
    cout << "Salary updated to: Rs. " << newSalary << endl;
}

void EmployeeDaoImpl::deleteEmployee() {
    cout << "Employee " << name << " has been deleted from the system." << endl;
}

void EmployeeDaoImpl::displayEmployeeDetails() {
    cout << "Employee Details: Id: " << id
         << ", Name: " << name
         << ", Department: " << department
         << ", Salary: Rs" << salary
         << ", Role: " << static_cast<int>(role) << endl;
}

UserRole EmployeeDaoImpl::getRole() const {
    return role;
}
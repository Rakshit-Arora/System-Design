#include <iostream>
#include "header/employeeDaoProxy.h"
using namespace std;

int main() {
    cout << "===== Proxy Design Pattern (C++) =====" << endl;

    try {
        // Admin demo
        EmployeeDao* admin = new EmployeeDaoProxy(1, "John", "HR", 30000.0, UserRole::ADMIN);
        admin->getEmployeeInfo();
        admin->displayEmployeeDetails();
        admin->createEmployeeInfo();
        admin->updateSalary(40000.0);
        admin->deleteEmployee();
        delete admin;

        // HR demo
        EmployeeDao* hr = new EmployeeDaoProxy(2, "Jane", "HR", 25000.0, UserRole::HR);
        hr->getEmployeeInfo();
        hr->displayEmployeeDetails();
        hr->updateSalary(30000.0);
        delete hr;

        // Manager demo
        EmployeeDao* manager = new EmployeeDaoProxy(3, "Bob", "IT", 20000.0, UserRole::MANAGER);
        manager->getEmployeeInfo();
        manager->displayEmployeeDetails();
        delete manager;

        // Employee demo
        EmployeeDao* employee = new EmployeeDaoProxy(4, "Alice", "IT", 15000.0, UserRole::EMPLOYEE);
        employee->getEmployeeInfo();
        delete employee;

    } catch (const exception& ex) {
        cerr << ex.what() << endl;
    }

    return 0;
}

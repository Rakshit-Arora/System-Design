#pragma once
#include "employeeDao.h"
#include "enum.h"
#include <string>
using namespace std;

class EmployeeDaoImpl : public EmployeeDao {
private:
    int id;
    string name;
    string department;
    double salary;
    UserRole role;

public:
    EmployeeDaoImpl(int id, string name, string department, double salary, UserRole role);

    void getEmployeeInfo() override;
    void createEmployeeInfo() override;
    void deleteEmployee() override;
    void updateSalary(double newSalary)override;
    void displayEmployeeDetails() override;

    UserRole getRole() const;
};
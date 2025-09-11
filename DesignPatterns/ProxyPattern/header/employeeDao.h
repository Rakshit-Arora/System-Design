#pragma once

class EmployeeDao {
public:
    virtual void getEmployeeInfo() = 0;
    virtual void createEmployeeInfo() = 0;
    virtual void deleteEmployee() = 0;
    virtual void updateSalary(double newSalary) = 0;
    virtual void displayEmployeeDetails() = 0;
    virtual ~EmployeeDao() = default;
};
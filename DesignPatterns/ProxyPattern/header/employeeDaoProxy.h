#pragma once
#include "employeeDao.h"
#include <memory>
#include "enum.h"
#include "employeeDapImpl.h"
using namespace std;

class EmployeeDaoProxy : public EmployeeDao {
private:
    std:: unique_ptr<EmployeeDaoImpl> realEmployee;
    bool hasAccessForRole(AccessType accessType, UserRole role);

public:
    EmployeeDaoProxy(int id, std:: string name, std:: string department, double salary, UserRole role);

    void displayEmployeeDetails() override;
    void updateSalary(double newSalary) override;
    void deleteEmployee() override;
    void createEmployeeInfo() override;
    void getEmployeeInfo() override;
};
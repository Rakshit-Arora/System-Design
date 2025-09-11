#include <iostream>
#include <stdexcept>
#include "header/employeeDaoProxy.h"
using namespace std;

EmployeeDaoProxy :: EmployeeDaoProxy(int id, std:: string name, std:: string department, double salary, UserRole role) {
    realEmployee = std:: make_unique<EmployeeDaoImpl> (id, name, department, salary, role);
}

bool EmployeeDaoProxy :: hasAccessForRole(AccessType accessType, UserRole role) {
    switch(accessType) {
        case AccessType::CREATE:
            return role == UserRole::ADMIN;
        case AccessType::DELETE:
            return role == UserRole::ADMIN;
        case AccessType::UPDATE:
            return role == UserRole::ADMIN || role == UserRole::HR;
        case AccessType::VIEW_ALL_DETAILS:
            return role == UserRole::MANAGER || role == UserRole::HR || role == UserRole::ADMIN;
        case AccessType::VIEW_BASIC_INFO:
            return true;
        default:
            return false;
    }
}

void EmployeeDaoProxy::displayEmployeeDetails() {
    if (hasAccessForRole(AccessType::VIEW_ALL_DETAILS, realEmployee->getRole())) {
        realEmployee->displayEmployeeDetails();
    } else {
        throw runtime_error("Access Denied");
    }
}

void EmployeeDaoProxy::updateSalary(double newSalary) {
    if (hasAccessForRole(AccessType::UPDATE, realEmployee->getRole())) {
        realEmployee->updateSalary(newSalary);
    } else {
        throw runtime_error("Access Denied");
    }
}

void EmployeeDaoProxy::deleteEmployee() {
    if (hasAccessForRole(AccessType::DELETE, realEmployee->getRole())) {
        realEmployee->deleteEmployee();
    } else {
        throw runtime_error("Access Denied");
    }
}

void EmployeeDaoProxy::createEmployeeInfo() {
    if (hasAccessForRole(AccessType::CREATE, realEmployee->getRole())) {
        realEmployee->createEmployeeInfo();
    } else {
        throw runtime_error("Access Denied");
    }
}

void EmployeeDaoProxy::getEmployeeInfo() {
    if (hasAccessForRole(AccessType::VIEW_BASIC_INFO, realEmployee->getRole())) {
        realEmployee->getEmployeeInfo();
    }
}


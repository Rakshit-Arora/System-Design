/// A class should have only one Reason to change, like a class should have only one Responsiblity.
/// This is the Single Responsibility Principle (SRP) in action.

/// SRP Violation Example:
#include <iostream>
#include <string>
using namespace std;

class Employee{
    string name;
    double hoursWorked;
    double hourlyRate;

    public:

    Employee(string name, double hoursWorked, double hourlyRate) {
        this->name = name;
        this->hoursWorked = hoursWorked;
        this->hourlyRate = hourlyRate;
    }

    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }

    void printReport() {
        cout << "Employee: " << name << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Salary: $" << calculateSalary() << endl;
    }
};

// int main() {
//     Employee emp("John Doe", 40, 20);
//     emp.printReport(); // This method does two things: calculates salary and prints report.
//     return 0;
// }

/// SRP Compliant Example:
#include <iostream>
#include <string>
using namespace std;

class Employee {
    string name;
    double hoursWorked;
    double hourlyRate;

    public: 
    Employee(string name, double hoursWorked, double hourlyRate) {
        this->name = name;
        this->hoursWorked = hoursWorked;
        this->hourlyRate = hourlyRate;
    }

    string getName() {
        return name;
    }

    double getHoursWorked() {
        return hoursWorked;
    }

    double getHourlyRate() {
        return hourlyRate;
    }
};

class payCalculator {
    public: 
    double calculatePay(Employee& emp) {
        return emp.getHoursWorked() * emp.getHourlyRate();
    }
};

class ReportPrinter {
    public:
    void printReport(Employee& emp, double salary) {
        cout << "Employee Name: " << emp.getName() << endl;
        cout << "Hours Worked: " << emp.getHoursWorked() << endl;
        cout << "Hourly Rate: $" << emp.getHourlyRate() << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Employee emp("John Doe", 40, 40);
    payCalculator calculator;
    ReportPrinter printer;

    double salary = calculator.calculatePay(emp);
    printer.printReport(emp, salary); // Now each class has a single responsibility.
    
    return 0;
}
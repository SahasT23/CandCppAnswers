// Polymorphism and Virtual functions

#include <iostream>

class Employee {
public:
    virtual double calculatePay() {
        return 0.0;
    }
};

class FullTimeEmployee : public Employee {
private:
    double annualSalary;
public:
    FullTimeEmployee(double salary) : annualSalary(salary) {}

    double calculatePay() override {
        // Let's assume monthly pay
        return annualSalary / 12;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(double rate, int hours) 
        : hourlyRate(rate), hoursWorked(hours) {}

    double calculatePay() override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    Employee* e1 = new FullTimeEmployee(60000);
    Employee* e2 = new PartTimeEmployee(20, 80);

    std::cout << "Full-time Employee Pay: $" << e1->calculatePay() << std::endl;
    std::cout << "Part-time Employee Pay: $" << e2->calculatePay() << std::endl;

    delete e1;
    delete e2;
    return 0;
}
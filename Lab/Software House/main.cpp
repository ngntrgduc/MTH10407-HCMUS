#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee;
class Programmer;
class ProjectLeader;

class Employee {
    string payroll;
    int monthlySalary;
    string name;
public:
    Employee(string payroll, int monthlySalary, string name) {
        this->setName(name);
        this->setPayroll(payroll);
        this->setSalary(monthlySalary);
    }

    string getPayroll() {
        return this->payroll;
    }

    int getMonthlySalary() {
        return this->monthlySalary;
    }

    string getName() {
        return this->name;
    }

    void setPayroll(string payroll) {
        this->payroll = payroll;
    }

    void setSalary(int salary) {
        this->monthlySalary = salary;
    }

    void setName(string name) {
        this->name = name;
    }

    void display() {
        cout << "Number: " << this->getPayroll() << 
                ", Salary: " << this->getMonthlySalary() <<
                ", Name: " << this->getName() << '\n';
    }
};

class Programmer : public Employee {
    string language;
public:
    Programmer(string payroll, int monthlySalary, string name, string language) : Employee(payroll, monthlySalary, name) {
        this->setLanguage(language);
    }

    string getLanguage() {
        return this->language;
    }

    void setLanguage(string language) {
        this->language = language;
    }
    void display() {
        cout << "Number: " << this->getPayroll() << 
                ", Salary: " << this->getMonthlySalary() <<
                ", Name: " << this->getName() << 
                ", Language: " << this->getLanguage() << '\n';
    }
};

class ProjectLeader {

public:
    void addProgrammer(Programmer programmer) {

    }
    void display() {

    }
};

int main() {
    // Create some new programmers.
    Programmer* p1 = new Programmer("123", 2000, "John", "Ada");
    Programmer* p2 = new Programmer("234", 2500, "Ken", "C++");
    Programmer* p3 = new Programmer("456", 3000, "Peter", "Java");
    
    // Create some new project leaders.
    // ProjectLeader pl1("567", 4000, "Jon", "C");
    // ProjectLeader pl2("789", 4000, "Jessie", "Java");

    // Assign each programmer to a project leader
    // pl1.addProgrammer(p3);
    // pl1.addProgrammer(p2);
    // pl2.addProgrammer(p1);
    // pl1.display();
    // pl2.display();

    p1->display();
    p2->display();
    p3->display();

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Employee;
class Programmer;
class ProjectLeader;
class SoftwareHouse;

class Employee {
    string number;
    int salary;
    string name;
public:
    Employee(string number, int salary, string name) {
        this->setNumber(number);
        this->setSalary(salary);
        this->setName(name);
    }

    string getNumber() {
        return this->number;
    }

    int getSalary() {
        return this->salary;
    }

    virtual string getName() {
        return this->name;
    }

    void setNumber(string number) {
        this->number = number;
    }

    void setSalary(int salary) {
        this->salary = salary;
    }

    void setName(string name) {
        this->name = name;
    }

    virtual void display() {
        cout << "- Number: " << this->getNumber() << 
                "\n  Salary: " << this->getSalary() <<
                "\n  Name: " << this->getName() << '\n';
    }
};

class Programmer : public Employee {
    string language;
public:
    Programmer(string number, int salary, string name, string language) : Employee(number, salary, name) {
        this->setLanguage(language);
    }

    string getLanguage() {
        return this->language;
    }

    void setLanguage(string language) {
        this->language = language;
    }

    virtual void display() {
        Employee::display();
        cout << "  Language: " << this->getLanguage() << '\n';
    }

    string getName() {
        return Employee::getName();
    }
};

class ProjectLeader: public Programmer {
    unordered_map<string, Programmer*> team;
public:
    ProjectLeader(string number, int salary, string name, string language) 
        : Programmer(number, salary, name, language) {}

    void addProgrammer(Programmer *programmer) {
        this->team.insert({programmer->getNumber(), programmer});
    }

    void display() {
        cout << " --- Project Leader: \n";
        Programmer::display();
        cout << "+ Have programmers:\n";
        // for (auto it = this->team.begin(); it != this->team.end(); it++)
        //     it->second->display();
        for (auto programmer: team) 
            programmer.second->display();
    }

    string getName() {
        return Employee::getName();
    }
};

class SoftwareHouse {
    string name;
    map<string, Programmer*> staffs;
public:
    SoftwareHouse(string name) {
        this->setName(name);
    }
    SoftwareHouse() : SoftwareHouse("NA"){}

    string getName() {
        return this->name;
    }

    void setName(string name) {
        this->name = name;
    }

    void addProgrammer(Programmer *programmer) {
        this->staffs.insert({programmer->getNumber(), programmer});
        // this->staffs.emplace(programmer->getNumber(), programmer);
    }

    void displayStaff() {
        cout << "Software House: " << this->getName() << "\n";
        for (auto it = this->staffs.begin(); it != this->staffs.end(); it++) {
            // cout << it->second->getName() << endl;
            it->second->display();
        }
    }
};

int main() {
    // Create some new programmers.
    Programmer p1("123", 2000, "John", "Ada");
    Programmer p2("234", 2500, "Ken", "C++");
    Programmer p3("456", 3000, "Peter", "Java");    

    // Create some new project leaders.
    ProjectLeader pl1("567", 4000, "Jon", "C");
    ProjectLeader pl2("789", 4000, "Jessie", "Java");

    // Assign each programmer to a project leader
    pl1.addProgrammer(&p3);
    pl1.addProgrammer(&p2);
    pl2.addProgrammer(&p1);

    SoftwareHouse house("Mai am gia dinh");
    house.addProgrammer(&p2);
    house.addProgrammer(&p1);
    house.addProgrammer(&p3);
    house.addProgrammer(&pl1);
    house.addProgrammer(&pl2);
    house.displayStaff();
}
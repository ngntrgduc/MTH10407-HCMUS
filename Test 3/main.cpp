#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Person;
class Vaccine;
class TypeOfVaccine;
class Immunization;

class Person {
    string id;
    string name;
    string date;
    vector<Immunization*> immunization;
public:
    Person(string id, string name, string date) {
        this->setId(id);
        this->setName(name);
        this->setDate(date);
    }
    Person() {}

    void setId(string id) {
        this->id = id;
    }
    string getId() {
        return this->id;
    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    void setDate(string date) {
        this->date = date;
    }
    string getDate() {
        return this->date;
    }    

    void addImmunization(Immunization *im) {
        this->immunization.push_back(im);
    }
    vector<Immunization*> getImmunization() {
        return this->immunization;
    }

    void display() {
        cout << "  - Name: " << this->getName() << ":\n";
        cout << "  - ID: " << this->getId() << "\n";
        cout << "  - Date: " << this->getDate() << "\n";
    }

    void immunize(int dose, TypeOfVaccine* tov, string date);

    void printCertificate();
};

class Vaccine {
    string id;
    string date; 
public:
    Vaccine(string id, string date) {
        this->setId(id);
        this->setDate(date);
    }
    Vaccine() {}

    void setId(string id) {
        this->id = id;
    }
    string getId() {
        return this->id;
    }
    void setDate(string date) {
        this->date = date;
    }
    string getDate() {
        return this->date;
    }    
};

class TypeOfVaccine : public Vaccine {
    string name;
public:
    TypeOfVaccine(string id, string date, string name)
        : Vaccine(id, date) {
            this->setName(name);
        }
    TypeOfVaccine(string name)
        : Vaccine("00000", "????") {
            this->setName(name);
        }
    TypeOfVaccine() {}
    
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
};

class Immunization {
    int dose;
    string date;
    Person* person;
    TypeOfVaccine* vaccine;
public:
    Immunization(int dose, string date, Person *person, TypeOfVaccine *tov) {
        this->setDose(dose);
        this->setDate(date);
        this->setPerson(person);
        this->setVaccine(tov);
    }
    Immunization() {
        this->setDose(0);
    }
    void setDose(int dose) {
        this->dose = dose;
    }
    int getDose() {
        return this->dose;
    }
    void setDate(string date) {
        this->date = date;
    }
    string getDate() {
        return this->date;
    }
    void setPerson(Person *person) {
        this->person = person;
    }
    Person* getPerson() {
        return this->person;
    }
    void setVaccine(TypeOfVaccine *vaccine) {
        this->vaccine = vaccine;
    }
    TypeOfVaccine* getVaccine() {
        return this->vaccine;
    }

    void display() {
        cout << "  - Dose: " << this->getDose() << "\n";
        cout << "  - Name of vaccine: " << this->getVaccine()->getName() << "\n";
        cout << "  - Date: " << this->getDate() << "\n";
        cout << "  ------------------\n";
    }
};


// ====== Method implementation

void Person::immunize(int dose, TypeOfVaccine* tov, string date) {
    Immunization *im = new Immunization(dose, date, this, tov);
    this->addImmunization(im);
    cout << this->getName() << " immunized with " << tov->getName() << " at " << date << "\n";
}

void Person::printCertificate() {
    cout << "Certificate for " << this->getName() << ":\n";
    cout << " Person infomation:\n";
    this->display();
    cout << " Immunization:\n";
    for (int i = 0; i < this->getImmunization().size(); i++) {
        this->getImmunization()[i]->display();
    }
    cout << "\n";
}


// ====== Main
int main() {
    // Create 2 people
    Person *p1 = new Person("12345", "Person 1", "2003");
    Person *p2 = new Person("67890", "Person 2", "2000");
    
    // Create 2 type of vaccines: Pfizer, Moderna
    TypeOfVaccine *pfizer = new TypeOfVaccine("001", "2021", "Pfizer");
    TypeOfVaccine *moderna = new TypeOfVaccine("002", "2022", "Moderna");

    // Immunize Person 1    
    p1->immunize(1, pfizer, "1-1-2020");
    p1->immunize(2, pfizer, "1-5-2020");

    // Immunize Person 2
    p2->immunize(1, moderna, "2-2-2021");
    p2->immunize(2, pfizer, "2-6-2021");

    // Print certificate
    cout << "\nPrinting certificate:\n";
    p1->printCertificate();
    p2->printCertificate();
    
    return 0;
}
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Person;
class Vaccine;

class Person
{
    private:
        string id;
        string name;
        string date;
        vector<pair<Vaccine*, pair<string, string>>> immunizations;

    public:

        //Constructor
        Person(string id, string name, string date)
        {
            this->setId(id);
            this->setName(name);
            this->setDate(date);
        }

        //Defaut constructor
        Person(string id) : Person(id, "NA", "NA") {};
        Person() : Person ("???", "NA", "NA") {};

        //Destructor
        ~Person() {};

        //Access methods: Getters and Setters
        void setId(string id) 
        {
            this->id = id;
        }
        const string& getId() const
        {
            return id;
        }
        void setName(string name)
        {
            this->name = name;
        }
        const string& getName() const
        {
            return name;
        }
        void setDate(string date)
        {
            this->date = date;
        }
        const string& getDate() const 
        {
            return date;
        }

        //Other methods
        void addImmunization(Vaccine* vaccine, string dose, string date) 
        {
            immunizations.push_back(make_pair(vaccine, make_pair(dose, date)));
        }
        void printCertificate() 
        {
        cout << "ID: " << this->getId() << endl;
        cout << "Date: " << this->getDate() << endl;
        cout << "Information immunization of " << getName() << ":" << endl;
        for (auto immunization : immunizations) {
            cout << "Injection: " << immunization).first << ", Dose: " << immunization.second.first << ", Date: " << immunization.second.second << endl;
        }
        cout << "==========================" << endl;
    }
};

class Vaccine 
{
    private:
        int idVac;
        string dateVac;

    public:

        //Constructor
        Vaccine(int idVac, string dateVac)
        {
            this->setId(idVac);
            this->setDate(dateVac);
        }

        //Defaut constructor
        Vaccine(int id) : Vaccine(id, "NA") {};
        Vaccine() : Vaccine(0, "NA") {};

        //Destructor
        ~Vaccine() {};

        //Access methods: Getters and Setters
        void setId(int idVac)
        {
            this->idVac = idVac;
        }
        const int& getId() const
        {
            return idVac;
        }
        void setDate(string dateVac)
        {
            this->dateVac = dateVac;
        }
        const string& getDate() const
        {
            return dateVac;
        }
};

class Pfizer : public Vaccine 
{
    public:
        Pfizer(int id, string date) : Vaccine(id, date) 
        {}
        string nameVac = "Pfizer";
};

class Moderna : public Vaccine 
{
    public:
        Moderna(int id, string date) : Vaccine(id, date) 
        {}
        string nameVac = "Moderna";
};

int main() {

    //Create person
    Person person1("04503213123", "Nguyen Huu Minh", "1985");
    Person person2("05213123213", "Nguyen Van Huy", "1990");

    //Create Vaccine
    Pfizer pfizer1(1, "2021");
    Pfizer pfizer2(2, "2021");
    Moderna moderna1(3, "2022");
    Moderna moderna2(4, "2022");

    //Add Immunization to person
    person1.addImmunization(&pfizer1, "Dose 1", "01/06/2022");
    person1.addImmunization(&pfizer2, "Dose 2", "15/02/2023");

    person2.addImmunization(&moderna1, "Dose 1", "02/06/2022");
    person2.addImmunization(&moderna2, "Dose 2", "01/03/2023");

    //Print Certificate of Immunization
    person1.printCertificate();

    person2.printCertificate();


    return 0;
}
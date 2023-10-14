// Thay check mail cua em voi a, 21110269@student.hcmus.edu.vn a.
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Student;
class Faculty;
class UndergraduateStudent;
class GraduateStudent;
class Enrollment;

class Student {
    string id;
    string name;
    vector<Enrollment*> enrollments;
public:
    Student(string id, string name) {
        this->setId(id);
        this->setName(name);
    }
    Student() {}

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

    void setEnrollment(vector<Enrollment*> enrollemnts) {
        this->enrollments = enrollemnts;
    }

    vector<Enrollment*> getEnrollment() {
        return enrollments;
    }

    // float getGPA() {
    //     return this->gpa;
    // }
    virtual void display() {
        cout << "Id: " << this->getId() << "\n";
        cout << "Name: " << this->getName() << "\n";
    }

    void setGPA(string major, float gpa);
    // virtual void enroll(Faculty* faculty, string major);
};


class UndergraduateStudent: public Student {
    vector<Enrollment*> enrollments;
public:
    UndergraduateStudent(string id, string name) 
        :Student(id, name) {
    }

    void display() {
        Student::display();
        // cout << "Major: " << this-> << "\n";
    }

    void enroll(Faculty* faculty, std::string major);

    void setGPA(string major, float gpa);
};

class GraduateStudent: public Student {
    string degree;
    vector<Enrollment> enrollments;
public:
    GraduateStudent(string id, string name,string degree) 
        :Student(id, name) {
        this->setDegree(degree);
    }

    void setDegree(string degree) {
        this->degree = degree;
    }

    string getDegree() {
        return this->degree;
    }

    void display() {
        Student::display();
        cout << "Degree: " << this->getDegree() << "\n";
    }

    void enroll(Faculty* faculty, string major);

    void setGPA(string degree, float gpa);
};

class Faculty {
    string name;
    vector<Student*> students;
    vector<Enrollment> enrollments;
public:
    Faculty(string name) {
        this->setName(name);
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    vector<Student*> getStudents() {
        return this->students;
    }

    // void addStudent(Student* student, string major) {
    //     this->getStudents().push_back(student);
    // }
    // void addStudent(GraduateStudent student, string degree) {
    //     this->getStudents().push_back(student);
    //     // enrollments.push_back(Enrollment())
    // }

    void addStudent(Student* student, string major);

    void setGPA(Student* student, string major, float gpa);

    void displayStudents();
};

class Enrollment {
    Faculty* faculty;
    string major;
    float gpa;
public: 
    Enrollment(Faculty* faculty, string major, float gpa){
        this->faculty = faculty;
        this->major = major;
        this->gpa = gpa;
    };

    void setGPA(float gpa) {
        this->gpa = gpa;
    }
};


// void Student::setEnrollment(Faculty* faculty, string major) {
//     enrollments.push_back()
// }

void Faculty::addStudent(Student* student, string major) {
    students.push_back(student);
    // this->enrollments = Enrollment(this, major, 0);
}

void Faculty::setGPA(Student* student, string major, float gpa) {

}

void Faculty::displayStudents() {
    std::cout << "Faculty: " << name << std::endl;
    for (const auto& student : students) {
        student->display();
    }
}

int main() {
    UndergraduateStudent* a = new UndergraduateStudent("001", "Nguyen Trung Duc");
    GraduateStudent* b = new GraduateStudent("002", "Nguyen Van A", "master");

    Faculty* khoaToan = new Faculty("Khoa Toan - Tin hoc");
    Faculty* khoaCNTT = new Faculty("Khoa Cong nghe thong tin");

    khoaToan->addStudent(a, "nganh Toan");
    khoaCNTT->addStudent(a, "nganh Khoa hoc May tinh");

    khoaToan->addStudent(b, "nganh Toan", "master");
    khoaCNTT->addStudent(b, "nganh Khoa hoc May tinh", "PhD");

    khoaToan->setGPA(a, 9);
    khoaCNTT->setGPA(a, 9);

    khoaToan->setGPA(b, 10);
    khoaCNTT->setGPA(b, 10);

    khoaToan->displayStudents();
    khoaCNTT->displayStudents();
}
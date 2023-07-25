#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Person;
class Professor;
class Student;
class Course;
class Section;
class ScheduleOfClasses;
class Transcript;
class TranscriptEntry;

class Person {
    string ssn;
    string name;
public: 
    Person(string ssn, string name) {
        this->setSsn(ssn);
        this->setName(name);
    }
    Person(): Person("NA", "NA"){}

    void setSsn(string ssn) {
        this->ssn = ssn;
    }
    string getSsn() {
        return this->ssn;
    }

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }

    virtual void display() {
        cout << "\tName: " << this->name << "\n";
        cout << "\tSSN: " << this->ssn << "\n";
    }
};

class Professor: public Person {
    string title;
    string department;
    vector<Section*> teaches;
public: 
    Professor(string ssn, string name, string title, string department)
        : Person(ssn, name) {
        this->setTitle(title);
        this->setDepartment(department);
    }
    void setTitle(string title) {
        this->title = title;
    }
    string getTitle() {
        return this->title;
    }

    void setDepartment(string department) {
        this->department = department;
    }
    string getDepartment() {
        return this->department;
    }

    void display() {
        cout << "Professor: \n";
        Person::display();
        cout << "\tTitle: " << this->title << "\n";
        cout << "\tDepartment: " << this->department << "\n";
    }

    void agreeToTeach(Section *section);
};

class Student: public Person {
    string major;
    string degree;
    vector<Section*> attends;
    Transcript* transcript;
public: 
    Student(string ssn,string name,string major,string degree);
    
    void setMajor(string major) {
        this->major = major;
    }
    string getMajor() {
        return this->major;
    }

    void setDegree(string degree) {
        this->degree = degree;
    }
    string getDegree() {
        return this->degree;
    }

    void setTranscript(Transcript* transcript) {
        this->transcript = transcript;
    }
    Transcript *getTranscript() {
        return this->transcript;
    }

    void display() {
        cout << "Student:\n";
        this->Person::display();
        cout << "\tMajor: " << this->major << "\n";
        cout << "\tDegree: " << this->degree << "\n";
        this->displayCourseSchedule();
        this->printTranscript();
    }

    void addSection(Section *section) {
        this->attends.push_back(section);
    }
    void dropSection(Section *section);
    bool isEnrolledIn(Section *section);
    void printTranscript();
    void displayCourseSchedule();
};

class Course {
    string courseNo;
    string courseName;
    int credits;
    vector<Section*> offeredAsSection;
    vector<Course*> prerequisites;
public:
    Course(string courseNo, string name, int credits) {
        this->setCourseNo(courseNo);
        this->setName(name);
        this->setCredits(credits);
    }
    void setCourseNo(string courseNo) {
        this->courseNo = courseNo;
    }
    string getCourseNo() {
        return this->courseNo;
    }

    void setName(string name) {
        this->courseName = name;
    }
    string getName() {
        return this->courseName;
    }

    void setCredits(int credits) {
        this->credits = credits; 
    }
    int getCredits() {
        return this->credits;
    }

    void addSection(Section *section) {
        this->offeredAsSection.push_back(section);
    }

    Section* scheduleSection(string day, string time, string room, int capacity);

    void addPrerequisite(Course *course) {
        this->prerequisites.push_back(course);
    }

    vector<Course*> getPrerequisitises() {
        return this->prerequisites;
    }

    void displayPrerequisitises() {
        if (this->getPrerequisitises().size() == 0) return;
        cout << "Prerequisitises of " << this->getName() << ":\n";
        for (auto course: this->getPrerequisitises()) {
            cout << " - " << course->getName() << "\n";
        }
    }

    bool hasPrerequisites() {
        return this->prerequisites.size() > 0;
    }
};

class Section {
    string sectionNo;
    string dayOfWeek;
    string timeOfDay;
    string room;
    int seatingCapacity;
    Professor *instructor;
    Course *representedCourse;
    ScheduleOfClasses *offerIn;
    map<string, Student*> enrolledStudents;
    map<Student*,TranscriptEntry*> graded;
public:
    Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity) {
        this->setSectionNo(sectionNo);
        this->setDayOfWeek(dayOfWeek);
        this->setTimeOfDay(timeOfDay);
        this->setRoom(room);
        this->setSeatingCapacity(seatingCapacity);
    }
    void setSectionNo(string sectionNo) {
        this->sectionNo = sectionNo;
    }
    string getSectionNo() {
        return this->sectionNo;
    }

    void setDayOfWeek(string day) {
        this->dayOfWeek = day;
    }
    string getDayOfWeek() {
        return this->dayOfWeek;
    }

    void setTimeOfDay(string time) {
        this->timeOfDay = time;
    }
    string getTimeOfDay() {
        return this->timeOfDay;
    }
    
    void setRoom(string room) {
        this->room = room;
    }
    string getRoom() {
        return this->room;
    }
    
    void setSeatingCapacity(int capacity) {
        this->seatingCapacity = capacity;
    }
    int getSeatingCapacity() {
        return this->seatingCapacity;
    }

    void setClass(ScheduleOfClasses* soc) {
        this->offerIn = soc;
    }        
    ScheduleOfClasses* getClasses() {
        return this->offerIn;
    }

    void setInstructor(Professor* prof) {
        this->instructor = prof;
    }
    Professor* getInstructor() {
        return this->instructor;
    }

    void enroll(Student*);

    bool drop(Student *student) {
        if (!(student->isEnrolledIn(this))) {
            return false;
        } else {
            enrolledStudents.erase(student->getSsn());
            student->dropSection(this);
            return true;
        }
    }

    bool postGrade(Student *student, float grade);

    bool confirmSeatAvailability() {
        return enrolledStudents.size() < this->seatingCapacity;
    }

    void setOfferedIn(ScheduleOfClasses *soc) {
        this->offerIn = soc;
    }

    ScheduleOfClasses *getOfferedIn() {
        return this->offerIn;
    }

    float getGrade(Student *student);

    Course* getCourse() {
        return this->representedCourse;
    }

    void setCourse(Course *course) {
        this->representedCourse = course; 
    }

    Course *getRepresentedCourse() {
        return this->representedCourse;
    }

    void display();

    map<string, Student*> getStudents() {
        return this->enrolledStudents;
    }
};

class ScheduleOfClasses {
    string semester;
    map<string, Section*> sectionOffered;
public:
    ScheduleOfClasses(string semester) {
        this->setSemester(semester);
    }

    string getSemester() {
        return this->semester;
    }

    void setSemester(string semester) {
        this->semester = semester;
    }

    void addSection(Section *section) {
        sectionOffered.insert({section->getSectionNo(), section});
        section->setOfferedIn(this);
    }

    void display() {
        cout << "Schedule Of Classes for " << this->getSemester() << "\n";
        for (auto it = sectionOffered.begin(); it != sectionOffered.end(); it++) {
            cout << "Section Information: \n";
            it->second->display();
        }
    }
};

class Transcript {
    vector<TranscriptEntry*> transcriptEntries;
    Student *studentOwner;
public:
    Transcript(Student* studentOwner){
        this->studentOwner = studentOwner;
    }

    void display();
    void addTranscriptEntry(TranscriptEntry* te);
    bool verifyCompletion(Course *course);
};

class TranscriptEntry {
    float grade;
    Student *student;
    Section *section;
public:
    TranscriptEntry(Student *student, Section *section, float grade) {
        this->setStudent(student);
        this->setSection(section);
        this->setGrade(grade);
        Transcript *transcript = student->getTranscript();
        transcript->addTranscriptEntry(this);
    }
    
    bool validateGrade(float grade) {
        return (grade >= 0 && grade <= 10);
    }


    bool passingGrade() {
        if (validateGrade(this->getGrade())) {
            return this->getGrade() > 5;
        }
        return false;
    }

    void setGrade(float grade) {
        if (validateGrade(grade))
            this->grade = grade;
    }
    float getGrade() {
        return this->grade;
    }

    void setStudent(Student *s) {
        this->student = s;
    }

    Student *getStudent() {
        return this->student;
    }

    void setSection(Section *se) {
        this->section = se;
    }

    Section *getSection() {
        return this->section;
    }
};


// ======================================================================
// Professor
void Professor::agreeToTeach(Section *section) {
    teaches.push_back(section);
    section->setInstructor(this);
}

// Student
Student::Student(string ssn, string name, string major, string degree)
    : Person(ssn, name) {
        this->setMajor(major);
        this->setDegree(degree);
        Transcript* transcript = new Transcript(this);
        this->setTranscript(transcript);
        this->attends = vector<Section*>();
    }

void Student::displayCourseSchedule() {
    cout << "  Course schedule for: " << this->getName() << "\n";
    for (int i = 0; i < this->attends.size(); i++){
        cout << "    Section No: " << attends[i]->getSectionNo() << "\n";
        cout << "\tCourse No: " << attends[i]->getCourse()->getName()  << "\n";
        cout << "\tMeeting Day: " << attends[i]->getDayOfWeek() << "\n";
        cout << "\tTime Held: " << attends[i]->getTimeOfDay() << "\n";
        cout << "\tRoom: "<< attends[i]->getRoom() << "\n";
        
        if (this->attends[i]->getInstructor())
            cout << "\tProfessor:  \t" << this->attends[i]->getInstructor()->getName() << "\n";
        else
            cout << "\tProfessor:  \tUnknow!" << "\n";
        cout << "\t--------\n";
    }
}

void Student::dropSection(Section *section) {
    for (int i = 0; i < this->attends.size(); i++) {
        if (this->attends[i] == section) {
            this->attends.erase(this->attends.begin() + i); 
            cout << this->getName() << " dropped " << section->getCourse()->getName() << "\n";
            break;
        }
    }
}

bool Student::isEnrolledIn(Section *section) {
    for (int i = 0; i < this->attends.size(); i++) {
        if (attends[i]->getSectionNo() == section->getSectionNo()) {
            return true;
        }
    }    
    return false;
}
void Student::printTranscript() {
    this->transcript->display();
}


// Transcript
void Transcript::addTranscriptEntry(TranscriptEntry* te) {
    this->transcriptEntries.push_back(te);
}

void Transcript::display() {
    cout << "  Transcript of: " << this->studentOwner->getName() << "\n";
    if (this->transcriptEntries.size() == 0) cout << "\tDoesn't have transcript\n";
    else for (int i = 0; i < this->transcriptEntries.size(); i++) {
        cout << "\tCourse Name: \t" << this->transcriptEntries[i]->getSection()->getCourse()->getName() << "\n";
        if (this->transcriptEntries[i])
            cout << "\tGrade:   \t" << this->transcriptEntries[i]->getGrade() << "\n";
        else
            cout << "\tGrade:   \tUnknow!\n";
        cout << "\t--------\n";
    }
}

bool Transcript::verifyCompletion(Course* course) {
    for (int i = 0; i < this->transcriptEntries.size(); i++) {
        if (this->transcriptEntries[i]->getSection()->getCourse() == course) {
            if (this->transcriptEntries[i]->passingGrade()) {
                // cout << " - Passed this course\n";
                return true;
            } else {
                // cout << " - Not passed this course, pass away\n";
                return false;
            }
        }
    }
    return false; // doesn't study this course
}

// Course
Section* Course::scheduleSection(string day, string time, string room, int capacity) {
    Section *section = new Section(to_string(offeredAsSection.size() + 1), day, time, room, capacity);
    section->setCourse(this);
    this->addSection(section);
    return section;
}

// Section
bool Section::postGrade(Student *student, float grade) {
    // Assume that grade in a right format
    // if (!TranscriptEntry::validateGrade(grade)) return false;
    
    // Check if student enrolled in course
    if (!student->isEnrolledIn(this)) {
        return false;
    }
    // Check if student have been graded, using another changeGrade() method
    if (graded[student]) {
        return false;
    }

    // TranscriptEntry *te = new TranscriptEntry(student, this, grade);
    // this->graded.insert({student, te});
    cout << "  Post grade " << grade << " for " << student->getName() << " in " << this->getCourse()->getName() << "\n";
    graded[student] = new TranscriptEntry(student, this, grade);
    return true;
}

float Section::getGrade(Student *student) {
    return this->graded[student]->getGrade();
}

void Section::display() {
    cout << "Semester: "      + this->getOfferedIn()->getSemester() << "\n";
    cout << "  Course Name: " + this->getCourse()->getName() << "\n";
    cout << "\tCourse No: "   + this->getCourse()->getCourseNo() << "\n";
    cout << "\tSection No: "  + this->getSectionNo() << "\n";
    cout << "\tOffered: "     + this->getDayOfWeek() +" at " + this->getTimeOfDay() << "\n";
    cout << "\tIn Room: "     + this->getRoom() << "\n";
    string professor = (this->getInstructor() != NULL) ? this->getInstructor()->getName() : "Unknow!";
    cout << "\tProfessor: "  + professor << "\n";
    map<string,Student*> students = this->getStudents();
    if (students.size() == 0) {
        cout << "    Total 0 students enrolled\n";
    } else {
        string st = (students.size() > 1) ? "students" : "student";
        cout << "    Total " + to_string(students.size()) + " " + st + " enrolled, as follows:\n";
        for (auto student: students)
            cout << "\t" + student.second->getName() << "\n";
    }
    cout << "\n";
}

void Section::enroll(Student *student) {
    Course *course = this->getCourse();
    cout << student->getName() << " is enrolling: " << course->getName() << "...\n";
    if (course->hasPrerequisites()) {
        vector<Course*> prerequisitises = course->getPrerequisitises();
        for (auto it = prerequisitises.begin(); it != prerequisitises.end(); ++it) {
            if (!(student->getTranscript()->verifyCompletion(*it))) {
                cout << " - Students didn't complete the prerequisite course:\n\t" + (*it)->getName() + "\n";
                return;
            }
        }
    }

    if (confirmSeatAvailability()) {
        if (!student->isEnrolledIn(this)) {
            enrolledStudents.insert({student->getSsn(), student});
            student->addSection(this);
            cout << " - Complete to enroll this section\n";
        } else {
            if (!student->getTranscript()->verifyCompletion(course))
                cout << " - Already registered this section\n"; 
            else 
                cout << " - Student passed this course\n";
        }
    }
}


// ==============================================================
int main() {
    vector<Professor*> professors;
    vector<Student*> students;
    vector<Course*> courses;
    
    // Professor *p1, *p2, *p3;
    Professor *p1 = new Professor("123-45-6789", "Jacquie Barker", "Adjunct Professor", "Information Technology");
    Professor *p2 = new Professor("567-81-2345", "Claudio Cioffi", "Full Professor", "Computational Social Sciences");
    Professor *p3 = new Professor("987-65-4321", "Snidely Whiplash", "Full Professor", "Physical Education");
    professors.push_back(p1);
    professors.push_back(p2);
    professors.push_back(p3);

    // Student *s1, *s2, *s3;
    Student *s1 = new Student("111-11-1111", "Joe Blow", "Math", "M.S.");
    Student *s2 = new Student("222-22-2222", "Fred Schnurd", "Information Technology", "Ph. D.");
    Student *s3 = new Student("333-33-3333", "Mary Smith", "Physics", "B.S.");
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);

    // Course *c1, *c2, *c3, *c4, *c5;
    Course *c1 = new Course("CMP101", "Beginning Computer Technology", 3.0);
    Course *c2 = new Course("OBJ101", "Object Methods for Software Development", 3.0);
    Course *c3 = new Course("CMP283", "Higher Level Languages (Java)", 3.0);
    Course *c4 = new Course("CMP999", "Living Brain Computers", 3.0);
    Course *c5 = new Course("ART101", "Beginning Basketweaving", 3.0);

    courses.push_back(c1);
    courses.push_back(c2);
    courses.push_back(c3);
    courses.push_back(c4);
    courses.push_back(c5);

    c2->addPrerequisite(c1);
    c3->addPrerequisite(c2);
    c4->addPrerequisite(c3);

    // Section *sec1, *sec2, *sec3, *sec4, *sec5, *sec6, *sec7;
    Section *sec1 = c1->scheduleSection("Mon", "8:10 - 10:00 PM", "GOVT101", 30);
    Section *sec2 = c1->scheduleSection("Wed", "6:10 - 8:00 PM", "GOVT202", 30); 
    Section *sec3 = c2->scheduleSection("Thu", "4:10 - 6:00 PM", "GOVT105", 25); 
    Section *sec4 = c2->scheduleSection("Tue", "6:10 - 8:00 PM", "SCI330", 25);  
    Section *sec5 = c3->scheduleSection("Mon", "6:10 - 8:00 PM", "GOVT101", 20); 
    Section *sec6 = c4->scheduleSection("Thu", "4:10 - 6:00 PM", "SCI241", 15);  
    Section *sec7 = c5->scheduleSection("Mon", "4:10 - 6:00 PM", "ARTS25", 40);  

    ScheduleOfClasses schedule("HK2-2023");
    schedule.addSection(sec1);
    schedule.addSection(sec2);
    schedule.addSection(sec3);
    schedule.addSection(sec4);
    schedule.addSection(sec5);
    schedule.addSection(sec6);
    schedule.addSection(sec7);
    
    p1->agreeToTeach(sec3);
    p1->agreeToTeach(sec5);
    p2->agreeToTeach(sec2);
    p2->agreeToTeach(sec6);
    p3->agreeToTeach(sec1);
    p3->agreeToTeach(sec4);
    p3->agreeToTeach(sec7);

    cout << "====================================\nStudent registration has begun!\n====================================\n";
    sec1->enroll(s1);
    sec1->enroll(s1);
    // s1->dropSection(sec1);
    sec2->enroll(s2);
    sec3->enroll(s2);
    sec7->enroll(s2);
    sec1->enroll(s3);

    cout << "Begin post grade...\n";
    sec1->postGrade(s1, 10);
    sec1->postGrade(s3, 1);
    // sec1->changeGrade(s1, 9);

    sec1->enroll(s1); 

    cout << "\n====================================\n\tSection Display\n====================================\n";
    sec1->display();
    sec2->display();
    sec3->display();
    sec4->display();
    sec5->display();
    sec6->display();

    // cout << "\n====================================\n\tProfessor Information\n====================================\n";
    // p1->display();
    // p2->display();
    // p3->display();

    cout << "\n====================================\n\tStudent Information\n====================================\n";
    s1->display();
    s2->display();
    s3->display();

    cout << "\n====================================\n\tSchedule Display\n====================================\n";
    schedule.display();

    cout << "====================================== END ======================================";
    return 0;


    // vector<Professor*> professors;
    // vector<Student*> students;
    // vector<Course*> courses;

    // ScheduleOfClasses sche("HK2-2023");

    // // Professor *p1, *p2, *p3;
    // Professor p1("123-45-6789", "Jacquie Barker", "Adjunct Professor", "Information Technology");
    // Professor p2("567-81-2345", "Claudio Cioffi", "Full Professor", "Computational Social Sciences");
    // Professor p3("987-65-4321", "Snidely Whiplash", "Full Professor", "Physical Education");
    // professors.push_back(&p1);
    // professors.push_back(&p2);
    // professors.push_back(&p3);

    // // Student *s1, *s2, *s3;
    // Student s1(" s1111-11-1111", "Joe Blow", "Math", "M.S.");
    // Student s2("222-22-2222", "Fred Schnurd", "Information Technology", "Ph. D.");
    // Student s3("333-33-3333", "Mary Smith", "Physics", "B.S.");
    // students.push_back(&s1);
    // students.push_back(&s2);
    // students.push_back(&s3);

    // // Course *c1, *c2, *c3, *c4, *c5;
    // Course c1("CMP101", "Beginning Computer Technology", 3.0);
    // Course c2("OBJ101", "Object Methods for Software Development", 3.0);
    // Course c3("CMP283", "Higher Level Languages (Java)", 3.0);
    // Course c4("CMP999", "Living Brain Computers", 3.0);
    // Course c5("ART101", "Beginning Basketweaving", 3.0);

    // courses.push_back(&c1);
    // courses.push_back(&c2);
    // courses.push_back(&c3);
    // courses.push_back(&c4);
    // courses.push_back(&c5);

    // c2.addPrerequisite(&c1);
    // c3.addPrerequisite(&c2);
    // c4.addPrerequisite(&c3);

    // Section *sec1, *sec2, *sec3, *sec4, *sec5, *sec6, *sec7;
    // sec1 = c1.scheduleSection("Mon", "8:10 - 10:00 PM", "GOVT101", 30); 
    // sec2 = c1.scheduleSection("Wed", "6:10 - 8:00 PM", "GOVT202", 30);  
    // sec3 = c2.scheduleSection("Thu", "4:10 - 6:00 PM", "GOVT105", 25);  
    // sec4 = c2.scheduleSection("Tue", "6:10 - 8:00 PM", "SCI330", 25);   
    // sec5 = c3.scheduleSection("Mon", "6:10 - 8:00 PM", "GOVT101", 20);  
    // sec6 = c4.scheduleSection("Thu", "4:10 - 6:00 PM", "SCI241", 15);   
    // sec7 = c5.scheduleSection("Mon", "4:10 - 6:00 PM", "ARTS25", 40);   

    // sche.addSection(sec1);
    // sche.addSection(sec2);
    // sche.addSection(sec3);
    // sche.addSection(sec4);
    // sche.addSection(sec5);
    // sche.addSection(sec6);
    // sche.addSection(sec7);

    // p3.agreeToTeach(sec1);
    // p2.agreeToTeach(sec2);
    // p1.agreeToTeach(sec3);
    // p3.agreeToTeach(sec4);
    // p1.agreeToTeach(sec5);
    // p2.agreeToTeach(sec6);
    // p3.agreeToTeach(sec7);

    // cout << "====================================\nStudent registration has begun!\n====================================\n";
    
    // sec1->enroll(&s1);
    // sec1->enroll(&s1);
    // sec2->enroll(&s2);
    // sec3->enroll(&s2);
    // sec7->enroll(&s2);
    // sec1->enroll(&s3);

    // cout << "Begin post grade...\n";
    // sec1->postGrade(&s1, 10);
    // sec1->postGrade(&s3, 1);
    // // sec1->changeGrade(s1, 9);

    // sec1->enroll(&s1); 

    // cout << "\n====================================\n\tSection Display\n====================================\n";
    // sec1->display();
    // sec2->display();
    // sec3->display();

    // cout << "\n====================================\n\tProfessor Information\n====================================\n";
    // p1.display();
    // p2.display();
    // p3.display();

    // cout << "\n====================================\n\tStudent Information\n====================================\n";
    // s1.display();
    // s2.display();
    // s3.display();

    // cout << "====================================== END ======================================";
}
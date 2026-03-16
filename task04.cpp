#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;
public:
    Person() {}
    Person(string n, int i, string a, string p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    string getName() { return name; }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string n, string a, string p, string e) {
        name = n;
        address = a;
        phoneNumber = p;
        email = e;
    }
};

class Student : public Person {
private:
    string coursesEnrolled[10];
    int courseCount;
    double GPA;
    int enrollmentYear;
public:
    Student() { courseCount = 0; }
    Student(string n, int i, string a, string p, string e, double g, int year)
        : Person(n,i,a,p,e), GPA(g), enrollmentYear(year), courseCount(0) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Courses Enrolled: ";
        for(int i=0;i<courseCount;i++)
            cout << coursesEnrolled[i] << " ";
        cout << endl;
    }

    void enrollCourse(string courseName) {
        if(courseCount < 10)
            coursesEnrolled[courseCount++] = courseName;
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught[10];
    int courseCount;
    double salary;
public:
    Professor() { courseCount = 0; }
    Professor(string n,int i,string a,string p,string e,string dept,double s)
        : Person(n,i,a,p,e), department(dept), salary(s), courseCount(0) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Courses Taught: ";
        for(int i=0;i<courseCount;i++)
            cout << coursesTaught[i] << " ";
        cout << endl;
    }

    void addCourse(string courseName) {
        if(courseCount < 10) coursesTaught[courseCount++] = courseName;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;
public:
    Staff() {}
    Staff(string n,int i,string a,string p,string e,string dept,string pos,double s)
        : Person(n,i,a,p,e), department(dept), position(pos), salary(s) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;
    Student* enrolledStudents[50];
    int studentCount;
public:
    Course() { studentCount = 0; }
    Course(string id,string name,int c,Professor* prof,string sch)
        : courseId(id), courseName(name), credits(c), instructor(prof), schedule(sch), studentCount(0) {}

    void registerStudent(Student* student) {
        if(studentCount < 50) {
            enrolledStudents[studentCount++] = student;
            student->enrollCourse(courseName);
        }
    }

    void displayCourseInfo() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << endl;
        instructor->displayInfo();
        cout << "Schedule: " << schedule << endl;
        cout << "Enrolled Students: ";
        for(int i=0;i<studentCount;i++)
            cout << enrolledStudents[i]->getName() << " ";
        cout << endl;
    }
};

class Department {
public:
    string deptName;
    Professor* professors[10];
    Staff* staffMembers[20];
    int profCount;
    int staffCount;
    Department() { profCount = 0; staffCount = 0; }

    void addProfessor(Professor* prof) {
        if(profCount < 10) professors[profCount++] = prof;
    }

    void addStaff(Staff* s) {
        if(staffCount < 20) staffMembers[staffCount++] = s;
    }
};

class Schedule {
public:
    string day;
    string time;
};

class Grade {
public:
    Student* student;
    string course;
    char grade;
};

class University {
public:
    Student* students[100];
    Professor* professors[50];
    Staff* staffs[50];
    Course* courses[50];
    int studentCount, profCount, staffCount, courseCount;

    University() { studentCount = profCount = staffCount = courseCount = 0; }

    void addStudent(Student* s) {
        if(studentCount<100) students[studentCount++] = s;
    }
    void addProfessor(Professor* p) {
        if(profCount<50) professors[profCount++] = p;
    }
    void addStaff(Staff* s) {
        if(staffCount<50) staffs[staffCount++] = s;
    }
    void addCourse(Course* c) {
        if(courseCount<50) courses[courseCount++] = c;
    }
};

int main() {
    Professor prof1("Dr.Will", 100, "12 uni ST", "9250-1234", "Will@uni.edu", "Computer Science", 90000);
    prof1.addCourse("CS101");

    Student s1("Lisa", 150, "40 Elm St", "555-5230", "lisa@mail.com", 4.0, 2023);
    Student s2("Jimmy", 201, "70 Oak St", "555-8456", "Jimmy@mail.com", 3.8, 2022);

    Course c1("CS101", "Intro to CS", 3, &prof1, "Mon 10-12");
    c1.registerStudent(&s1);
    c1.registerStudent(&s2);

    cout << "   Professor Info " << endl;
    prof1.displayInfo();
    cout << endl;

    cout << "    Students Info " << endl;
    s1.displayInfo();
    cout << endl;
    s2.displayInfo();
    cout << endl;

    cout << "   Course Info " << endl;
    c1.displayCourseInfo();
    cout << endl;

    return 0;
}
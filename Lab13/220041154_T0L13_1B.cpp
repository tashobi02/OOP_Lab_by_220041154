#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Person {
   protected:
    string name;
    int id;

   public:
    Person() : name(""), id(0) {}
    Person(string n, int i) : name(n), id(i) {}

    string getName() const { return name; }
    int getId() const { return id; }

    virtual void display() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
   private:
    set<string> coursesEnrolled;

   public:
    Student() : Person() {}
    Student(string n, int i) : Person(n, i) {}

    void enrollCourse(const string& courseCode) {
        coursesEnrolled.insert(courseCode);
    }

    void display() const override {
        cout << "Student - ";
        Person::display();
        cout << "Courses Enrolled: ";
        for (const auto& course : coursesEnrolled) cout << course << " ";
        cout << endl;
    }
};

class Instructor : public Person {
   private:
    set<string> coursesTeaching;

   public:
    Instructor() : Person() {}
    Instructor(string n, int i) : Person(n, i) {}

    void assignCourse(const string& courseCode) {
        coursesTeaching.insert(courseCode);
    }

    void display() const override {
        cout << "Instructor - ";
        Person::display();
        cout << "Courses Teaching: ";
        for (const auto& course : coursesTeaching) cout << course << " ";
        cout << endl;
    }
};

map<string, string> courses;
map<int, Student> students;
map<int, Instructor> instructors;

void addCourse(const string& code, const string& name) {
    courses[code] = name;
    cout << "Course added successfully!" << endl;
}

void enrollStudent(int studentId, const string& studentName,
                   const string& courseCode) {
    if (courses.find(courseCode) == courses.end()) {
        cout << "Error: Course does not exist!" << endl;
        return;
    }
    if (students.find(studentId) == students.end()) {
        students[studentId] = Student(studentName, studentId);
    }
    students[studentId].enrollCourse(courseCode);
    cout << "Student enrolled successfully!" << endl;
}

void assignInstructor(int instructorId, const string& instructorName,
                      const string& courseCode) {
    if (courses.find(courseCode) == courses.end()) {
        cout << "Error: Course does not exist!" << endl;
        return;
    }
    if (instructors.find(instructorId) == instructors.end()) {
        instructors[instructorId] = Instructor(instructorName, instructorId);
    }
    instructors[instructorId].assignCourse(courseCode);
    cout << "Instructor assigned successfully!" << endl;
}

void displayData() {
    cout << "Courses:\n";
    for (const auto& [code, name] : courses)
        cout << code << ": " << name << endl;
    cout << "\nStudents:\n";
    for (const auto& [id, student] : students) student.display();
    cout << "\nInstructors:\n";
    for (const auto& [id, instructor] : instructors) instructor.display();
}

void saveData() {
    ofstream courseFile("courses.txt"), studentFile("students.txt"),
        instructorFile("instructors.txt");
    for (const auto& [code, name] : courses)
        courseFile << code << " " << name << endl;
    for (const auto& [id, student] : students)
        studentFile << id << " " << student.getName() << endl;
    for (const auto& [id, instructor] : instructors)
        instructorFile << id << " " << instructor.getName() << endl;
    cout << "Data saved successfully!" << endl;
}

void loadData() {
    ifstream courseFile("courses.txt"), studentFile("students.txt"),
        instructorFile("instructors.txt");
    string code, name;
    while (courseFile >> code >> ws && getline(courseFile, name))
        courses[code] = name;
    int id;
    while (studentFile >> id >> ws && getline(studentFile, name))
        students[id] = Student(name, id);
    while (instructorFile >> id >> ws && getline(instructorFile, name))
        instructors[id] = Instructor(name, id);
    cout << "Data loaded successfully!" << endl;
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Course\n2. Enroll Student\n3. Assign Instructor\n4. "
                "Display Data\n5. Save Data\n6. Load Data\n7. Exit\nEnter your "
                "choice: ";
        cin >> choice;
        if (choice == 1) {
            string code, name;
            cout << "Enter course code: ";
            cin >> code;
            cin.ignore();
            cout << "Enter course name: ";
            getline(cin, name);
            addCourse(code, name);
        } else if (choice == 2) {
            int id;
            string name, course;
            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter course code: ";
            cin >> course;
            enrollStudent(id, name, course);
        } else if (choice == 3) {
            int id;
            string name, course;
            cout << "Enter instructor ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter instructor name: ";
            getline(cin, name);
            cout << "Enter course code: ";
            cin >> course;
            assignInstructor(id, name, course);
        } else if (choice == 4) {
            displayData();
        } else if (choice == 5) {
            saveData();
        } else if (choice == 6) {
            loadData();
        }
    } while (choice != 7);
    return 0;
}

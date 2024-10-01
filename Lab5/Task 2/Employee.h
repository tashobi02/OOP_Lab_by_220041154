#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <cstdlib>
#include <iostream>
#include <string>

#define loop(i, n) for (lli i = 0; i < (n); ++i)
typedef long long int lli;
typedef long double ld;
using namespace std;
class Employee {
   private:
    string name;
    string dob;
    ld salary;

   public:
    Employee() : name("John Doe"), dob("1 January 2002"), salary(10000) {}
    void setName(const string& n) {
        if (n.length() > 2) {
            name = n;
        } else {
            name = "John Doe";
        }
    }
    string getName() const { return name; }
    void setDOB(const string& d) {
        int birthYear = stoi(d.substr(d.find_last_of(' ') + 1));
        if (2024 - birthYear > 18) {
            dob = d;
        } else {
            dob = "1 January 2002";
        }
    }
    string getDOB() const { return dob; }
    void setSalary(ld s) {
        if (s >= 10000 && s <= 100000) {
            salary = s;
        } else {
            salary = 10000;
        }
    }
    ld getSalary() const { return salary; }
    void setInfo() {
        string tempName, tempDOB;
        ld tempSalary;
        cout << "Enter Name: ";
        getline(cin >> ws, tempName);
        setName(tempName);
        cout << "Enter Date of Birth (format: Day Month Year): ";
        getline(cin, tempDOB);
        setDOB(tempDOB);
        cout << "Enter Salary (BDT 10000 to BDT 100000): ";
        cin >> tempSalary;
        setSalary(tempSalary);
    }
    void getInfo() const {
        cout << "Name: " << getName() << std::endl;
        cout << "Date of Birth: " << getDOB() << std::endl;
        cout << "Salary: " << getSalary() << " BDT" << std::endl;
    }
    Employee compareAge(const Employee& e) const {
        int year1 = std::stoi(dob.substr(dob.find_last_of(' ') + 1));
        int year2 =
            std::stoi(e.getDOB().substr(e.getDOB().find_last_of(' ') + 1));
        if (year1 < year2) {
            return *this;
        } else {
            return e;
        }
    }
};

#endif

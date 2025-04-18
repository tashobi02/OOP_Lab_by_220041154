#include <fstream>
#include <iostream>
using namespace std;
class person {
   protected:
    char name[80];
    int age;

   public:
    void getData() {
        cout << "\n   Enter name: ";
        cin >> name;
        cout << "   Enter age: ";
        cin >> age;
    }
    void showData() {
        cout << "\n   Name: " << name;
        cout << "\n   Age: " << age;
    }
};
int main() {
    char ch;
    person pers;
    fstream file;
    file.open("GROUP.DAT", ios::app | ios::out | ios::in | ios::binary);
    do {
        cout << "\nEnter person's data:";
        pers.getData();
        file.write(reinterpret_cast<char *>(&pers), sizeof(pers));
        cout << "Enter another person (y/n)? ";
        cin >> ch;
    } while (ch == 'y');
    file.seekg(0);
    file.read(reinterpret_cast<char *>(&pers), sizeof(pers));
    while (!file.eof()) {
        cout << "\nPerson:";
        pers.showData();
        file.read(reinterpret_cast<char *>(&pers), sizeof(pers));
    }
    cout << endl;
    return 0;
}

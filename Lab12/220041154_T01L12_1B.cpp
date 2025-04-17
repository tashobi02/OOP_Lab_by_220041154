#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Book {
   private:
    string name;
    string author;
    string ISBN;

   public:
    Book(string name, string author, string ISBN) {
        this->name = name;
        this->author = author;
        this->ISBN = ISBN;
    }
    string getName() { return name; }
    string getAuthor() { return author; }
    string getISBN() { return ISBN; }
    void setName(string name) { this->name = name; }
    void setAuthor(string author) { this->author = author; }
    void setISBN(string ISBN) { this->ISBN = ISBN; }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

int main() { return 0; }
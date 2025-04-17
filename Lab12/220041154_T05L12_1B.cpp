#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
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
    string getName() const { return name; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    void setName(string name) { this->name = name; }
    void setAuthor(string author) { this->author = author; }
    void setISBN(string ISBN) { this->ISBN = ISBN; }
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

class Library {
   private:
    vector<Book> books;
    deque<Book> borrowedBooks;
    list<Book> archivedBooks;

   public:
    void addBook(Book book) { books.push_back(book); }
    void borrowBook(int index) {
        borrowedBooks.push_back(books[index]);
        books.erase(books.begin() + index);
    }
    void returnBook(int index) {
        books.push_back(borrowedBooks[index]);
        borrowedBooks.erase(borrowedBooks.begin() + index);
    }
    void archiveBook(int index) {
        archivedBooks.push_back(books[index]);
        books.erase(books.begin() + index);
    }
    void displayBooks() {
        cout << "Inventory: " << books.size() << endl;
        for (int i = 0; i < (int)books.size(); i++) {
            cout << "Book " << i + 1 << endl;
            books[i].display();
        }
        int j = 1;
        cout << "Borrowed: " << borrowedBooks.size() << endl;
        for (const auto& borrowedBook : borrowedBooks) {
            cout << j++ << ". ";
            borrowedBook.display();
            cout << endl;
        }
        j = 1;
        cout << "Archived: " << archivedBooks.size() << endl;
        for (const auto& archivedBook : archivedBooks) {
            cout << j++ << ". ";
            archivedBook.display();
            cout << endl;
        }
    }
    void displayBorrowedBooks() {
        for (int i = 0; i < (int)borrowedBooks.size(); i++) {
            cout << "Borrowed Book " << i + 1 << endl;
            borrowedBooks[i].display();
        }
    }
    void displayArchivedBooks() {
        for (list<Book>::iterator it = archivedBooks.begin();
             it != archivedBooks.end(); it++) {
            cout << "Archived Book" << endl;
            it->display();
        }
    }
    void addNewBook() {
        string name, author, ISBN;
        cin.ignore();
        cout << "Enter name: " << endl;
        getline(cin, name);
        cout << "Enter author: " << endl;
        getline(cin, author);
        cout << "Enter ISBN: " << endl;
        getline(cin, ISBN);
        Book book(name, author, ISBN);
        addBook(book);
    }
    void saveData() {
        ofstream file1("inventory.txt");
        ofstream file2("borrowed.txt");
        ofstream file3("archived.txt");
        if (!file1.is_open() || !file2.is_open() || !file3.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }
        for (const auto& book : books) {
            file1 << book.getName() << "," << book.getAuthor() << ","
                  << book.getISBN() << endl;
        }
        for (const auto& book : borrowedBooks) {
            file2 << book.getName() << "," << book.getAuthor() << ","
                  << book.getISBN() << endl;
        }
        for (const auto& book : archivedBooks) {
            file3 << book.getName() << "," << book.getAuthor() << ","
                  << book.getISBN() << endl;
        }
        file1.close();
        file2.close();
        file3.close();
    }

    void loadData() {
        ifstream file1("inventory.txt");
        ifstream file2("borrowed.txt");
        ifstream file3("archived.txt");
        string line, name, author, ISBN;
        books.clear();
        borrowedBooks.clear();
        archivedBooks.clear();
        while (getline(file1, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, author, ',');
            getline(ss, ISBN, ',');
            books.push_back(Book(name, author, ISBN));
        }
        while (getline(file2, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, author, ',');
            getline(ss, ISBN, ',');
            borrowedBooks.push_back(Book(name, author, ISBN));
        }
        while (getline(file3, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, author, ',');
            getline(ss, ISBN, ',');
            archivedBooks.push_back(Book(name, author, ISBN));
        }
    }
};

int main() {
    Library library;
    // Book book1("Book1", "Author1", "ISBN1");
    // Book book2("Book2", "Author2", "ISBN2");
    // Book book3("Book3", "Author3", "ISBN3");
    int x;
    // library.addBook(book1);
    // library.addBook(book2);
    // library.addBook(book3);
    // library.displayBooks();
    // library.borrowBook(1);
    // library.displayBooks();
    // library.displayBorrowedBooks();
    // library.returnBook(0);
    // library.displayBooks();
    // library.displayBorrowedBooks();
    // library.archiveBook(0);
    // library.displayBooks();
    // library.displayArchivedBooks();
    while (true) {
        cout << "1. Add book " << endl;
        cout << "2. Borrow book " << endl;
        cout << "3. Return book " << endl;
        cout << "4. Archive book " << endl;
        cout << "5. Display books " << endl;
        cout << "6. Save Data " << endl;
        cout << "7. Load Data " << endl;
        cout << "8. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> x;
        if (x == 8)
            break;
        else {
            if (x == 1) {
                library.addNewBook();
            } else if (x == 2) {
                int index;
                cout << "Enter index: ";
                cin >> index;
                library.borrowBook(index);
            } else if (x == 3) {
                int index;
                cout << "Enter index: ";
                cin >> index;
                library.returnBook(index);
            } else if (x == 4) {
                int index;
                cout << "Enter index: ";
                cin >> index;
                library.archiveBook(index);
            } else if (x == 5) {
                library.displayBooks();
            } else if (x == 6) {
                library.saveData();
            } else if (x == 7) {
                library.loadData();
            }
        }
        cout << endl;
    }
    return 0;
}
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
        for (int i = 0; i < (int)books.size(); i++) {
            cout << "Book " << i + 1 << endl;
            books[i].display();
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
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter author: ";
        cin >> author;
        cout << "Enter ISBN: ";
        cin >> ISBN;
        Book book(name, author, ISBN);
        addBook(book);
    }
};

int main() {
    Library library;
    Book book1("Book1", "Author1", "ISBN1");
    Book book2("Book2", "Author2", "ISBN2");
    Book book3("Book3", "Author3", "ISBN3");
    int x;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.displayBooks();
    library.borrowBook(1);
    library.displayBooks();
    library.displayBorrowedBooks();
    library.returnBook(0);
    library.displayBooks();
    library.displayBorrowedBooks();
    library.archiveBook(0);
    library.displayBooks();
    library.displayArchivedBooks();
    cout << "1. Add book " << endl;
    cout << "2. Borrow book " << endl;
    cout << "3. Return book " << endl;
    cout << "4. Archive book " << endl;
    cout << "5. Display books " << endl;
    cout << "6. Exit " << endl;
    cout << "Enter your choice: ";
    while (true) {
        cin >> x;
        if (x == 6)
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
            }
        }
    }
    return 0;
}
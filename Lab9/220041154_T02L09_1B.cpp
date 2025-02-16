#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

enum class CoverType { Hardcover, Paperback };

class LibraryResource {
   private:
    string title;
    string author;
    int price;

   public:
    LibraryResource(string t, string a, int p)
        : title(t), author(a), price(p) {}

    void resourceDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    int getPrice() const { return price; }
};

class Book : public LibraryResource {
   private:
    CoverType coverType;

   public:
    Book(string t, string a, int p, CoverType c)
        : LibraryResource(t, a, p), coverType(c) {}

    void resourceDetails() const {
        LibraryResource::resourceDetails();
        cout << "Cover Type: "
             << (coverType == CoverType::Hardcover ? "Hardcover" : "Paperback")
             << endl;
    }
};

class EBook : public LibraryResource {
   private:
    double fileSize;

   public:
    EBook(string t, string a, int p, double f)
        : LibraryResource(t, a, p), fileSize(f) {}

    void resourceDetails() const {
        LibraryResource::resourceDetails();
        cout << "File Size: " << fileSize << " MB" << endl;
    }
};

class AudioBook : public LibraryResource {
   private:
    int minutes;

   public:
    AudioBook(string t, string a, int p, int d)
        : LibraryResource(t, a, p), minutes(d) {}

    void resourceDetails() const {
        LibraryResource::resourceDetails();
        cout << "Duration: " << minutes << " minutes" << endl;
    }
};

int main() {
    LibraryResource* resource_list[100];

    /* TASK 1: Objects creation */
    resource_list[0] =
        new Book("The Alchemist", "Paulo Coelho", 500, CoverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new AudioBook("Becoming", "Michelle Obama", 700, 120);

    /* TASK 2: Display details */
    for (int i = 0; i < 3; i++) {
        resource_list[i]->resourceDetails();
        cout << endl;
    }
}
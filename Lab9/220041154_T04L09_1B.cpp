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
    int no_of_copies;

   public:
    LibraryResource(string t, string a, int p, int copies = 1)
        : title(t), author(a), price(p), no_of_copies(copies) {}

    void setNoOfCopies(int copies) {
        if (copies > 0)
            no_of_copies = copies;
        else
            cout << "Invalid number of copies. Must be positive." << endl;
    }

    int getNoOfCopies() const { return no_of_copies; }

    void resourceDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "No. of Copies: " << no_of_copies << endl;
    }

    int getPrice() const { return price; }
};

class Book : public LibraryResource {
   private:
    CoverType coverType;

   public:
    Book(string t, string a, int p, CoverType c, int copies = 1)
        : LibraryResource(t, a, p, copies), coverType(c) {}

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
    EBook(string t, string a, int p, double f, int copies = 1)
        : LibraryResource(t, a, p, copies), fileSize(f) {}

    void resourceDetails() const {
        LibraryResource::resourceDetails();
        cout << "File Size: " << fileSize << " MB" << endl;
    }
};

class AudioBook : public LibraryResource {
   private:
    int minutes;

   public:
    AudioBook(string t, string a, int p, int d, int copies = 1)
        : LibraryResource(t, a, p, copies), minutes(d) {}

    void resourceDetails() const {
        LibraryResource::resourceDetails();
        cout << "Duration: " << minutes << " minutes" << endl;
    }
};

void sort_resources_price(LibraryResource** resources, int n) {
    sort(resources, resources + n, [](LibraryResource* a, LibraryResource* b) {
        return a->getPrice() < b->getPrice();
    });
}

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

    /* TASK 3: Setting the number of copies */
    resource_list[0]->setNoOfCopies(50);
    resource_list[1]->setNoOfCopies(5);
    resource_list[2]->setNoOfCopies(1);

    for (int i = 0; i < 3; i++) {
        resource_list[i]->resourceDetails();
        cout << endl;
    }

    /* TASK 4: Creating more resources and sorting */
    resource_list[3] =
        new Book("Sapiens", "Yuval Noah Harari", 1000, CoverType::Paperback);
    resource_list[4] = new EBook("Digital Minimalism", "Cal Newport", 400, 3.2);
    resource_list[5] = new AudioBook("Atomic Habits", "James Clear", 1200, 180);
    resource_list[6] =
        new Book("Dune", "Frank Herbert", 800, CoverType::Hardcover);
    resource_list[7] = new EBook("The Subtle Art of Not Giving a F*ck",
                                 "Mark Manson", 350, 1.8);
    resource_list[8] = new AudioBook("Educated", "Tara Westover", 600, 150);
    resource_list[9] = new Book("Harry Potter and the Philosopher's Stone",
                                "J.K. Rowling", 450, CoverType::Paperback);

    cout << "Before Sorting:" << endl;
    for (int i = 0; i < 10; i++) {
        resource_list[i]->resourceDetails();
        cout << endl;
    }

    sort_resources_price(resource_list, 10);

    cout << "After Sorting by Price:" << endl;
    for (int i = 0; i < 10; i++) {
        resource_list[i]->resourceDetails();
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        delete resource_list[i];
    }

    return 0;
}
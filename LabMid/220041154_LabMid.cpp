#include <iostream>
#include <string>

using namespace std;

class Laptop {
   private:
    string model;
    double price;
    string manufacturer;

   public:
    Laptop() {
        model = "Yoga";
        price = 1600.00;
        manufacturer = "Lenovo";
    }

    void setter() {
        string md;
        double p;
        string mn;
        cin >> md >> p >> mn;
        model = md;
        price = p;
        manufacturer = mn;
    }

    string getter() {
        return model + "-" + to_string(price) + " " + manufacturer;
    }

    void display() const {
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }

    static void sortByManufacturer(Laptop lpt[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (lpt[j].manufacturer[0] < lpt[i].manufacturer[0]) {
                    swap(lpt[i], lpt[j]);
                }
            }
        }
    }
};

int main() {
    Laptop lpt[10];
    for (int i = 0; i < 3; i++) {
        lpt[i].setter();
    }
    cout << "Before sorting: " << endl;
    for (int i = 0; i < 3; i++) {
        lpt[i].display();
    }

    Laptop::sortByManufacturer(lpt, 10);

    cout << "After sorting: " << endl;
    for (int i = 0; i < 10; i++) {
        lpt[i].display();
    }
}

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Animal_Classes.h"

using namespace std;

int main() {
    Cow cow("Hamba", "Dhaka", 200, 10, 25.0);

    cow.displayInformation();
    cow.make_sound();
    cout << "Milk Production: " << cow.getMilkProduction() << " liters" << endl;

    Chicken chicken("Tutturu", "Moiran", 3, 1, 3);
    chicken.make_sound();
    cout << "Daily Egg Count: " << chicken.getEggCount() << endl;
    chicken.displayInformation();

    PetCat petCat("Oreo", "CDS", 4, 1);
    petCat.displayInformation();
    petCat.make_sound();
    return 0;
}

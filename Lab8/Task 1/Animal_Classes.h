#ifndef ANIMAL_CLASSES
#define ANIMAL_CLASSES

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

class Animal {
   private:
    string nameOfAnimal;
    string habitat_Area;
    string sound;
    int weight;
    int height;

   public:
    Animal(string nA, string hA, string so, int w, int h)
        : nameOfAnimal(nA), habitat_Area(hA), sound(so), weight(w), height(h) {}

    void displayInformation() const {
        cout << "Animal Summary:" << endl;
        cout << "Name: " << nameOfAnimal << endl;
        cout << "Habitat Area: " << habitat_Area << endl;
        cout << "Weight: " << weight << endl;
        cout << "Height: " << height << endl;
    }

    void changeWeight(int _weight) { weight = _weight; }

    void make_sound() const { cout << sound << endl; }

   protected:
    void setSound(const string& newSound) { sound = newSound; }
};

class Cow : public Animal {
   private:
    double milkProductionInLiters;

   public:
    Cow(string nA, string hA, int w, int h, double mpl)
        : Animal(nA, hA, "moo", w, h), milkProductionInLiters(mpl) {
        setSound("moo.");
    }

    void make_sound() const {
        cout << "The cow says: ";
        Animal::make_sound();
    }

    double getMilkProduction() const { return milkProductionInLiters; }
};

class Chicken : protected Animal {
   private:
    int dailyEggCount;

   public:
    Chicken(string nA, string hA, int w, int h, int eggCount)
        : Animal(nA, hA, "buck buck", w, h), dailyEggCount(eggCount) {
        setSound("buck buck.");
    }

    void make_sound() const {
        cout << "The chicken says: ";
        Animal::make_sound();
    }

    void displayInformation() const { Animal::displayInformation(); }

    int getEggCount() const { return dailyEggCount; }
};

class Cat : private Animal {
   public:
    Cat(string nA, string hA, int w, int h) : Animal(nA, hA, "meow", w, h) {
        setSound("meow.");
    }

    void make_sound() const {
        cout << "The cat says: ";
        Animal::make_sound();
    }

    void displayInformation() const { Animal::displayInformation(); }
};

class PetCat : public Cat {
   private:
    string petName;

   public:
    PetCat(string nA, string hA, int w, int h)
        : Cat(nA, hA, w, h), petName(nA) {}

    void make_sound() const {
        cout << petName << " ";
        Cat::make_sound();
    }
    void displayInformation() const { Cat::displayInformation(); }
};

#endif

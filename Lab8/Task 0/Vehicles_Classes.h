#ifndef CLASSES_H
#define CLASSES_H
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
   protected:
    string licensePlate;
    string manufacturer;
    int carriageSizeLimit;

   public:
    Vehicle(string lp, string m, int cs)
        : licensePlate(lp), manufacturer(m), carriageSizeLimit(cs) {}

    void displayInfo() const {
        cout << "Vehicle - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit << " kg" << endl;
    }

    void performMaintenance() const {
        cout << "General vehicle maintenance." << endl;
    }
};

class GasolineVehicle : public Vehicle {
   protected:
    int fuelTankCapacity;
    string fuelType;

   public:
    GasolineVehicle(string lp, string m, int cs, int fc, string ft)
        : Vehicle(lp, m, cs), fuelTankCapacity(fc), fuelType(ft) {}

    void displayInfo() const {
        cout << "Gasoline Vehicle - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType << endl;
    }

    void performMaintenance() const {
        cout << "Gasoline Vehicle - maintenance" << endl;
    }
};

class Motorcycle : public GasolineVehicle {
   public:
    Motorcycle(string lp, string m, int cs, int fc, string ft)
        : GasolineVehicle(lp, m, cs, fc, ft) {}

    void displayInfo() const {
        cout << "Motorcycle - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType << endl;
    }

    void performMaintenance() const {
        cout << "Motorcycle - maintenance" << endl;
    }
};

class Car : public GasolineVehicle {
   private:
    int passengerCapacity;

   public:
    Car(string lp, string m, int cs, int fc, string ft, int pc)
        : GasolineVehicle(lp, m, cs, fc, ft), passengerCapacity(pc) {}

    void displayInfo() const {
        cout << "Car - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType
             << ", Passenger Capacity: " << passengerCapacity << endl;
    }

    void performMaintenance() const { cout << "Car - maintenance" << endl; }
};

class Truck : public GasolineVehicle {
   private:
    int cargoCapacity;

   public:
    Truck(string lp, string m, int cs, int fc, string ft, int cc)
        : GasolineVehicle(lp, m, cs, fc, ft), cargoCapacity(cc) {}

    void displayInfo() const {
        cout << "Truck - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType
             << ", Cargo Capacity: " << cargoCapacity << " kg" << endl;
    }

    void performMaintenance() const { cout << "Truck - maintenance" << endl; }
};

class ElectricVehicle : public Vehicle {
   private:
    int batteryCapacity;
    int chargingTime;

   public:
    ElectricVehicle(string lp, string m, int cs, int bc, int ct)
        : Vehicle(lp, m, cs), batteryCapacity(bc), chargingTime(ct) {}

    void displayInfo() const {
        cout << "Electric Vehicle - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Battery Capacity: " << batteryCapacity
             << " KWh, Charging Time: " << chargingTime << " minutes" << endl;
    }

    void performMaintenance() const {
        cout << "Electric Vehicle - maintenance" << endl;
    }
};

class HybridVehicle : public GasolineVehicle {
   private:
    int batteryCapacity;
    int chargingTime;
    float energyRegenEfficiency;

   public:
    HybridVehicle(string lp, string m, int cs, int fc, string ft, int bc,
                  int ct, float ere)
        : GasolineVehicle(lp, m, cs, fc, ft),
          batteryCapacity(bc),
          chargingTime(ct),
          energyRegenEfficiency(ere) {}

    void displayInfo() const {
        cout << "Hybrid Vehicle - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType
             << ", Battery Capacity: " << batteryCapacity
             << " KWh, Charging Time: " << chargingTime
             << " minutes, Energy Regen Efficiency: " << energyRegenEfficiency
             << endl;
    }

    void performMaintenance() const {
        cout << "Hybrid Vehicle - maintenance" << endl;
    }
};

#endif

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Vehicles_Classes.h"


int main() {
    Motorcycle motorcycle("MC123", "Yamaha", 150, 10, "Petrol");
    Car car("CAR456", "Toyota", 1200, 40, "Petrol", 5);
    Truck truck("TRK789", "Volvo", 8000, 200, "Diesel", 5000);
    ElectricVehicle electricVehicle("EV101", "Tesla", 500, 100, 60);
    HybridVehicle hybridVehicle("HYB202", "Toyota", 1000, 50, "Petrol", 120, 45,
                                0.85);

    motorcycle.displayInfo();
    motorcycle.performMaintenance();

    car.displayInfo();
    car.performMaintenance();

    truck.displayInfo();
    truck.performMaintenance();

    electricVehicle.displayInfo();
    electricVehicle.performMaintenance();

    hybridVehicle.displayInfo();
    hybridVehicle.performMaintenance();

    return 0;
}
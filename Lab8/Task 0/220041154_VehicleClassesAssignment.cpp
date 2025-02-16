#include <iostream>
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

    virtual ~Vehicle() {
        cout << "Destroying Vehicle: " << licensePlate << endl;
    }

    virtual void displayInfo() const = 0;
    virtual void performMaintenance() const = 0;
};

class GasolineVehicle : public virtual Vehicle {
   protected:
    int fuelTankCapacity;
    string fuelType;

   public:
    GasolineVehicle(string lp, string m, int cs, int fc, string ft)
        : Vehicle(lp, m, cs), fuelTankCapacity(fc), fuelType(ft) {}

    virtual ~GasolineVehicle() {
        cout << "Destroying GasolineVehicle: " << licensePlate << endl;
    }
};

class Motorcycle : public GasolineVehicle {
   public:
    Motorcycle(string lp, string m, int cs, int fc, string ft)
        : GasolineVehicle(lp, m, cs, fc, ft) {}

    void displayInfo() const override {
        cout << "Motorcycle - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType << endl;
    }

    void performMaintenance() const override {
        cout << "Motorcycle maintenance complete." << endl;
    }
};

class Car : public GasolineVehicle {
   private:
    int passengerCapacity;

   public:
    Car(string lp, string m, int cs, int fc, string ft, int pc)
        : GasolineVehicle(lp, m, cs, fc, ft), passengerCapacity(pc) {}

    void displayInfo() const override {
        cout << "Car - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType
             << ", Passenger Capacity: " << passengerCapacity << endl;
    }

    void performMaintenance() const override {
        cout << "Car maintenance complete." << endl;
    }
};

class Truck : public GasolineVehicle {
   private:
    int cargoCapacity;

   public:
    Truck(string lp, string m, int cs, int fc, string ft, int cc)
        : GasolineVehicle(lp, m, cs, fc, ft), cargoCapacity(cc) {}

    void displayInfo() const override {
        cout << "Truck - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Fuel Capacity: " << fuelTankCapacity
             << " liters, Fuel Type: " << fuelType
             << ", Cargo Capacity: " << cargoCapacity << " kg" << endl;
    }

    void performMaintenance() const override {
        cout << "Truck maintenance complete." << endl;
    }
};

class ElectricVehicle : public virtual Vehicle {
   private:
    int batteryCapacity;
    int chargingTime;

   public:
    ElectricVehicle(string lp, string m, int cs, int bc, int ct)
        : Vehicle(lp, m, cs), batteryCapacity(bc), chargingTime(ct) {}

    void displayInfo() const override {
        cout << "Electric Vehicle - License Plate: " << licensePlate
             << ", Manufacturer: " << manufacturer
             << ", Carriage Size: " << carriageSizeLimit
             << " kg, Battery Capacity: " << batteryCapacity
             << " KWh, Charging Time: " << chargingTime << " minutes" << endl;
    }

    void performMaintenance() const override {
        cout << "Electric Vehicle maintenance complete." << endl;
    }
};

class Branch {
   private:
    vector<const Vehicle*> vehicles;

   public:
    void addVehicle(const Vehicle* v) { vehicles.push_back(v); }

    void maintenance_all_vehicle() const {
        for (const auto& vehicle : vehicles) {
            vehicle->performMaintenance();
        }
    }

    ~Branch() {
        for (const auto& vehicle : vehicles) {
            delete vehicle;
        }
    }
};

int main() {
    Branch branch;

    branch.addVehicle(new Motorcycle("MC123", "Yamaha", 150, 10, "Petrol"));
    branch.addVehicle(new Car("CAR456", "Toyota", 1200, 40, "Petrol", 5));
    branch.addVehicle(new Truck("TRK789", "Volvo", 8000, 200, "Diesel", 5000));
    branch.addVehicle(new ElectricVehicle("EV101", "Tesla", 500, 100, 60));

    branch.maintenance_all_vehicle();

    return 0;
}

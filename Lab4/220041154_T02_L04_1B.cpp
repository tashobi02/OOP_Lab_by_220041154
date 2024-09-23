#include <iostream>
typedef long long int lli;
typedef long double ld;
#define loop(i, n) for (lli i = 0; i < (n); i++)
#define endl "\n"
using namespace std;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
class Flight {
   private:
    lli flight_number;
    string destination;
    ld distance;
    ld max_fuel_capacity;

   public:
    CalFuel(ld distance, ld max_fuel_capacity) {
        bool valid = false;
        if (distance <= 1000 && max_fuel_capacity >= 500)
            valid = true;
        else if ((distance > 1000 || distance <= 2000) &&
                 max_fuel_capacity <= 1100)
            valid = true;
        else if (distance > 2000 && max_fuel_capacity >= 2200)
            valid = true;
        return valid;
    }
    void FeedInfo() {
        lli fn;
        string dest;
        ld dist;
        ld mfc;
        cout << "Enter Flight Number: ";
        cin >> fn;
        flight_number = fn;
        cout << endl << "Enter Destination: ";
        cin >> dest;
        destination = dest;
        cout << endl << "Enter Distance: ";
        cin >> dist;
        distance = dist;
        cout << endl << "Max Fuel Capacity: ";
        cin >> mfc;
        max_fuel_capacity = mfc;
    }
    void ShowInfo() {
        cout << "Flight Number: " << flight_number << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << distance << endl;
        cout << "Max Fuel Capacity: " << max_fuel_capacity << endl;
        bool valid = CalFuel(distance, max_fuel_capacity);
        if (valid)
            cout << "Fuel Capacity is fit enough for this flight distance ";
        else
            cout << "Not sufficient Fuel Capacity for this flight.";
        cout << endl;
    }
};
int main() {
    Flight f1;
    f1.FeedInfo();
    f1.ShowInfo();
}

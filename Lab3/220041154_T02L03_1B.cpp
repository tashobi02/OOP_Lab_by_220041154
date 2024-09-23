#include <cmath>
#include <iostream>
using namespace std;
typedef long long int lli;
typedef long double ld;
#define loop(i, n) for (lli i = 0; i < (n); i++)
#define endl "\n"
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
class Temperature {
   private:
    ld value;
    string unit;
    bool isValidUnit(const string& u) {
        return (u == "Celsius" || u == "Fahrenheit" || u == "Kelvin");
    }
   public:
    void assign(ld tempValue, const string& tempUnit) {
        if (!isValidUnit(tempUnit)) {
            cout << "Invalid unit! Only Celsius, Fahrenheit, or Kelvin are "
                    "allowed."
                 << endl;
            return;
        }
        ld celsiusValue;
        if (tempUnit == "Fahrenheit") {
            celsiusValue = (tempValue - 32) * 5 / 9;
        } else if (tempUnit == "Kelvin") {
            celsiusValue = tempValue - 273.15;
        } else {
            celsiusValue = tempValue;
        }
        if (celsiusValue < -273.15) {
            cout << "Temperature cannot be below absolute zero (-273.15 C or 0 "
                    "K)."
                 << endl;
            return;
        }
        value = tempValue;
        unit = tempUnit;
    }
    ld convert(const string& targetUnit) {
        if (!isValidUnit(targetUnit)) {
            cout << "Invalid target unit! Only Celsius, Fahrenheit, or Kelvin "
                    "are allowed."
                 << endl;
            return NAN;
        }
        ld convertedValue;
        if (unit == "Celsius") {
            if (targetUnit == "Fahrenheit") {
                convertedValue = (value * 9 / 5) + 32;
            } else if (targetUnit == "Kelvin") {
                convertedValue = value + 273.15;
            } else {
                convertedValue = value;
            }
        } else if (unit == "Fahrenheit") {
            ld celsiusValue = (value - 32) * 5 / 9;
            if (targetUnit == "Celsius") {
                convertedValue = celsiusValue;
            } else if (targetUnit == "Kelvin") {
                convertedValue = celsiusValue + 273.15;
            } else {
                convertedValue = value;
            }
        } else if (unit == "Kelvin") {
            ld celsiusValue = value - 273.15;
            if (targetUnit == "Celsius") {
                convertedValue = celsiusValue;
            } else if (targetUnit == "Fahrenheit") {
                convertedValue = (celsiusValue * 9 / 5) + 32;
            } else {
                convertedValue = value;
            }
        }
        return convertedValue;
    }
    void print() const {
        cout << "The temperature is " << value << " " << unit << "." << endl;
    }
};
int main() {
    fast();
    Temperature temp;
    temp.assign(100, "Celsius");
    temp.print();
    cout << "In Fahrenheit: " << temp.convert("Fahrenheit") << "F" << endl;
    cout << "In Kelvin: " << temp.convert("Kelvin") << "K" << endl;
    temp.assign(200, "Invalid Unit");
    temp.assign(-300, "Celsius");
    return 0;
}

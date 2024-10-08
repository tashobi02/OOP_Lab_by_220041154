#include "Celsius.h"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;

celsius::celsius() : temp_c(0) {}
celsius::celsius(ld temp) { assign(temp); }
void celsius::assign(ld temp) {
    if (temp < -273.15) {
        cerr << "Error! Given temperature is below absolute zero" << endl;
        return;
    }
    temp_c = temp;
}
void celsius::display() const {
    cout << "The temperature is " << temp_c << " Celsius." << endl;
}
celsius::operator fahrenheit() const {
    ld temp_f = (temp_c * 9) / 5 + 32;
    return fahrenheit(temp_f);
}
celsius::operator kelvin() const {
    ld temp_k = temp_c + 273.15;
    return kelvin(temp_k);
}

#include "Kelvin.h"

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

kelvin::kelvin() : temp_k(0) {}
kelvin::kelvin(ld temp) { assign(temp); }
void kelvin::assign(ld temp) {
    if (temp < 0) {
        cerr << "Error! Given temperature is below absolute zero" << endl;
        return;
    }
    temp_k = temp;
}
void kelvin::display() const {
    cout << "The temperature is " << temp_k << " Kelvin." << endl;
}
kelvin::operator fahrenheit() const {
    ld temp_f = ((temp_k - 273.15) * 9) / 5 + 32;
    return fahrenheit(temp_f);
}
kelvin::operator celsius() const {
    ld temp_c = temp_k - 273.15;
    return celsius(temp_c);
}

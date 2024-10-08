#include "Fahrenheit.h"

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

fahrenheit::fahrenheit() : temp_f(0) {}
fahrenheit::fahrenheit(ld temp) { assign(temp); }
void fahrenheit::assign(ld temp) {
    if (temp < -459.67) {
        cerr << "Error! Given temperature is below absolute zero" << endl;
        return;
    }
    temp_f = temp;
}
void fahrenheit::display() const {
    cout << "The temperature is " << temp_f << " Fahrenheit." << endl;
}
fahrenheit::operator celsius() const {
    ld temp_c = (temp_f - 32) * 5 / 9;
    return celsius(temp_c);
}
fahrenheit::operator kelvin() const {
    ld temp_k = ((temp_f - 32) * 5 / 9) + 273.15;
    return kelvin(temp_k);
}

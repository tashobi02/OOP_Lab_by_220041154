#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Celsius.h"
#include "Kelvin.h"

using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;

class celsius;
class kelvin;

class fahrenheit {
   private:
    ld temp_f;

   public:
    fahrenheit();
    fahrenheit(ld temp);
    void assign(ld temp);
    void display() const;
    operator kelvin() const;
    operator celsius() const;
};

#endif

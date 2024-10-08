#ifndef KELVIN_H
#define KELVIN_H

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Celsius.h"
#include "Fahrenheit.h"
using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;

class celsius;
class fahrenheit;

class kelvin {
   private:
    ld temp_k;

   public:
    kelvin();
    kelvin(ld temp);
    void assign(ld temp);
    void display() const;
    operator celsius() const;
    operator fahrenheit() const;
};

#endif

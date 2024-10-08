#ifndef CELCIUS_H
#define CELCIUS_H

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Fahrenheit.h"
#include "Kelvin.h"

using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;

class kelvin;
class fahrenheit;

class celsius {
   private:
    ld temp_c;

   public:
    celsius();
    celsius(ld temp);
    void assign(ld temp);
    void display() const;
    operator kelvin() const;
    operator fahrenheit() const;
};

#endif

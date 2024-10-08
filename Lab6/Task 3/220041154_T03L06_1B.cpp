#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"

using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;
int main() {
    celsius c1(35);
    kelvin k1(10);
    fahrenheit f1;
    c1.display();
    k1 = c1;
    f1 = c1;
    k1.display();
    f1.display();
    return 0;
}

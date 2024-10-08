#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Counter.h"

using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;

int main() {
    Counter c1, c2, c3;
    c1.setIncrementStep(2);
    c1.increment();
    cout << "c1 count after increment: " << c1.getCount() << endl;

    c2.setIncrementStep(2);
    c2.increment();
    cout << "c2 count after increment: " << c2.getCount() << endl;

    c3 = c1 + c2;
    cout << "c3 count after addition: " << c3.getCount() << endl;
    return 0;
}

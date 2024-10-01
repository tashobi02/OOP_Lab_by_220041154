#include <cstdlib>  // for std::stoi
#include <iostream>
#include <string>

#include "Employee.h"

#define loop(i, n) for (lli i = 0; i < (n); ++i)
typedef long long int lli;
typedef long double ld;
int main() {
    Employee e1, e2;
    e1.setInfo();
    e2.setInfo();
    cout << "Employee 1 Information: " << endl;
    e1.getInfo();
    cout << endl;
    cout << "Employee 2 Information: " << endl;
    e2.getInfo();
    cout << endl;
    Employee elder = e1.compareAge(e2);
    cout << "The elder employee is: " << elder.getName() << endl;
    return 0;
}

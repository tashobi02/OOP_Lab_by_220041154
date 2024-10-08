#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Coordinate.h"

using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;

void randomAssignment(Coordinate c[], lli size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(-100.0, 100.0);
    loop(i, size) {
        ld x = dist(gen);
        ld y = dist(gen);
        c[i].setValues(x, y);
    }
}

void Sort(Coordinate c[], lli size) {
    vector<pair<ld, lli>> cords(size);
    loop(i, size) {
        cords[i].first = c[i].getDistance();
        cords[i].second = i;
    }

    sort(cords.begin(), cords.end());

    loop(i, size) {
        c[cords[i].second].display();
        cout << " " << cords[i].first << endl;
    }
}

int main() {
    Coordinate coord[10];
    randomAssignment(coord, 10);

    cout << "Before sorting: " << endl;
    loop(i, 10) {
        coord[i].display();
        cout << " " << coord[i].getDistance() << endl;
    }

    cout << "After sorting: " << endl;
    Sort(coord, 10);

    return 0;
}

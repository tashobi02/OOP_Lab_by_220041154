#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>
#include <iostream>


using namespace std;
#define loop(i, n) for (lli i = 0; i < (n); ++i)
#define endl "\n"
typedef long long int lli;
typedef long double ld;

class Coordinate {
   private:
    ld abscissa;
    ld ordinate;

   public:
    Coordinate();
    Coordinate(ld x, ld y);
    ~Coordinate();

    void setValues(ld x, ld y);
    void display() const;
    ld operator-(const Coordinate& c) const;
    ld getDistance() const;
    void move_x(ld val);
    void move_y(ld val);
    void move(ld x_val, ld y_val);
    bool operator==(const Coordinate& c) const;
    bool operator!=(const Coordinate& c) const;
    bool operator>(const Coordinate& c) const;
    bool operator<(const Coordinate& c) const;
    bool operator>=(const Coordinate& c) const;
    bool operator<=(const Coordinate& c) const;
};

#endif

#include "Coordinate.h"

Coordinate::Coordinate() : abscissa(0), ordinate(0) {}

Coordinate::Coordinate(ld x, ld y) : abscissa(x), ordinate(y) {}

Coordinate::~Coordinate() {}

void Coordinate::setValues(ld x, ld y) {
    abscissa = x;
    ordinate = y;
}

void Coordinate::display() const {
    cout << "(" << abscissa << ", " << ordinate << ")" << endl;
}

ld Coordinate::operator-(const Coordinate& c) const {
    ld dx = abscissa - c.abscissa;
    ld dy = ordinate - c.ordinate;
    return sqrt(dx * dx + dy * dy);
}

ld Coordinate::getDistance() const {
    return sqrt(abscissa * abscissa + ordinate * ordinate);
}

void Coordinate::move_x(ld val) { abscissa += val; }

void Coordinate::move_y(ld val) { ordinate += val; }

void Coordinate::move(ld x_val, ld y_val) {
    abscissa += x_val;
    ordinate += y_val;
}

bool Coordinate::operator==(const Coordinate& c) const {
    return getDistance() == c.getDistance();
}

bool Coordinate::operator!=(const Coordinate& c) const {
    return getDistance() != c.getDistance();
}

bool Coordinate::operator>(const Coordinate& c) const {
    return getDistance() > c.getDistance();
}

bool Coordinate::operator<(const Coordinate& c) const {
    return getDistance() < c.getDistance();
}

bool Coordinate::operator>=(const Coordinate& c) const {
    return getDistance() >= c.getDistance();
}

bool Coordinate::operator<=(const Coordinate& c) const {
    return getDistance() <= c.getDistance();
}

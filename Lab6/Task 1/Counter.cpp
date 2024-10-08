#include "Counter.h"

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
Counter::Counter() : count(0), steps(1) {}

void Counter::setIncrementStep(lli step_val) {
    if (count == 0 && step_val > 0) {
        steps = step_val;
    }
}

lli Counter::getCount() const { return count; }

void Counter::increment() { count += steps; }

void Counter::resetCount(long long step) {
    count = 0;
    steps = step > 0 ? step : 1;
}

Counter Counter::operator+(const Counter& cc) const {
    Counter result;
    if (steps == cc.steps) {
        result.count = count + cc.count;
        result.steps = steps;
    } else {
        cout << "Increment steps are not the same." << endl;
    }
    return result;
}

bool Counter::operator==(const Counter& cc) const { return count == cc.count; }

bool Counter::operator!=(const Counter& cc) const { return count != cc.count; }

bool Counter::operator>(const Counter& cc) const { return count > cc.count; }

bool Counter::operator<(const Counter& cc) const { return count < cc.count; }

bool Counter::operator>=(const Counter& cc) const { return count >= cc.count; }

bool Counter::operator<=(const Counter& cc) const { return count <= cc.count; }

Counter& Counter::operator+=(const Counter& cc) {
    count += cc.count;
    steps = max(steps, cc.steps);
    return *this;
}

Counter Counter::operator++(int) {
    Counter temp = *this;
    increment();
    return temp;
}

Counter& Counter::operator++() {
    increment();
    return *this;
}

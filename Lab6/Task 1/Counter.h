#ifndef COUNTER_H
#define COUNTER_H

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

class Counter {
   private:
    lli count;
    lli steps;

   public:
    Counter();
    void setIncrementStep(lli step_val);
    lli getCount() const;
    void increment();
    void resetCount(long long step = 1);
    Counter operator+(const Counter& cc) const;
    bool operator==(const Counter& cc) const;
    bool operator!=(const Counter& cc) const;
    bool operator>(const Counter& cc) const;
    bool operator<(const Counter& cc) const;
    bool operator>=(const Counter& cc) const;
    bool operator<=(const Counter& cc) const;
    Counter& operator+=(const Counter& cc);
    Counter operator++(int);
    Counter& operator++();
};

#endif

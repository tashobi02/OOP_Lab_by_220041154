#include <iostream>
using namespace std;
class Counter {
   private:
    int ct;
    int incrementStep;

   public:
    Counter() {
        ct = 0;
        incrementStep = 1;
    }
    void setIncrementStep(int step) { incrementStep = step; }
    int getCount() const { return ct; }
    void increment() { ct += incrementStep; }
    void resetCount() { ct = 0; }
};
int main() {
    Counter m1;
    m1.setIncrementStep(5);
    m1.increment();
    m1.increment();
    cout << "Current Count: " << m1.getCount() << endl;
    m1.resetCount();
    cout << "Count after reset: " << m1.getCount() << endl;
    return 0;
}
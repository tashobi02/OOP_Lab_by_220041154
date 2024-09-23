#include <iostream>
typedef long long int lli;
typedef long double ld;
#define loop(i, n) for (long long int i = 0; i < (n); i++)
#define endl "\n"
using namespace std;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
class Calculator {
   private:
    lli cst;
    lli getStatus() const { return cst; }
    void setStatus(lli val) { cst = val; }
   public:
    Calculator() { setStatus(0); }
    Calculator(lli val) { setStatus(val); }
    void add(lli val) { setStatus(getStatus() + val); }
    void subtract(lli val) { setStatus(getStatus() - val); }
    void multiply(lli val) { setStatus(getStatus() * val); }
    lli divideBy(lli val) {
        if (val == 0) {
            cout << "Invalid arithmetic operation." << endl;
            return getStatus();
        }
        lli rem = getStatus() % val;
        setStatus(getStatus() / val);
        return rem;
    }
    void clear() { setStatus(0); }
    void display() const {
        cout << "Calculator display: " << getStatus() << endl;
    }
    ~Calculator() {
        cout << getStatus() << endl;
        cout << "Destructor of the Calculator object is called." << endl;
    }
};
int main() {
    fast();
    Calculator calc;
    calc.add(10);
    calc.display();
    calc.add(7);
    calc.display();
    calc.multiply(31);
    calc.display();
    calc.subtract(42);
    calc.display();
    calc.divideBy(7);
    calc.display();
    calc.divideBy(0);
    calc.display();
    calc.add(3);
    calc.display();
    calc.clear();
    calc.display();
    return 0;
}

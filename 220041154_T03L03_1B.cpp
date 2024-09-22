#include <iostream>
typedef long long int lli;
typedef long double ld;
#define loop(i, n) for (lli i = 0; i < (n); i++)
#define endl "\n"
using namespace std;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
class Time {
   private:
    int hour, minute, second;
    void normalizeTime() {
        if (second >= 60) {
            minute += second / 60;
            second %= 60;
        }
        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        }
        if (hour >= 24) {
            hour %= 24;
        }
    }

   public:
    int hours() const { return hour; }
    int minutes() const { return minute; }
    int seconds() const { return second; }
    void reset(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
        normalizeTime();
    }
    void advance(int h, int m, int s) {
        hour += h;
        minute += m;
        second += s;
        normalizeTime();
    }
    void print() const {
        cout << "Current time: " << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second << endl;
    }
};
int main() {
    fast();
    Time t;
    t.reset(23, 59, 55);
    t.print();
    t.advance(0, 0, 10);
    t.print();
    t.advance(1, 120, 3665);
    t.print();
    return 0;
}

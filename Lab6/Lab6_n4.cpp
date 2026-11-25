#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class time
{
private:
    int hours;
    int minutes;
    int seconds;

    void normalize()
    {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }

public:
    time() : hours(0), minutes(0), seconds(0) {}

    time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        normalize();
    }

    void show() const
    {
        cout << setfill('0')
            << setw(2) << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << endl;
    }

    class time add(const class time& other) const
    {
        time result;
        result.hours = hours + other.hours;
        result.minutes = minutes + other.minutes;
        result.seconds = seconds + other.seconds;
        result.normalize();
        return result;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const class time t1(10, 45, 54);
    const class time t2(9, 20, 31);
    class time t3;

    t3 = t1.add(t2);

    cout << "t1 = "; t1.show();
    cout << "t2 = "; t2.show();
    cout << "t3 = t1 + t2 = "; t3.show();

    return 0;
}
#include <iostream>
#include <windows.h>

using namespace std;

struct Distance
{
    int feet;
    int inches;
};

Distance average(const Distance arr[], int size)
{
    long total_inches = 0;

    for (int i = 0; i < size; i++)
    {
        total_inches += arr[i].feet * 12 + arr[i].inches;
    }

    long avg_inches = total_inches / size;

    Distance result;
    result.feet = static_cast<int>(avg_inches / 12);
    result.inches = static_cast<int>(avg_inches % 12);

    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 5;
    Distance d[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nИнтервал #" << i + 1 << endl;

        while (true)
        {
            cout << "Футы: ";
            cin >> d[i].feet;

            if (cin.fail())
            {
                cout << "Ошибка! Нужно ввести целое число.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (d[i].feet < 0)
            {
                cout << "Ошибка! Футы не могут быть отрицательными.\n";
                continue;
            }

            break;
        }

        while (true)
        {
            cout << "Дюймы: ";
            cin >> d[i].inches;

            if (cin.fail())
            {
                cout << "Ошибка! Нужно ввести целое число.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (d[i].inches < 0)
            {
                cout << "Ошибка! Дюймы не могут быть отрицательными.\n";
                continue;
            }

            break;
        }
    }

    Distance avg = average(d, N);

    cout << "\nСреднее значение: " << avg.feet << " футов "
        << avg.inches << " дюймов" << endl;

    return 0;
}
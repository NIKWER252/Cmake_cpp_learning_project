#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

struct fraction
{
    int numerator;
    int denominator;
};

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int MAX_SIZE = 100;
    fraction arr[MAX_SIZE];
    char slash;
    int count = 0;

    cout << "Введите дроби в формате a/b (для завершения введите q):\n";

    while (count < MAX_SIZE)
    {
        cout << "Дробь #" << (count + 1) << ": ";
        cin >> ws;
        if (cin.peek() == 'q' || cin.peek() == 'Q')
        {
            break;
        }

        cin >> arr[count].numerator >> slash >> arr[count].denominator;

        if (!cin)
        {
            cout << "Ошибка ввода! Попробуйте ещё раз.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (arr[count].denominator == 0)
        {
            cout << "На ноль делить нельзя! Попробуйте ещё раз.\n";
            continue;
        }

        ++count;
    }

    if (count == 0)
    {
        cout << "Вы не ввели ни одной дроби.\n";
        return 0;
    }

    fraction sum{ 0, 1 };
    for (int i = 0; i < count; ++i)
    {
        sum.numerator = sum.numerator * arr[i].denominator
            + arr[i].numerator * sum.denominator;
        sum.denominator = sum.denominator * arr[i].denominator;

        int g = gcd(sum.numerator, sum.denominator);
        sum.numerator /= g;
        sum.denominator /= g;
    }

    fraction average{};
    average.numerator = sum.numerator;
    average.denominator = sum.denominator * count;

    int g = gcd(average.numerator, average.denominator);
    average.numerator /= g;
    average.denominator /= g;

    cout << "\nВведено дробей: " << count << "\n";
    cout << "Среднее значение: ";
    if (average.denominator == 1)
    {
        cout << average.numerator << "\n";
    }
    else if (abs(average.numerator) > average.denominator)
    {
        cout << average.numerator / average.denominator << " "
            << abs(average.numerator) % average.denominator << "/"
            << average.denominator << "\n";
    }
    else
    {
        cout << average.numerator << "/" << average.denominator << "\n";
    }

    return 0;
}
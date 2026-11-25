#include <iostream>
#include <windows.h>

using namespace std;

class date
{
private:
    int month;
    int day;
    int year;

    bool isLeap(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const
    {
        switch (m)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeap(y) ? 29 : 28;
        default:
            return 31;
        }
    }

    bool isValid(int m, int d, int y) const
    {
        if (m < 1 || m > 12) return false;
        if (y < 1) return false;
        if (d < 1 || d > daysInMonth(m, y)) return false;
        return true;
    }

public:
    void getdate()
    {
        char slash1, slash2;

        do
        {
            cout << "Введите дату в формате мм/дд/гг: ";
            cin >> month >> slash1 >> day >> slash2 >> year;

            if (!isValid(month, day, year))
            {
                cout << "Ошибка: некорректная дата. Повторите ввод." << endl;
                cout << "Месяц должен быть от 1 до 12." << endl;
                cout << "Год должен быть больше нуля." << endl;
                cout << "В месяце должно быть соответствующее количество дней." << endl;
            }
        } while (!isValid(month, day, year));
    }

    void showdate() const
    {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    date d;

    d.getdate();
    d.showdate();

    return 0;
}
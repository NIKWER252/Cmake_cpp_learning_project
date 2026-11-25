#include <iostream>
#include <windows.h>

using namespace std;

enum etype {
    LABORANT,
    SECRETARY,
    MANAGER,
    DIRECTOR
};

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
            cout << "Введите дату приема (мм/дд/гг): ";
            cin >> month >> slash1 >> day >> slash2 >> year;

            if (!isValid(month, day, year))
                cout << "Ошибка: некорректная дата. Повторите ввод." << endl;
        } while (!isValid(month, day, year));
    }

    void showdate() const
    {
        cout << month << "/" << day << "/" << year;
    }
};

class employee
{
private:
    int number;
    float salary;
    date hireDate;
    etype position;

public:
    void setNumber(int n)
    {
        number = n;
    }

    void getemploy()
    {
        do
        {
            cout << "Введите оклад сотрудника (>= 0): ";
            cin >> salary;
            if (salary < 0.0f)
                cout << "Ошибка: оклад не может быть отрицательным. Повторите ввод." << endl;
        } while (salary < 0.0f);

        hireDate.getdate();

        int pos;
        do
        {
            cout << "Введите должность (0 - лаборант, 1 - секретарь, 2 - менеджер, 3 - директор): ";
            cin >> pos;
            if (pos < 0 || pos > 3)
                cout << "Ошибка: неверный код должности. Повторите ввод." << endl;
        } while (pos < 0 || pos > 3);

        position = static_cast<etype>(pos);
    }

    void putemploy() const
    {
        cout << "Номер: " << number << endl;
        cout << "Оклад: " << salary << " руб." << endl;
        cout << "Дата приема: ";
        hireDate.showdate();
        cout << endl;

        cout << "Должность: ";
        switch (position)
        {
        case LABORANT:  cout << "Лаборант"; break;
        case SECRETARY: cout << "Секретарь"; break;
        case MANAGER:   cout << "Менеджер"; break;
        case DIRECTOR:  cout << "Директор"; break;
        default:        cout << "Неизвестно"; break;
        }
        cout << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    employee emp[3];
    int used[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "--- Ввод данных сотрудника " << i + 1 << " ---" << endl;

        bool ok;
        int n;
        do
        {
            ok = true;
            cout << "Введите номер сотрудника (> 0, не повторяющийся): ";
            cin >> n;

            if (n <= 0)
            {
                cout << "Ошибка: номер должен быть больше нуля. Повторите ввод." << endl;
                ok = false;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    if (used[j] == n)
                    {
                        cout << "Ошибка: сотрудник с номером " << n << " уже существует. Повторите ввод." << endl;
                        ok = false;
                        break;
                    }
                }
            }
        } while (!ok);

        used[i] = n;
        emp[i].setNumber(n);
        emp[i].getemploy();
        cout << endl;
    }

    cout << "\nВведенные данные о сотрудниках:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "\nСотрудник " << i + 1 << ":" << endl;
        emp[i].putemploy();
    }

    return 0;
}
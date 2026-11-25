#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

// ==================== Задание 1 ====================
class Double
{
private:
    double value;

public:
    void setZero()
    {
        value = 0.0;
    }

    void setInt(int v)
    {
        value = v;
    }

    void show() const
    {
        cout << value << endl;
    }

    Double add(Double& other) const
    {
        Double result;
        result.value = value + other.value;
        return result;
    }
};

void task1()
{
    Double d1, d2, d3;

    d1.setInt(10);
    d2.setInt(25);

    d3 = d1.add(d2);

    cout << "d1 = "; d1.show();
    cout << "d2 = "; d2.show();
    cout << "d3 = d1 + d2 = "; d3.show();

    cin.clear();
    cin.ignore(10000, '\n');
}

// ==================== Задание 2 ====================
class employee
{
private:
    int   number;
    float salary;

public:
    void setdata(int n, float s)
    {
        number = n;
        salary = s;
    }

    void putdata() const
    {
        cout << "  Номер сотрудника: " << number << "\n";
        cout << "  Оклад: " << salary << " руб." << "\n";
    }
};

bool numberOk(int n, const int used[], int count)
{
    if (n <= 0)
    {
        cout << "  Ошибка: номер должен быть больше нуля.\n";
        return false;
    }
    for (int i = 0; i < count; i++)
    {
        if (used[i] == n)
        {
            cout << "  Ошибка: такой номер уже есть.\n";
            return false;
        }
    }
    return true;
}

bool salaryOk(float s)
{
    if (s < 0)
    {
        cout << "  Ошибка: оклад не может быть отрицательным.\n";
        return false;
    }
    return true;
}

void task2()
{
    const int COUNT = 3;
    employee emp[COUNT];
    int numbers[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        int n;
        float s;

        cout << "Сотрудник #" << i + 1 << ":\n";

        do
        {
            cout << "  Введите номер: ";
            cin >> n;
        } while (!numberOk(n, numbers, i));

        do
        {
            cout << "  Введите оклад: ";
            cin >> s;
        } while (!salaryOk(s));

        numbers[i] = n;
        emp[i].setdata(n, s);
        cout << endl;
    }

    cout << "=== Введённые данные ===\n";
    for (int i = 0; i < COUNT; i++)
    {
        cout << "Сотрудник #" << i + 1 << ":\n";
        emp[i].putdata();
        cout << endl;
    }

    cin.clear();
    cin.ignore(10000, '\n');
}

// ==================== Задание 3 ====================
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

void task3()
{
    date d;

    d.getdate();
    d.showdate();

    cin.clear();
    cin.ignore(10000, '\n');
}

// ==================== Задание 4 ====================
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

void task4()
{
    const class time t1(10, 45, 54);
    const class time t2(9, 20, 31);
    class time t3;

    t3 = t1.add(t2);

    cout << "t1 = "; t1.show();
    cout << "t2 = "; t2.show();
    cout << "t3 = t1 + t2 = "; t3.show();

    cin.clear();
    cin.ignore(10000, '\n');
}

// ==================== Задание 5 ====================
enum etype {
    LABORANT,
    SECRETARY,
    MANAGER,
    DIRECTOR
};

class date5
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

class employee5
{
private:
    int number;
    float salary;
    date5 hireDate;
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

void task5()
{
    employee5 emp[3];
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

    cin.clear();
    cin.ignore(10000, '\n');
}

// ==================== Главное меню ====================
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    while (true)
    {
        cout << "\n========== Лабораторная работа №6 ==========\n";
        cout << "Выберите задание (введите 0 для выхода): ";

        cin >> choice;

        if (cin.fail())
        {
            cout << "Ошибка! Введите номер задания.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 0:
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный пункт меню. Попробуйте снова.\n";
        }
    }

    return 0;
}
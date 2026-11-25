#define NOMINMAX
#include <iostream>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(const Time& t)
{
    return static_cast<long>(t.hours) * 3600 + t.minutes * 60 + t.seconds;
}

Time secs_to_time(long totalSecs)
{
    Time t;
    t.hours = static_cast<int>(totalSecs / 3600);
    t.minutes = static_cast<int>((totalSecs % 3600) / 60);
    t.seconds = static_cast<int>(totalSecs % 60);
    return t;
}

bool is_valid(const Time& t)
{
    return t.hours >= 0
        && t.minutes >= 0 && t.minutes <= 59
        && t.seconds >= 0 && t.seconds <= 59;
}

Time read_time(const char* prompt)
{
    Time t{};
    char colon;

    while (true)
    {
        cout << prompt;
        cin >> t.hours >> colon >> t.minutes >> colon >> t.seconds;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Некорректный формат.\n";
            cout << "Введите время в формате чч:мм:сс.\n\n";
            continue;
        }

        if (!is_valid(t))
        {
            cout << "Ошибка! Некорректное время.\n";
            cout << "Часы >= 0, минуты и секунды от 0 до 59.\n\n";
            continue;
        }

        return t;
    }
}

void print_time(const char* label, const Time& t)
{
    cout << label
        << setfill('0') << setw(2) << t.hours << ":"
        << setfill('0') << setw(2) << t.minutes << ":"
        << setfill('0') << setw(2) << t.seconds << "\n";
}

int read_int(const char* prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите целое число.\n";
            continue;
        }
        return value;
    }
}

// ======================= Задание 1 =======================

long hms_to_secs(int hours, int minutes, int seconds)
{
    return long(hours) * 3600 + long(minutes) * 60 + seconds;
}

void task1()
{
    int hours;
    int minutes;
    int seconds;
    char check;
    do
    {
        while (true)
        {
            hours = read_int("Введите часы: ");
            minutes = read_int("Введите минуты: ");
            seconds = read_int("Введите секунды: ");
            if (hours < 0 || minutes < 0 || seconds < 0)
            {
                cout << "Время не может быть отрицательным" << endl;
                continue;
            }
            break;
        }

        cout << "В секундах: " << hms_to_secs(hours, minutes, seconds) << endl;
        cout << "Продолжить? (y/n): ";
        cin >> check;
    } while (check == 'y');
    cin.clear();
    cin.ignore(10000, '\n');
}

// ======================= Задание 2 =======================

void task2()
{
    Time t1 = read_time("Введите первое время (чч:мм:сс): ");
    Time t2 = read_time("Введите второе время (чч:мм:сс): ");

    long totalSecs = time_to_secs(t1) + time_to_secs(t2);
    Time sum = secs_to_time(totalSecs);

    print_time("Сумма: ", sum);
    cin.clear();
    cin.ignore(10000, '\n');
}

// ======================= Задание 3 =======================

void swap_ints(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void task3()
{
    int x = read_int("Введите x: ");
    int y = read_int("Введите y: ");

    swap_ints(x, y);

    cout << "x = " << x << ", y = " << y << endl;
    cin.clear();
    cin.ignore(10000, '\n');
}

// ======================= Задание 4 =======================

void swap_times(Time& a, Time& b)
{
    Time temp = a;
    a = b;
    b = temp;
}

void task4()
{
    Time t1 = read_time("Введите первое время (чч:мм:сс): ");
    Time t2 = read_time("Введите второе время (чч:мм:сс): ");

    swap_times(t1, t2);

    print_time("t1 = ", t1);
    print_time("t2 = ", t2);
    cin.clear();
    cin.ignore(10000, '\n');
}

// ======================= Задание 5 =======================

int global_call_count = 0;

void show_global_call_count()
{
    cout << "функция сработала " << global_call_count << " раз\n";
    ++global_call_count;
}

void show_static_local_call_count()
{
    static int static_local_call_count = 0;
    cout << "функция сработала " << static_local_call_count << " раз\n";
    ++static_local_call_count;
}

void show_local_call_count()
{
    int local_call_count = 0;
    cout << "функция сработала " << local_call_count << " раз\n";
    ++local_call_count;
}

void task5()
{
    cout << "С глобальной переменной:\n";
    for (int i = 0; i < 10; i++)
    {
        show_global_call_count();
    }
    cout << "Со статичной локальной переменной:\n";
    for (int i = 0; i < 10; i++)
    {
        show_static_local_call_count();
    }
    cout << "С обычной локальной переменной:\n";
    for (int i = 0; i < 10; i++)
    {
        show_local_call_count();
    }
    cin.clear();
    cin.ignore(10000, '\n');
}

// ======================= Меню =======================

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    while (true)
    {
        cout << "========== Лабораторная работа №4 ==========\n";
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
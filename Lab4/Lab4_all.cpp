#define NOMINMAX
#include <iostream>
#include <iomanip>
#include <limits>
#include <windows.h>

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
    t.hours   = static_cast<int>(totalSecs / 3600);
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
        std::cout << prompt;
        std::cin >> t.hours >> colon >> t.minutes >> colon >> t.seconds;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка! Некорректный формат.\n";
            std::cout << "Введите время в формате чч:мм:сс.\n\n";
            continue;
        }

        if (!is_valid(t))
        {
            std::cout << "Ошибка! Некорректное время.\n";
            std::cout << "Часы >= 0, минуты и секунды от 0 до 59.\n\n";
            continue;
        }

        return t;
    }
}

void print_time(const char* label, const Time& t)
{
    std::cout << label
              << std::setfill('0') << std::setw(2) << t.hours << ":"
              << std::setfill('0') << std::setw(2) << t.minutes << ":"
              << std::setfill('0') << std::setw(2) << t.seconds << "\n";
}

int read_int(const char* prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Введите целое число.\n";
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
            hours   = read_int("Введите часы: ");
            minutes = read_int("Введите минуты: ");
            seconds = read_int("Введите секунды: ");
            if (hours < 0 || minutes < 0 || seconds < 0)
            {
                std::cout << "Время не может быть отрицательным" << std::endl;
                continue;
            }
            break;
        }

        std::cout << "В секундах: " << hms_to_secs(hours, minutes, seconds) << std::endl;
        std::cout << "Продолжить? (y/n): ";
        std::cin >> check;
    }
    while (check == 'y');
}

// ======================= Задание 2 =======================

void task2()
{
    Time t1 = read_time("Введите первое время (чч:мм:сс): ");
    Time t2 = read_time("Введите второе время (чч:мм:сс): ");

    long totalSecs = time_to_secs(t1) + time_to_secs(t2);
    Time sum = secs_to_time(totalSecs);

    print_time("Сумма: ", sum);
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

    std::cout << "x = " << x << ", y = " << y << std::endl;
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
}

// ======================= Задание 5 =======================

int global_call_count = 0;

void show_global_call_count()
{
    std::cout << "функция сработала " << global_call_count << " раз\n";
    ++global_call_count;
}

void show_static_local_call_count()
{
    static int static_local_call_count = 0;
    std::cout << "функция сработала " << static_local_call_count << " раз\n";
    ++static_local_call_count;
}

void show_local_call_count()
{
    int local_call_count = 0;
    std::cout << "функция сработала " << local_call_count << " раз\n";
    ++local_call_count;
}

void task5()
{
    std::cout << "С глобальной переменной:\n";
    for (int i = 0; i < 10; i++)
    {
        show_global_call_count();
    }
    std::cout << "Со статичной локальной переменной:\n";
    for (int i = 0; i < 10; i++)
    {
        show_static_local_call_count();
    }
    std::cout << "С обычной локальной переменной:\n";
    for (int i = 0; i < 10; i++)
    {
        show_local_call_count();
    }
}

// ======================= Меню =======================

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    while (true)
    {

        int choice = read_int("Выберите задание (0 чтобы выйти): ");
        std::cout << "\n";

        switch (choice)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 0:
            std::cout << "Выход.\n";
            return 0;
        default:
            std::cout << "Нет такого задания. Выберите число от 0 до 5.\n";
        }
    }
}

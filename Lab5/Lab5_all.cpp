#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>

using namespace std;

// ==================== ЗАДАНИЕ 1 ====================
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

void task1()
{
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
        return;
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
    cin.clear();
    cin.ignore(10000, '\n');
}

// ==================== ЗАДАНИЕ 2 ====================
int maxint(int* arr, int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

void task2()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int count = 0;

    cout << "Введите целые числа (для завершения введите q):\n";

    while (count < MAX_SIZE)
    {
        cout << "Число #" << (count + 1) << ": ";

        cin >> ws;
        if (cin.peek() == 'q' || cin.peek() == 'Q')
            break;

        int value;
        cin >> value;

        if (!cin)
        {
            cout << "Ошибка ввода! Введите целое число или q.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        arr[count] = value;
        ++count;
    }

    if (count == 0)
    {
        cout << "Вы не ввели ни одного числа.\n";
        return;
    }

    int maxIndex = maxint(arr, count);

    cout << "\nВведено чисел: " << count << "\n";
    cout << "Наибольший элемент: " << arr[maxIndex] << "\n";
    cout << "Его индекс в массиве: " << maxIndex << "\n";
    cin.clear();
    cin.ignore(10000, '\n');
}

// ==================== ЗАДАНИЕ 3 ====================

void reversit(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void task3()
{
    const int MAX = 100;
    char str[MAX];

    cout << "Введите строку: ";
    cin.get();
    cin.get(str, MAX);

    reversit(str);

    cout << "Перевёрнутая строка: " << str << endl;
}

// ==================== Задание 4 ====================

struct employee
{
    char name[50];
    long number;
};

void getdata(employee& emp, const employee staff[], int current_count)
{
    cout << "Введите имя: ";
    cin.get();
    cin.get(emp.name, 50);

    while (true)
    {
        cout << "Введите номер: ";
        cin >> emp.number;

        if (cin.fail())
        {
            cout << "Ошибка! Нужно вести целое число. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (emp.number < 0)
        {
            cout << "Ошибка! Номер не может быть отрицательным. Попробуйте снова.\n";
            continue;
        }

        bool duplicate = false;
        for (int i = 0; i < current_count; ++i)
        {
            if (staff[i].number == emp.number)
            {
                duplicate = true;
                break;
            }
        }

        if (duplicate)
        {
            cout << "Ошибка! Такой номер уже существует. Введите другой номер.\n";
            continue;
        }

        break;
    }
}

void putdata(const employee& emp)
{
    cout << "Имя:   " << emp.name << endl;
    cout << "Номер: " << emp.number << endl;
}

void task4()
{
    const int N = 3;
    employee staff[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nСлужащий #" << i + 1 << endl;
        getdata(staff[i], staff, i);
    }

    cout << "\nДанные всех служащих" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "\nСлужащий #" << i + 1 << endl;
        putdata(staff[i]);
    }
}

// ==================== ЗАДАНИЕ 5 ====================
struct Distance
{
    int feet;
    int inches;
};

Distance average_dist(const Distance arr[], int size)
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

void task5()
{
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

    Distance avg = average_dist(d, N);

    cout << "\nСреднее значение: " << avg.feet << " футов "
        << avg.inches << " дюймов" << endl;
}

// ==================== ГЛАВНОЕ МЕНЮ ====================
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    while (true)
    {
        cout << "\n========== ЛАБОРАТОРНАЯ РАБОТА №5 ==========\n";
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
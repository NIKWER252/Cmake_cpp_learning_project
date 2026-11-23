#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct employee
{
    char name[50];
    long number;
};

void getdata(employee& emp)
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
            cout << "Ошибка! Нужно ввести целое число. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (emp.number < 0)
        {
            cout << "Ошибка! Номер не может быть отрицательным. Попробуйте снова.\n";
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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 3;
    employee staff[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nСлужащий #" << i + 1 << endl;
        getdata(staff[i]);
    }

    cout << "\nДанные всех служащих" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "\nСлужащий #" << i + 1 << endl;
        putdata(staff[i]);
    }

    return 0;
}
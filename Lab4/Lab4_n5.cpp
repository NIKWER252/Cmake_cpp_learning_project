#include <iostream>
#include <windows.h>

using namespace std;

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

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
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
}
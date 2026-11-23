#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX = 100;
    char str[MAX];

    cout << "Введите строку: ";
    cin.get(str, MAX);

    reversit(str);

    cout << "Перевёрнутая строка: " << str << endl;
    return 0;
}
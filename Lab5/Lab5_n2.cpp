#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100;

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

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

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
        return 0;
    }

    int maxIndex = maxint(arr, count);

    cout << "\nВведено чисел: " << count << "\n";
    cout << "Наибольший элемент: " << arr[maxIndex] << "\n";
    cout << "Его индекс в массиве: " << maxIndex << "\n";

    return 0;
}
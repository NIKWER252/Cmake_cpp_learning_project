#include <iostream>
#include <windows.h>
#include <cstdlib>

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

    std::cout << "Введите целые числа (для завершения введите q):\n";

    while (count < MAX_SIZE)
    {
        std::cout << "Число #" << (count + 1) << ": ";

        std::cin >> std::ws;
        if (std::cin.peek() == 'q' || std::cin.peek() == 'Q')
            break;

        int value;
        std::cin >> value;

        if (!std::cin)
        {
            std::cout << "Ошибка ввода! Введите целое число или q.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        arr[count] = value;
        ++count;
    }

    if (count == 0)
    {
        std::cout << "Вы не ввели ни одного числа.\n";
        return 0;
    }

    int maxIndex = maxint(arr, count);

    std::cout << "\nВведено чисел: " << count << "\n";
    std::cout << "Наибольший элемент: " << arr[maxIndex] << "\n";
    std::cout << "Его индекс в массиве: " << maxIndex << "\n";

    return 0;
}
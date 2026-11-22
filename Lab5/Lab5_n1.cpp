#include <iostream>
#include <windows.h>
#include <cstdlib>

struct fraction
{
    int numerator;
    int denominator;
};

int gcd(int a, int b)
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int MAX_SIZE = 100;
    fraction arr[MAX_SIZE];
    char slash;
    int count = 0;

    std::cout << "Введите дроби в формате a/b (для завершения введите q):\n";

    // Ввод дробей до тех пор, пока не введён 'q' или не достигнут лимит
    while (count < MAX_SIZE)
    {
        std::cout << "Дробь #" << (count + 1) << ": ";

        // Пропускаем пробельные символы и проверяем, не хочет ли пользователь выйти
        std::cin >> std::ws;
        if (std::cin.peek() == 'q' || std::cin.peek() == 'Q')
        {
            break;
        }

        std::cin >> arr[count].numerator >> slash >> arr[count].denominator;

        if (!std::cin)
        {
            std::cout << "Ошибка ввода! Попробуйте ещё раз.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (arr[count].denominator == 0)
        {
            std::cout << "На ноль делить нельзя! Попробуйте ещё раз.\n";
            continue;
        }

        ++count;
    }

    if (count == 0)
    {
        std::cout << "Вы не ввели ни одной дроби.\n";
        return 0;
    }

    // Вычисление суммы всех дробей
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

    // Среднее значение = сумма / count
    fraction average{};
    average.numerator = sum.numerator;
    average.denominator = sum.denominator * count;

    int g = gcd(average.numerator, average.denominator);
    average.numerator /= g;
    average.denominator /= g;

    // Вывод результата
    std::cout << "\nВведено дробей: " << count << "\n";
    std::cout << "Среднее значение: ";
    if (average.denominator == 1)
    {
        std::cout << average.numerator << "\n";
    }
    else if (std::abs(average.numerator) > average.denominator)
    {
        std::cout << average.numerator / average.denominator << " "
            << std::abs(average.numerator) % average.denominator << "/"
            << average.denominator << "\n";
    }
    else
    {
        std::cout << average.numerator << "/" << average.denominator << "\n";
    }

    return 0;
}
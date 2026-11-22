#include <iostream>

int main() {
    const int MAX = 100;
    double fractions[MAX];
    int count = 0;
    double value;

    std::cout << "Введите дробные числа (для завершения введите любой нечисловой символ):\n";

    while (count < MAX && std::cin >> value) {
        fractions[count++] = value;
    }

    if (count == 0) {
        std::cout << "Вы не ввели ни одного числа.\n";
        return 1;
    }

    double sum = 0.0;
    for (int i = 0; i < count; ++i) {
        sum += fractions[i];
    }

    std::cout << "Среднее значение: " << sum / count << "\n";

    return 0;
}
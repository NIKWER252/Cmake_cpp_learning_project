#include <iostream>
#include <windows.h>

using namespace std;

class employee {
private:
    int   number;
    float salary;

public:
    void setdata(int n, float s) {
        number = n;
        salary = s;
    }

    void putdata() const {
        cout << "  Номер сотрудника: " << number << "\n";
        cout << "  Оклад: " << salary << " руб." << "\n";
    }
};

bool numberOk(int n, const int used[], int count) {
    if (n <= 0) {
        cout << "  Ошибка: номер должен быть больше нуля.\n";
        return false;
    }
    for (int i = 0; i < count; i++) {
        if (used[i] == n) {
            cout << "  Ошибка: такой номер уже есть.\n";
            return false;
        }
    }
    return true;
}

bool salaryOk(float s) {
    if (s < 0) {
        cout << "  Ошибка: оклад не может быть отрицательным.\n";
        return false;
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int COUNT = 3;
    employee emp[COUNT];
    int numbers[COUNT];

    for (int i = 0; i < COUNT; i++) {
        int n;
        float s;

        cout << "Сотрудник #" << i + 1 << ":\n";

        do {
            cout << "  Введите номер: ";
            cin >> n;
        } while (!numberOk(n, numbers, i));

        do {
            cout << "  Введите оклад: ";
            cin >> s;
        } while (!salaryOk(s));

        numbers[i] = n;
        emp[i].setdata(n, s);
        cout << endl;
    }

    cout << "=== Введённые данные ===\n";
    for (int i = 0; i < COUNT; i++) {
        cout << "Сотрудник #" << i + 1 << ":\n";
        emp[i].putdata();
        cout << endl;
    }

    return 0;
}
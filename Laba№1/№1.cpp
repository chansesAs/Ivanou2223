#include <iostream>
using namespace std;

class Money {
public:
    int first;  // номинал купюры
    int second; // количество купюр данного достоинства

    Money(int first = 0, int second = 0) {
        this->first = first;
        this->second = second;
    }

    int summa() {
        return first * second;
    }
};

int main() {
    setlocale(0, "RU");
    Money money[] = { Money(1, 10), Money(2, 5), Money(5, 2), Money(50, 3), Money(100, 1) };

    int total_sum = 0;
    for (int i = 0; i < 5; i++) {
        total_sum += money[i].summa();
    }

    cout << "Общая сумма денег: " << total_sum << endl;

    return 0;
}
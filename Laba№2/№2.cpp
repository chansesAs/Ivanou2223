#include <iostream>
#include <string>
using namespace std;

class Decimal {
private:
    string number;

public:
    // Конструктор для целых чисел
    Decimal(int num) {
        if (num < 0) {
            number = "-" + to_string(-num);
        }
        else {
            number = "+" + to_string(num);
        }
        reverse(number.begin() + 1, number.end());
    }

    // Конструктор для строк
    Decimal(string num) {
        if (num[0] != '+' && num[0] != '-') {
            num = "+" + num;
        }
        number = num;
        reverse(number.begin() + 1, number.end());
    }

    // Метод для сложения
    Decimal add(Decimal other) {
        // Проверяем знаки чисел
        if (number[0] == '-' && other.number[0] == '+') {
            other.number[0] = '-';
            return subtract(other);
        }
        else if (number[0] == '+' && other.number[0] == '-') {
            other.number[0] = '+';
            return subtract(other);
        }

        string result = "";
        int carry = 0;

        // Дополнить нулями, если необходимо
        while (number.size() < other.number.size()) {
            number += '0';
        }
        while (other.number.size() < number.size()) {
            other.number += '0';
        }

        // Проходим по каждой цифре числа
        for (int i = 1; i < number.size(); ++i) {
            int sum = (number[i] - '0') + (other.number[i] - '0') + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        // Обработка оставшегося знака
        if (carry) {
            result += '1';
        }
        char sign = (number[0] == other.number[0]) ? number[0] : '+';
        result += sign;

        // Реверс и возвращаем результат
        reverse(result.begin(), result.end());
        return Decimal(result);
    }


    // Метод для вычитания (предполагает, что this >= other)
    Decimal subtract(Decimal other) {
        // Проверяем знаки чисел
        if (number[0] == '+' && other.number[0] == '-') {
            other.number[0] = '+';
            return add(other);
        }
        else if (number[0] == '-' && other.number[0] == '+') {
            other.number[0] = '-';
            return add(other);
        }

        string result = "";
        int borrow = 0;

        // Дополнить нулями, если необходимо
        while (number.size() < other.number.size()) {
            number += '0';
        }
        while (other.number.size() < number.size()) {
            other.number += '0';
        }

        // Проходим по каждой цифре числа
        for (int i = 1; i < number.size(); ++i) {
            int diff = (number[i] - '0') - (other.number[i] - '0') - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            result += diff + '0';
        }

        // Удаляем ведущие нули
        int index = result.size() - 1;
        while (index > 0 && result[index] == '0') {
            --index;
        }
        result = result.substr(0, index + 1);

        // Добавляем знак
        if (borrow) {
            result += '-';
        }
        else {
            result += '+';
        }

        // Реверс и возвращаем результат
        reverse(result.begin(), result.end());
        return Decimal(result);
    }


    // Методы сравнения
    bool equals(Decimal other) {
        return number == other.number;
    }

    bool greaterThan(Decimal other) {
        if (number[0] != other.number[0]) {
            return number[0] == '+';
        }
        if (number.size() != other.number.size()) {
            return number.size() > other.number.size();
        }
        for (int i = number.size() - 1; i >= 1; --i) {
            if (number[i] != other.number[i]) {
                return number[i] > other.number[i];
            }
        }
        return false; // числа равны
    }
    // Вывод числа
    void print() {
        for (int i = number.size() - 1; i >= 0; --i) {
            cout << number[i];
        }
        cout << endl;
    }
};
void reverse(string& s, int begin, int end) {
    while (begin < end) {
        char temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        ++begin;
        --end;
    }
}
int main() {
    setlocale(0, "RU");
    Decimal dec1(5622);
    Decimal dec2("-1221");
    cout << "dec1: ";
    dec1.print();
    cout << "dec2: ";
    dec2.print();

    Decimal dec3 = dec1.add(dec2);
    cout << "dec1 + dec2: ";
    dec3.print();

    if (dec1.greaterThan(dec2) || dec1.equals(dec2)) {
        Decimal dec4 = dec1.subtract(dec2);
        cout << "dec1 - dec2: ";
        dec4.print();
    }
    else {
        cout << "dec1 меньше чем dec2, вычитание невозможно." << endl;
    }

    if (dec1.equals(dec2)) {
        cout << "dec1 равно dec2" << endl;
    }
    else {
        cout << "dec1 не равно dec2" << endl;
    }

    if (dec1.greaterThan(dec2)) {
        cout << "dec1 больше чем dec2" << endl;
    }
    else {
        cout << "dec1 не больше чем dec2" << endl;
    }


    return 0;
}
#include <cmath>

class Double {
private:
    double value;

public:
    Double(double val = 0.0) : value(val) {}


    Double operator+(const Double& other) const {
        return Double(value + other.value);
    }

    Double operator-(const Double& other) const {
        return Double(value - other.value);
    }

    Double operator*(const Double& other) const {
        return Double(value * other.value);
    }

    Double operator/(const Double& other) const {
        return Double(value / other.value);
    }

    Double operator+=(const Double& other) {
        value += other.value;
        return *this;
    }

    Double operator-=(const Double& other) {
        value -= other.value;
        return *this;
    }

    Double operator*=(const Double& other) {
        value *= other.value;
        return *this;
    }

    Double operator/=(const Double& other) {
        value /= other.value;
        return *this;
    }

    Double operator-() const {
        return Double(-value);
    }

    // Дружественные функции
    friend Double pow(const Double& base, const Double& exponent) {
        return Double(std::pow(base.value, exponent.value));
    }

    friend Double sqrt(const Double& num) {
        return Double(std::sqrt(num.value));
    }

    // Методы элементарных функций
    Double abs() const {
        return Double(std::abs(value));
    }

    Double sin() const {
        return Double(std::sin(value));
    }

    Double cos() const {
        return Double(std::cos(value));
    }

    // Преобразование во встроенный тип double
    operator double() const {
        return value;
    }
};

int main() {
    Double a = 2.5;
    Double b = 1.3;

    Double c = a + b;
    Double d = pow(a, b);

    double result = static_cast<double>(c);  // Преобразование обратно в double

    return 0;
}
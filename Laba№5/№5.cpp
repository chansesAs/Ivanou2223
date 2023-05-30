#include <iostream>
#include <algorithm>

class Cylinder {
public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getSurfaceArea() const {
        double baseArea = 3.14 * radius * radius;
        double lateralArea = 2 * 3.14 * radius * height;
        return 2 * baseArea + lateralArea;
    }

    double getVolume() const {
        return 3.14 * radius * radius * height;
    }

    double getWeight() const {
        // Здесь предполагается, что вес зависит от объема цилиндра
        // и некоторого коэффициента материала
        double materialDensity = 1.0;  // Коэффициент плотности материала (предположим, что 1.0)
        return getVolume() * materialDensity;
    }

private:
    double radius;
    double height;
};

bool compareCylinders(const Cylinder& c1, const Cylinder& c2) {
    return c1.getWeight() < c2.getWeight();
}

int main() {
    setlocale(0, "RU");
    // Создаем массив объектов класса Cylinder
    Cylinder cylinders[] = { Cylinder(2.0, 5.0), Cylinder(3.0, 4.0), Cylinder(1.5, 6.0) };
    int numCylinders = sizeof(cylinders) / sizeof(Cylinder);

    // Упорядочиваем массив по возрастанию веса
    std::sort(cylinders, cylinders + numCylinders, compareCylinders);

    // Выводим полную поверхность, объем и вес каждого цилиндра
    for (int i = 0; i < numCylinders; ++i) {
        const Cylinder& cylinder = cylinders[i];
        std::cout << "Параметры цилиндра:" << std::endl;
        std::cout << "Полная поверхность: " << cylinder.getSurfaceArea() << std::endl;
        std::cout << "Объем: " << cylinder.getVolume() << std::endl;
        std::cout << "Вес: " << cylinder.getWeight() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
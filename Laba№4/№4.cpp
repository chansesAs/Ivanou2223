#include <iostream>

class Vector2D {
protected:
    double x;
    double y;

public:
    Vector2D(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    virtual void printCoordinates() {
        std::cout << "Vector coordinates: (" << x << ", " << y << ")" << std::endl;
    }
};

class Vector3D : public Vector2D {
private:
    double z;

public:
    Vector3D(double xCoord, double yCoord, double zCoord) : Vector2D(xCoord, yCoord), z(zCoord) {}

    void printCoordinates() override {
        Vector2D::printCoordinates();
        std::cout << "Additional coordinate: " << z << std::endl;
    }
};

int main() {
    Vector2D vector2D(2.5, 3.7);
    Vector3D vector3D(1.0, 2.0, 3.0);

    Vector2D* basePtr = &vector2D;
    Vector3D* derivedPtr = &vector3D;

    basePtr->printCoordinates();    // Вызывается функция из базового класса
    derivedPtr->printCoordinates(); // Вызывается переопределенная функция из производного класса

    return 0;
}
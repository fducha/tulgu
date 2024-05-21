#include <iostream>
#include <math.h>

using namespace std;

class SpatialVector
{
    double x, y, z;
public:
    SpatialVector(double x = 0, double y = 0, double z = 0);
    ~SpatialVector() {
//        cout << "Работа деструктора" << endl;
    }

    double abs();

    double getX() const { return x; }
    void setX(double x) { this->x = x; }
    double getY() const { return y; }
    void setY(double y) { this->y = y; }
    double getZ() const { return z; }
    void setZ(double z) { this->z = z; }

    void info() {
        cout << "Координаты вектора " << x << ", " << y << ", " << z << endl;
    }

    SpatialVector operator+ (SpatialVector other) {
        SpatialVector c;
        c.setX(this->getX() + other.getX());
        c.setY(this->getY() + other.getY());
        c.setZ(this->getZ() + other.getZ());
        return c;
    }
};

SpatialVector::SpatialVector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
//    cout << "Работа конструктора" << endl;
}

double SpatialVector::abs() {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    SpatialVector a(1, 2, 3), b(10, 20, 30), c;
    c = a + b;
    c.info();
    return 0;
}

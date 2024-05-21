#include <iostream>
#include <math.h>

using namespace std;

class SpatialVector
{
    double x, y, z;
public:
    SpatialVector();
    ~SpatialVector() {
        cout << "Работа деструктора" << endl;
    }

    void set(double a, double b, double c);
    double abs();

    double getX() const { return x; }
    void setX(double x) { this->x = x; }
    double getY() const { return y; }
    void setY(double y) { this->y = y; }
    double getZ() const { return z; }
    void setZ(double z) { this->z = z; }
};

SpatialVector::SpatialVector() {
    cout << "Работа конструктора" << endl;
}

void SpatialVector::set(double a, double b, double c) {
    x = a; y = b; z = c;
}

double SpatialVector::abs() {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    SpatialVector a;
    cout << a.abs() << endl;
    a.setX(3);
    a.setY(4);
    a.setZ(0);
    cout << a.abs() << endl;
    return 0;
}


#include <iostream>
#include <math.h>

using namespace std;

class SpatialVector
{
    double x, y, z;
public:
    SpatialVector(double a, double b, double c);
    ~SpatialVector() {
        cout << "Работа деструктора" << endl;
    }

    //void set(double a, double b, double c);
    double abs();
};

SpatialVector::SpatialVector(double a, double b, double c) {
    x = a; y = b; z = c;
    cout << "Работа конструктора" << endl;
}

//void SpatialVector::set(double a, double b, double c) {
//    x = a; y = b; z = c;
//}

double SpatialVector::abs() {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    SpatialVector a(3, 4, 0);
    cout << a.abs() << endl;
    return 0;
}

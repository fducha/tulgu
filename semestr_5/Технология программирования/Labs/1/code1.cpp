#include <iostream>
#include <math.h>

using namespace std;

class SpatialVector
{
    double x, y, z;
public:
    void set(double a, double b, double c);
    double abs();
};

void SpatialVector::set(double a, double b, double c) {
    x = a; y = b; z = c;
}

double SpatialVector::abs() {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    SpatialVector a;
    a.set(1, 2, 3);
    cout << a.abs() << endl;
    return 0;
}

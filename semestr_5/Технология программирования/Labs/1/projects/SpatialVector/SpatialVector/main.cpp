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

//#include <iostream>
//#include <math.h>

//using namespace std;

//class SpatialVector
//{
//    double x, y, z;

//    friend ostream& operator<< (ostream &stream, SpatialVector &a);
//    friend istream& operator>> (istream &stream, SpatialVector &a);
//public:
//    SpatialVector(double x = 0, double y = 0, double z = 0);

//    double abs();

//    double getX() const { return x; }
//    void setX(double x) { this->x = x; }
//    double getY() const { return y; }
//    void setY(double y) { this->y = y; }
//    double getZ() const { return z; }
//    void setZ(double z) { this->z = z; }

//    void info() {
//        cout << "Координаты вектора " << x << ", " << y << ", " << z << endl;
//    }

//    SpatialVector operator+ (SpatialVector other) {
//        SpatialVector c;
//        c.setX(this->getX() + other.getX());
//        c.setY(this->getY() + other.getY());
//        c.setZ(this->getZ() + other.getZ());
//        return c;
//    }
//};

//SpatialVector::SpatialVector(double x, double y, double z) {
//    this->x = x;
//    this->y = y;
//    this->z = z;
//}

//double SpatialVector::abs() {
//    return sqrt(x * x + y * y + z * z);
//}

//ostream& operator<< (ostream &stream, SpatialVector &a) {
//    stream << "x = " << a.x << ", y = " << a.y << ", z = " << a.z << endl;
//    return stream;
//}
//istream& operator>> (istream &stream, SpatialVector &a) {
//    stream >> a.x >> a.y >> a.z;
//    return stream;
//}

//int main() {
//    SpatialVector a;
//    cin >> a;
//    cout << "Был введен вектор: " << a << endl;

//    return 0;
//}

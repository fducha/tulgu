#include <iostream>

using namespace std;

class Matrix
{
    double *m;
    size_t width, height;
public:
    Matrix(size_t w, size_t h);
    Matrix(const Matrix &other);
    ~Matrix();

    double getValue(size_t i, size_t j);
    void setValue(size_t i, size_t j, double val);
};

Matrix::Matrix(size_t w, size_t h) {
    m = new double[w * h];
    width = w;
    height = h;
}

Matrix::Matrix(const Matrix &other) {
    m = new double[other.width * other.height];
    width = other.width;
    height = other.height;
}

Matrix::~Matrix() {
    delete [] m;
}

double Matrix::getValue(size_t i, size_t j) {
    return m[i * width + j];
}

void Matrix::setValue(size_t i, size_t j, double val) {
    if ((i < width) && (j < height)) {
        m[i * width + j] = val;
    }
}

int main()
{
    Matrix a(2, 2);
    a.setValue(0, 0, 100);
    Matrix b = a;
    b.setValue(0, 0, 200);
    cout << "a[0, 0] = " << a.getValue(0, 0) << "; b[0, 0] = " << b.getValue(0, 0) << endl;
    return 0;
}

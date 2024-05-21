#include <iostream>

using namespace std;

class Integer
{
    int value;
public:
    Integer() { value = 0; }

    Integer& operator++();
    Integer operator++(int);

    int getValue() const { return value; }
};

Integer &Integer::operator++() {
    value += 1;
    cout << "Использован префиксный оператор" << endl;
    return *this;
}

// было
//Integer &Integer::operator++(int) {
//    value += 1;
//    cout << "Использован постфиксный оператор" << endl;
//    return *this;
//}

// стало
Integer Integer::operator++(int) {
    Integer t = *this;
    ++*this;
    cout << "Использован постфиксный оператор" << endl;
    return t;
}

int main()
{
    Integer i, i2;
    int a;
    i2 = i++;
    a = i2.getValue();
    cout << a << endl;
    a = i.getValue();
    cout << a << endl;
    i2 = ++i;
    a = i2.getValue();
    cout << a << endl;
    a = i.getValue();
    cout << a << endl;
    return 0;
}


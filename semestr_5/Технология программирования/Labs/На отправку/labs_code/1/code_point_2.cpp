#include <iostream>

using namespace std;

class Point
{
private:
    int x, y;
    static int count;
    friend void findPoint(Point *first, Point *last, Point arg);
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;

        cout << "Количество объектов " << ++count << endl;
    }
    ~Point() {
        cout << "Количество объектов " << --count << endl;
    }
};

int Point::count;

void findPoint(Point *first, Point *last, Point arg) {
    for (auto *p = first; p <= last; p++) {
        if ((p->x == arg.x) && (p->y == arg.y)) {
            cout << "Точка с координатами " << p->x << ", " << p->y << " найдена" << endl;
            return;
        }
    }
    cout << "Точка с координатами " << arg.x << ", " << arg.y << " не найдена" << endl;
}

int main()
{
    Point a, b, c;

    return 0;
}

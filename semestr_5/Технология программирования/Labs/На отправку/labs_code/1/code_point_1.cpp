#include <iostream>

using namespace std;

class Point
{
private:
    int x, y;
    friend void findPoint(Point *first, Point *last, Point arg);
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

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
    Point *points[10];
    for (int i = 0; i < 10; i++) {
        points[i] = new Point(i, i+1);
    }
    findPoint(points[0], points[9], Point(3, 4));
    findPoint(points[0], points[9], Point(5, 8));

    return 0;
}

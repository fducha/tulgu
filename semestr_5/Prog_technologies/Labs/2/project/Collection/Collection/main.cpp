#include <iostream>
#include <set>

using namespace std;

class IntCollection
{
public:
    IntCollection() {}
    void add(int element) { m_set.insert(element); }
    void remove(int element) { m_set.erase(element); }
    void print() {
        for (int el : m_set) {
            cout << el << " ";
        }
        cout << endl;
    };
    IntCollection operator *(const IntCollection &other) {
        IntCollection result;
        for (int el : this->m_set) {
            if (other.m_set.count(el) > 0) result.add(el);
        }
        return result;
    }

private:
    set<int> m_set;
};

int main()
{
    IntCollection A;
    for (int i = 1; i <= 7; i++) {
        A.add(i);
    }
    A.remove(1);
    cout << "Множество А:" << endl;
    A.print();

    IntCollection B;
    for (int i = 6; i <= 15; i++) {
        B.add(i);
    }
    B.remove(13);
    cout << "Множество B:" << endl;
    B.print();

    cout << "Пересечение множеств А и В:" << endl;
    IntCollection I = A * B;
    I.print();

    return 0;
}

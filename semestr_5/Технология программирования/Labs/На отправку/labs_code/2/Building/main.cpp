#include <iostream>
#include <iomanip>

using namespace std;

class Building
{
public:
    Building(const string &name, const string &material, double width, double lenght, double cost) :
        m_name(name), m_material(material), m_width(width), m_lenght(lenght), m_cost(cost) {}

    string name() const { return m_name; }
    string material() const { return m_material; }
    double width() const { return m_width; }
    double lenght() const { return m_lenght; }
    double cost() const { return m_cost; }

    double area() const { return m_width * m_lenght; }

    void info() {
        cout << "______________________________________________" << endl;
        cout << name() << endl;
        cout << "Материал: " << material() << endl;
        cout << "Ширина: " << width() << " м." << endl;
        cout << "Длина: " << lenght() << " м." << endl;
        cout << "Цена: " << fixed << setprecision(0) << cost() << " руб." << endl;
        cout << "Площадь: " << area() << " кв. м." << endl;
    }

private:
    string m_name;
    string m_material;
    double m_width;
    double m_lenght;
    double m_cost;
};

class Cottege : public Building
{
public:
    Cottege(const string &name, const string &material, double width, double lenght, double cost,
            int floors = 1, int balconies = 0, int garages = 0) :
        Building(name, material, width, lenght, cost),
        m_floors(floors), m_balconies(balconies), m_garages(garages) {}

    double area() const {
        if (floors() > 1) return Building::area() * m_floors;
        else return Building::area();
    }

    void info() {
        cout << "===========================================" << endl;
        cout << "Коттедж ";
        Building::info();

        if (floors() > 1) {
            cout << floors() << " этажа" << endl;
            cout << "Площадь " << floors() << " этажей: " << area() << " кв. м.";
        }
        else cout << "Одноэтажный";
        cout << endl;

        if (balconies() >= 1) cout << balconies() << " балкон(а)";
        else cout << "Балконы отсутствуют.";
        cout << endl;

        if (garages() >= 1) cout << garages() << " гараж(а)";
        else cout << "Гаражи отсутствуют.";
        cout << endl;
    }

    int floors() const { return m_floors; }

    int balconies() const { return m_balconies; }

    int garages() const { return m_garages; }

private:
    int m_floors;
    int m_balconies;
    int m_garages;
};

int main()
{
    Building b1("Склад", "Пеноблок", 30, 50, 15000000);
    b1.info();
    Building b2("Жилой дом", "Бетон", 20, 40, 33600000);
    b2.info();
    Cottege c1("Универсальный", "Кирпич", 14, 10, 3000000, 2, 4);
    c1.info();
    Cottege c2("Сельский", "Брус", 5, 7, 1500000, 1, 0, 1);
    c2.info();
    return 0;
}





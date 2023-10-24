#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

const string FILE_NAME = "data.dat";

struct Passenger {
    string name;
    string destination;
    double price;
    string train_number;

    void print() {
        cout << name << endl;
        cout << destination << endl;
        cout << price << endl;
        cout << train_number << endl;
    }
};

Passenger input_passenger() {
    cout << "Введите ФИО: ";
    Passenger p;
    cin.ignore();
    getline(cin, p.name);
    cout << "Введите пункт назначения: ";
    cin.clear();
    cin >> p.destination;
    cout << "Введите стоимость билета: ";
    string price_str;
    cin >> price_str;
    p.price = stod(price_str);
    cout << "Введите номер поезда: ";
    cin >> p.train_number;

    return p;
}

void add_passenger(string name, string destination, double price, string train_number) {
    ofstream file;
    file.open(FILE_NAME, ios::app);
    file << endl << name + "&" + destination + "&" + 
                std::to_string(price) + "&" + train_number;
    file.close();
}

Passenger parse_from_string(const string &data) {
    size_t pos = 0;
    Passenger p;

    stringstream ss{data};
    string str;

    while (getline(ss, str, '&'))
    {
        if (pos == 0) {
            p.name = str;
            pos++;
            continue;
        }
        if (pos == 1) {
            p.destination = str;
            pos++;
            continue;
        }
        if (pos == 2) {
            p.price = stod(str);
            pos++;
            continue;
        }
        if (pos == 3) {
            p.train_number = str;
            pos++;
            continue;
        }
    }

    return p;
}

void swap_data(Passenger &p1, Passenger &p2) {
    Passenger tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void sort_passengers_by_price(vector<Passenger> &data) {
    for (size_t i = 1; i < data.size(); i++)    {
        for (size_t j = i; j > 0 && data[j-1].price > data[j].price; j--) {
            swap_data(data[j-1], data[j]);
        }
    }
}

vector<Passenger> read_pass_data() {
    ifstream file;
    file.open(FILE_NAME, ios::in);
    vector<Passenger> result;
    while (!file.eof()) {
        string data;
        getline(file, data);
        Passenger p = parse_from_string(data);
        result.push_back(p);
    }
    file.close();
    sort_passengers_by_price(result);
    return result;
}

void print_menu() {
    cout << endl;
    cout << "Выберете действие и нажмите Ввод:" << endl;
    cout << "1 - Вывести список всех пассажиров;" << endl;
    cout << "2 - Добавить пассажира;" << endl;
    cout << "0 - Выйти из приложения." << endl;
}

void print_line() {
    for (size_t i = 0; i < 96; i++) {
        cout << "_";
    }
    cout << endl;
}

void print_table(const vector<Passenger> &data) {
    print_line();
    cout << "| " <<  "ФИО пассажира" << "\t\t\t\t| " << "Пункт назначения" << "\t| " 
            << "Стоимость" << "\t| " << "Номер" << "\t\t|" <<  endl;
    cout << "|\t\t\t\t\t| \t\t\t| "  << "билета, руб." << "\t| " << "поезда" << "\t|" <<  endl;
    print_line();
    
    for (auto p: data) {
        string holder1 = p.name.length() <= 40 ? "\t\t\t| " : "\t\t| ";
        string holder2 = p.destination.length() < 10 ? "\t\t\t| " : p.destination.length() > 25 ? "\t| " : "\t\t| ";
        cout << "| " <<  p.name << holder1 << p.destination << holder2 
            << fixed << setprecision(2) << p.price << "\t| " << p.train_number << "\t\t|" <<  endl;
    }
    print_line();
}

int main() {
    cout << "Вас приветствует приложение РЖД Пассажирам" << endl;
    print_menu();
    int command{0};
    cin >> command;
    while (command != 0) {
        switch (command) {
        case 1:
            print_table(read_pass_data());
            break;
        case 2: {
            Passenger p = input_passenger();
            add_passenger(p.name, p.destination, p.price, p.train_number);
        }
            break;
        default:
            cout << "Выбран некорректное действие" << endl;
            break;
        }
        print_menu();
        cin >> command;
    }
    cout << "До скорой встречи!!" << endl;
    return 0;
}

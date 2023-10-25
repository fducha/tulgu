#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node* next;

    Node(string val) : value(val), next(nullptr) {}
};

struct LinkedList {
    Node* first;
    Node* last;
    
    LinkedList() : first(nullptr), last(nullptr) {}

    bool is_empty() const {
        return first == nullptr;
    }

    void push_back(string val) {
        auto p = new Node(val);
        if (is_empty()) {
            first = p;
            last = p;
        }

        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        auto p = first;
        while (p) {
            cout << p->value << " (" << p << ")" << endl;
            p = p->next;
        }
        cout << endl;
    }
};

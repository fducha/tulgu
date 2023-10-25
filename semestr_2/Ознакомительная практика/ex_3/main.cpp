#include "linked_list.h"


void swap_first_and_last_node(LinkedList &list) {
    auto second = list.first->next;
    auto tmp_first = list.first;
    auto current = list.first;
    Node* beforeLast = nullptr;
    while (current->next) {
        beforeLast = current;
        current = current->next;
    }
    beforeLast->next = tmp_first;
    current->next = second;
    tmp_first->next = nullptr;
    list.first = current;
    list.last = tmp_first;
}

int main() {
    LinkedList list;
    list.push_back("Первый");
    list.push_back("Второй");
    list.push_back("Третий");
    list.push_back("Четвертый");
    list.push_back("Пятый");
    
    list.print();

    swap_first_and_last_node(list);

    list.print();

    swap_first_and_last_node(list);

    list.print();

    return 0;
}

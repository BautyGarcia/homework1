#include <iostream>
#include "main.h"
#include <memory>

using namespace std;

struct Node {
    unique_ptr<Node> next;
    int value;
};

struct List {
    unique_ptr<Node> head;
    int size = 0;
};

unique_ptr<Node> create_node(int value) {
    auto new_node = make_unique<Node>();
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}

void push_front(unique_ptr<List> &list, int value) {
    auto new_node = create_node(value);
    new_node->next = std::move(list->head);
    list->head = std::move(new_node);
    list->size++;
}

void push_back(unique_ptr<List> &list, int value) {
    auto new_node = create_node(value);
    if (list->head == nullptr) {
        list->head = std::move(new_node);
    } else {
        auto current = list->head.get();
        while (current->next != nullptr) {
            current = current->next.get();
        }
        current->next = std::move(new_node);
    }
    list->size++;
}

void insert(unique_ptr<List> &list, int value, int position) {
    if (position < 0) throw invalid_argument("Estas muy chistoso vos");
    if (position > list->size) {
        cout << "-- Como te fuiste de rango agrego al final" << endl;
        position = list->size;
    }

    if (position == 0) {
        push_front(list, value);
        return;
    }

    auto current = list->head.get();

    for (int i = 0; i < position - 1; i++) {
        current = current->next.get();
    }

    auto new_node = create_node(value);
    new_node->next = std::move(current->next);
    current->next = std::move(new_node);
    list->size++;
}

void erase(unique_ptr<List> &list, int position) {
    if (position < 0) throw invalid_argument("Estas muy chistoso vos");
    if (position >= list->size) {
        cout << "-- Como te fuiste de rango borro al final" << endl;
        position = list->size - 1;
    };

    if (position == 0) {
        list->head = std::move(list->head->next);
        list->size--;
        return;
    }

    auto current = list->head.get();
    for (int i = 0; i < position - 1; i++) {
        current = current->next.get();
    }

    current->next = std::move(current->next->next);
    list->size--;
}

void print_list(unique_ptr<List> &list) {
    auto current = list->head.get();
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next.get();
    }
    cout << endl;
}

int main()
{    
    unique_ptr<List> list = make_unique<List>();
    cout << "Hago push front de 1, 2, 3, 4, 5" << endl;
    push_front(list, 1);
    push_front(list, 2);
    push_front(list, 3);
    push_front(list, 4);
    push_front(list, 5);
    print_list(list);

    cout << "Hago push back de 6, 7, 8, 9, 10" << endl;
    push_back(list, 6);
    push_back(list, 7);
    push_back(list, 8);
    push_back(list, 9);
    push_back(list, 10);
    print_list(list);

    cout << "Hago insert de 11 en la posicion 3" << endl;
    insert(list, 11, 3);
    print_list(list);

    cout << "Hago erase en la posicion 2" << endl;
    erase(list, 2);
    print_list(list);

    cout << "Pruebo de insertar en una posicion que no existe" << endl;
    insert(list, 12, 100);
    print_list(list);

    cout << "Pruebo de borrar en una posicion que no existe" << endl;
    erase(list, 100);
    print_list(list);

    cout << "Pruebo de insertar en el borde" << endl;
    insert(list, 0, list->size);
    print_list(list);

    cout << "Pruebo de borrar en el borde" << endl;
    erase(list, list->size - 1);
    print_list(list);

    return 0;
}
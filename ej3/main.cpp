#include <iostream>
#include "main.h"
#include <memory>

using namespace std;

class Node {
    public:
        unique_ptr<Node> next;
        int value;

        Node(int value)
        {
            this->value = value;
        }
};

class List {
    unique_ptr<Node> head;
    int size;

    public:
        List()
        {
            size = 0;
        }

        void push_front(int value)
        {
            auto new_node = make_unique<Node>(value);
            
            new_node->next = move(head);
            head = move(new_node);

            size++;
        }

        void push_back(int value)
        {
            auto new_node = make_unique<Node>(value);
            
            if (head == nullptr) {
                head = move(new_node);
            } else {
                Node* current = head.get();
                while (current->next != nullptr) {
                    current = current->next.get();
                }
                current->next = move(new_node);
            }
            size++;
        }

        // Tomo position como el indice, arranco desde 0
        void insert(int value, int position)
        {
            auto new_node = make_unique<Node>(value);

            if (position == 0) {
                push_front(value);
                return;
            }
            if (position >= size) {
                cout << "Te pasaste de la lista, lo agrego al final, dormiste" << endl;
                push_back(value);
                return;
            }

            Node *current = head.get();
            for (int i = 0; i < position - 1; i++) {
                current = current->next.get();
            }

            new_node->next = move(current->next);
            current->next = move(new_node);
        }

        void erase(int position)
        {
            if (position >= size) {
                cout << "Te pasaste de la lista, borro el ultimo, dormiste" << endl;
                position = size - 1;
            }

            if (position == 0) {
                Node* temp = head.get();
                head = move(head->next);
                size--;
                return;
            }

            Node* current = head.get();
            for (int i = 0; i < position - 1; i++) {
                current = current->next.get();
            }

            Node* temp = current->next.get();
            current->next = move(temp->next);
            
            size--;
        }

        void print() {
            Node *current = head.get();
            while (current->next != nullptr) {
                cout << current->value << " -> ";
                current = current->next.get();
            }
            cout << current->value << " -○" << endl;
        }
};

int main()
{
    List list;
    cout << "\nDISCLAIMER: El indice de la lista arranca desde 0 en mi logica" << endl << endl;
    cout << "Creo una lista vacia..." << endl;
    cout << "Agrego elementos al principio: 1, 2, 3" << endl;
    list.push_front(1);
    list.push_front(2); 
    list.push_front(3);
    cout << "La lista actual es: ";
    list.print();

    cout << "\nAgrego un elemento en la posicion 2..." << endl;
    list.insert(4, 2);
    cout << "La lista actual es: ";
    list.print();

    cout << "\nIntento agregar un elemento en la posicion 10..." << endl;
    list.insert(10, 10);
    cout << "La lista actual es: ";
    list.print();

    cout << "\nBorro el elemento en la posicion 1..." << endl;
    list.erase(1);
    cout << "La lista actual es: ";
    list.print();

    cout << "\nIntento borrar un elemento en la posicion 10..." << endl;
    list.erase(10);
    cout << "La lista actual es: ";
    list.print();

    cout << "\nAgrego mas elementos al final: 5, 6" << endl;
    list.push_back(5);
    list.push_back(6);
    cout << "La lista actual es: ";
    list.print();
    
    return 0;
}
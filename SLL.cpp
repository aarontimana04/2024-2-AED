#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T data;
    Nodo* next;
    Nodo(T data) : data(data), next(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* head;  // Puntero al primer nodo de la lista
    int size;

public:
    ListaEnlazada() : head(nullptr), size(0) {}

    ~ListaEnlazada() {
        clear();
    }

    void push_front(T value) {
        Nodo<T>* nuevoNodo = new Nodo<T>(value);
        nuevoNodo->next = head;
        head = nuevoNodo;
        size++;
    }

    void push_back(T value) {
        Nodo<T>* nuevoNodo = new Nodo<T>(value);
        if (head == nullptr) {
            head = nuevoNodo;
        } else {
            Nodo<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nuevoNodo;
        }
        size++;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Nodo<T>* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
    }

    T front() {
        if (head == nullptr) {
            throw runtime_error("La lista está vacía.");
        }
        return head->data;
    }

    T back() {
        if (head == nullptr) {
            throw runtime_error("La lista está vacía.");
        }

        Nodo<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    int tam_list() {
        return size;
    }

    bool empty() {
        return head == nullptr;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void print() {
        if (head == nullptr) {
            cout << "Lista vacía" << endl;
            return;
        }
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void insert(T value, int lugar) {
        if (lugar < 0 || lugar > size) {
            throw runtime_error("Posición inválida.");
        }

        if (lugar == 0) {
            push_front(value);
        } else {
            Nodo<T>* nuevoNodo = new Nodo<T>(value);
            Nodo<T>* temp = head;
            for (int i = 0; i < lugar - 1; ++i) {
                temp = temp->next;
            }
            nuevoNodo->next = temp->next;
            temp->next = nuevoNodo;
            size++;
        }
    }

    void remove(int lugar) {
        if (lugar < 0 || lugar >= size) {
            throw runtime_error("Posición inválida.");
        }

        if (lugar == 0) {
            pop_front();
        } else {
            Nodo<T>* temp = head;
            for (int i = 0; i < lugar - 1; ++i) {
                temp = temp->next;
            }
            Nodo<T>* eliminar = temp->next;
            temp->next = eliminar->next;
            delete eliminar;
            size--;
        }
    }
};

int main() {
    ListaEnlazada<int> lista;

    // Insertando elementos
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_front(5);

    lista.print();  // Output: 5 -> 10 -> 20 -> 30 -> nullptr

    cout << "Tamaño de la lista: " << lista.tam_list() << endl;  // Output: 4

    cout << "Primer elemento: " << lista.front() << endl;  // Output: 5
    cout << "Último elemento: " << lista.back() << endl;   // Output: 30

    lista.pop_front();
    lista.pop_back();
    lista.print();  // Output: 10 -> 20 -> nullptr

    lista.insert(15, 1);  // Insertar 15 en la posición 1
    lista.print();  // Output: 10 -> 15 -> 20 -> nullptr

    lista.remove(1);  // Eliminar el nodo en la posición 1
    lista.print();  // Output: 10 -> 20 -> nullptr

    lista.clear();
    lista.print();  // Output: Lista vacía

    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T data;
    Nodo* next;
    Nodo* prev;
    Nodo(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    Nodo<T>* head;  // Puntero al primer nodo
    Nodo<T>* tail;  // Puntero al último nodo
    int size;

public:
    // Constructor
    ListaDoble() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor para liberar memoria
    ~ListaDoble() {
        clear();
    }

    // Método para insertar un nodo al frente de la lista
    void push_front(T value) {
        Nodo<T>* nuevoNodo = new Nodo<T>(value);
        if (head == nullptr) { // Si la lista está vacía
            head = tail = nuevoNodo;
        } else {
            nuevoNodo->next = head;
            head->prev = nuevoNodo;
            head = nuevoNodo;
        }
        size++;
    }

    // Método para insertar un nodo al final de la lista
    void push_back(T value) {
        Nodo<T>* nuevoNodo = new Nodo<T>(value);
        if (tail == nullptr) { // Si la lista está vacía
            head = tail = nuevoNodo;
        } else {
            tail->next = nuevoNodo;
            nuevoNodo->prev = tail;
            tail = nuevoNodo;
        }
        size++;
    }

    // Método para eliminar el primer nodo de la lista
    void pop_front() {
        if (head == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* temp = head;
        if (head == tail) { // Si hay un solo elemento
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Método para eliminar el último nodo de la lista
    void pop_back() {
        if (tail == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* temp = tail;
        if (head == tail) { // Si hay un solo elemento
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    // Método para obtener el valor del primer nodo
    T front() {
        if (head == nullptr) {
            throw runtime_error("La lista está vacía.");
        }
        return head->data;
    }

    // Método para obtener el valor del último nodo
    T back() {
        if (tail == nullptr) {
            throw runtime_error("La lista está vacía.");
        }
        return tail->data;
    }

    // Método para obtener el tamaño de la lista
    int tam_list() {
        return size;
    }

    // Método para verificar si la lista está vacía
    bool empty() {
        return head == nullptr;
    }

    // Método para eliminar todos los nodos de la lista
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Método para imprimir la lista en orden
    void print() {
        if (head == nullptr) {
            cout << "Lista vacía" << endl;
            return;
        }
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Método para imprimir la lista en orden inverso
    void print_reverse() {
        if (tail == nullptr) {
            cout << "Lista vacía" << endl;
            return;
        }
        Nodo<T>* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "nullptr" << endl;
    }

    // Método para insertar en una posición específica
    void insert(T value, int lugar) {
        if (lugar < 0 || lugar > size) {
            throw runtime_error("Posición inválida.");
        }

        if (lugar == 0) {
            push_front(value);
        } else if (lugar == size) {
            push_back(value);
        } else {
            Nodo<T>* nuevoNodo = new Nodo<T>(value);
            Nodo<T>* temp = head;
            for (int i = 0; i < lugar - 1; ++i) {
                temp = temp->next;
            }
            nuevoNodo->next = temp->next;
            nuevoNodo->prev = temp;
            temp->next->prev = nuevoNodo;
            temp->next = nuevoNodo;
            size++;
        }
    }

    // Método para eliminar en una posición específica
    void remove(int lugar) {
        if (lugar < 0 || lugar >= size) {
            throw runtime_error("Posición inválida.");
        }

        if (lugar == 0) {
            pop_front();
        } else if (lugar == size - 1) {
            pop_back();
        } else {
            Nodo<T>* temp = head;
            for (int i = 0; i < lugar; ++i) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }
    }
};

int main() {
    ListaDoble<int> lista;

    // Insertando elementos
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_front(5);

    // Imprimir lista en orden
    lista.print();  // Output: 5 <-> 10 <-> 20 <-> 30 <-> nullptr

    // Imprimir lista en orden inverso
    lista.print_reverse();  // Output: 30 <-> 20 <-> 10 <-> 5 <-> nullptr

    // Tamaño de la lista
    cout << "Tamaño de la lista: " << lista.tam_list() << endl;  // Output: 4

    // Obtener primer y último elemento
    cout << "Primer elemento: " << lista.front() << endl;  // Output: 5
    cout << "Último elemento: " << lista.back() << endl;   // Output: 30

    // Eliminar elementos
    lista.pop_front();
    lista.pop_back();
    lista.print();  // Output: 10 <-> 20 <-> nullptr

    // Insertar en posición específica
    lista.insert(15, 1);  // Insertar 15 en la posición 1
    lista.print();  // Output: 10 <-> 15 <-> 20 <-> nullptr

    // Eliminar en posición específica
    lista.remove(1);  // Eliminar el nodo en la posición 1
    lista.print();  // Output: 10 <-> 20 <-> nullptr

    // Limpiar lista
    lista.clear();
    lista.print();  // Output: Lista vacía

    return 0;
}

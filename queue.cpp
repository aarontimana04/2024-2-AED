#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* siguiente;
    Nodo() : valor(T()), siguiente(nullptr) {};
    Nodo(const T& val) : valor(val), siguiente(nullptr) {};
};

template <typename T>
class iter_queue {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    iter_queue() : cabeza(nullptr), cola(nullptr) {}

    ~iter_queue() {
        while (!empty()) {
            pop();
        }
    }

    // Verifica si la cola está vacía
    bool empty() const {
        return cabeza == nullptr;
    }

    // Devuelve el tamaño de la cola
    int tamanio() const {
        Nodo<T>* temp = cabeza;
        int contador = 0;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }
        return contador;
    }

    // Inserta un valor en la cola
    void push(const T& valor) {
        Nodo<T>* nnodo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = nnodo;
            cola = nnodo;
        } else {
            cola->siguiente = nnodo;
            cola = nnodo;
        }
    }

    // Devuelve el primer nodo de la cola
    Nodo<T>* front() const {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return nullptr;
        } else {
            return cabeza;
        }
    }

    // Devuelve el último nodo de la cola
    Nodo<T>* back() const {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return nullptr;
        } else {
            return cola;
        }
    }

    // Elimina el primer nodo de la cola
    void pop() {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return;
        }

        Nodo<T>* temp = cabeza;
        cabeza = cabeza->siguiente;
        if (cabeza == nullptr) {
            cola = nullptr;
        }
        delete temp;
    }

    // Imprime la cola
    void print() const {
        if (empty()) {
            cout << "Queue vacía" << endl;
            return;
        }
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};

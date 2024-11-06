#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* next;
    Nodo() : valor(0), next(nullptr) {}
    Nodo(const T& val) : valor(val), next(nullptr) {}
};

template<typename T>
class iter_stack {
private:
    Nodo<T>* head;

public:
    iter_stack() : head(nullptr) {}

    // Verifica si la pila está vacía
    bool empty() {
        return head == nullptr;
    }

    // Calcula el tamaño de la pila
    int size() {
        Nodo<T>* temp = head;
        int contador = 0;
        while (temp != nullptr) {
            contador++;
            temp = temp->next;
        }
        return contador;
    }

    // Inserta un nuevo nodo en el tope de la pila
    void push(Nodo<T>* nnodo) {
        nnodo->next = head;
        head = nnodo;
    }

    // Elimina el nodo en el tope de la pila
    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        Nodo<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // Devuelve el valor del nodo en el tope de la pila
    T top() {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return T();  // Valor por defecto de T
        }
        return head->valor;
    }

    // Imprime los valores de los nodos en la pila
    void print() {
        Nodo<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->next;
        }
        if (head == nullptr)
            cout << "Stack vacío";
        
        cout << endl;
    }
};

int main() {
    iter_stack<int> pila;
    Nodo<int>* n1 = new Nodo<int>(2);
    Nodo<int>* n2 = new Nodo<int>(3);
    Nodo<int>* n3 = new Nodo<int>(4);

    pila.push(n1);
    pila.push(n2);
    pila.push(n3);

    pila.print();

    cout << "Top: " << pila.top() << endl;

    pila.pop();
    pila.print();
    cout << "Top: " << pila.top() << endl;

    pila.pop();
    pila.print();
    cout << "Top: " << pila.top() << endl;

    pila.pop();
    pila.print();

    return 0;
}

#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* next;
    Nodo() : valor(0), next(nullptr){};
    Nodo(const T& val) : valor(val), next(nullptr){};
};

template <typename T>
class iter_queue {
    private:
    Nodo<T>* head;
    Nodo<T>* tail;

    public:
    iter_queue() : head(nullptr), tail(nullptr){}

    // Verifica si la cola está vacía
    bool empty() const {
        return head == nullptr;
    }

    // Devuelve el tamaño de la cola
    int size() const {
        Nodo<T>* temp = head;
        int contador = 0;
        while(temp != nullptr) {
            contador++;
            temp = temp->next;
        }
        return contador;
    }

    // Inserta un valor en la cola
    void push(const T& valor) {
        Nodo<T>* nnodo = new Nodo<T>(valor); // Crea un nuevo nodo con el valor
        if (head == nullptr) {
            head = nnodo;
            tail = nnodo;
        } else {
            tail->next = nnodo;
            tail = nnodo;
        }
    }

    // Devuelve el primer nodo de la cola
    Nodo<T>* front() const {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return nullptr;
        } else {
            return head;
        }
    }

    // Devuelve el último nodo de la cola
    Nodo<T>* back() const {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return nullptr;
        } else {
            return tail;
        }
    }

    // Elimina el primer nodo de la cola
    void pop() {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return;
        }

        Nodo<T>* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        temp = nullptr; // Asegurar que el puntero se borra
    }

    // Imprime la cola
    void print() const {
        if (empty()) {
            cout << "Queue vacía" << endl;
            return;
        }
        Nodo<T>* temp = head;
        while(temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    iter_queue<int> cola;

    // Insertando valores en la cola
    cola.push(10);
    cola.push(11);
    cola.push(12);
    cola.push(13);

    // Imprimir cola
    cola.print();

    // Tamaño de la cola
    cout << "Tamaño: " << cola.size() << endl;

    // Verificar si está vacía
    cout << "¿Cola vacía?: " << cola.empty() << endl;

    // Eliminar el primer elemento
    cola.pop();
    cola.print();
    cout << "Tamaño: " << cola.size() << endl;

    // Obtener el frente de la cola
    Nodo<int>* n7 = cola.front();
    if (n7 != nullptr) {
        cout << "Front: " << n7->valor << endl;
    }

    // Eliminar más elementos
    cola.pop();
    cola.pop();
    cola.print();

    // Obtener el último elemento (back) de la cola
    Nodo<int>* n8 = cola.back();
    if (n8 != nullptr) {
        cout << "Back: " << n8->valor << endl;
    }

    return 0;
}

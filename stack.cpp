#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* next;
    Nodo<T>* tail;
    Nodo() : valor(0), next(nullptr), tail(nullptr){};
    Nodo(const T& val) : valor(val), next(nullptr), tail(nullptr){};
};

template<typename T>
class iter_stack {
    private:
    Nodo<T>* head;
    public:
    iter_stack() : head(nullptr){};

    //completo
    bool empty(){
        return head == nullptr;
    }

    //completo
    int size(){
        Nodo<T>* temp = head;
        int contador = 0;
        while(temp != nullptr){
            contador++;
            temp = temp->next;
        }
        return contador;
    }

    //completo
    void push(Nodo<T>* nnodo){
        if(head == nullptr){
            head = nnodo;
            head->tail = nnodo;
        } else {
            head->tail->next = nnodo;
            head->tail = nnodo;
        }
    }
    
    //faltante
    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Nodo<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Nodo<T>* lastNode = temp->next;
        temp->next = nullptr;
        delete lastNode;
        head->tail = temp;
    }

    //incompleto
    T top() {
        if (head == nullptr) {
            cout << "Stack is empty." << endl;
            return T();  // Valor por defecto de T
        }
        return head->tail->valor;
    }

    //completo
    void print(){
        Nodo<T>* temp = head;
        while(temp != nullptr){
            cout << temp->valor << " ";
            temp = temp->next;
        }
        if (head == nullptr)
            cout << "Stack vacío";

        cout << endl;
    }

};

int main(){
    iter_stack<int> pila;
    Nodo<int>* n1 = new Nodo<int>(2);
    Nodo<int>* n2 = new Nodo<int>(3);
    Nodo<int>* n3 = new Nodo<int>(4);

    pila.push(n1);
    pila.push(n2);
    pila.push(n3);

    pila.print();

    cout << pila.top() << endl;

    pila.pop();

    pila.print();

    cout << pila.top() << endl;

    pila.print();

    pila.pop();

    pila.print();

    cout << pila.top() << endl;

    pila.pop();

    pila.print();

    return 0;
}

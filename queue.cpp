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
    iter_queue() : head(nullptr), tail(nullptr){};

    bool empty(){
        return head == nullptr;
    }

    int size(){
        Nodo<T>* temp = head;
        int contador = 0;
        while(temp != nullptr){
            contador++;
            temp = temp->next;
        }
        return contador;
    }

    void push(Nodo<T>* nnodo){
        if (head == nullptr) {
            head = nnodo;
            tail = nnodo;
        } else {
            tail->next = nnodo;
            tail = nnodo;
        }
    }

    Nodo<T>* front(){
        if (empty() == true) {
            cout << "Queue vacía." << endl;
            return nullptr;
        } else {
            return head;
        }
    }

    Nodo<T>* back(){
        if (empty() == true) {
            cout << "Queue vacía." << endl;
            return nullptr;
        } else {
            return tail;
        }
    }

    void pop(){
        if (empty() == true) {
            cout << "Queue vacía." << endl;
            return;
        }

        Nodo<T>* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    void print(){
        Nodo<T>* temp = head;
        while(temp != nullptr){
            cout << temp->valor << " ";
            temp = temp->next;
        }
        if (head == nullptr)
            cout << "Queue vacío";

        cout << endl;
    }
};

int main() {
    iter_queue<int> cola;
    Nodo<int>* n1 = new Nodo<int>(10);
    Nodo<int>* n2 = new Nodo<int>(11);
    Nodo<int>* n3 = new Nodo<int>(12);
    Nodo<int>* n4 = new Nodo<int>(13);

    cola.push(n1);
    cola.push(n2);
    cola.push(n3);
    cola.push(n4);

    cola.print();

    cout << cola.size() << endl;
    cout << cola.empty() << endl;

    cola.pop();
    cola.print();
    cout << cola.size() << endl;

    Nodo<int>* n7 = cola.front();
    if (n7 != nullptr) {
        cout << "Front: " << n7->valor << endl;
    }

    cola.pop();
    cola.pop();
    cola.print();

    Nodo<int>* n8 = cola.back();
    if (n8 != nullptr) {
        cout << "Back: " << n8->valor << endl;
    }

    

    return 0;
}

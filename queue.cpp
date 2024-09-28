#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* next;
    Nodo<T>* tail;
    Nodo() : valor(0), next(nullptr),tail(nullptr){};
    Nodo(const T& val) : valor(val), next(nullptr), tail(nullptr){};
};

template <typename T>
class iter_queue{
    private:
    Nodo<T>* head;
    public:
    iter_queue() : head(nullptr){};

    bool empty(){
        if(head == nullptr){
            return true;
        } else {
            return false;
        }
    }

    int size(){
        Nodo<T>* temp = head;
        int contador = 0;
        while(temp != nullptr){
            contador++;
            temp = temp->next;
        }

        if(head == nullptr){
            return 0;
        }
        return contador;
    }

    void push(Nodo<T>* nnodo){
        if(head == nullptr){
            head = nnodo;
            head->tail = nnodo;
        } else {
            head->tail->next = nnodo;
            head->tail = nnodo;
        }
    }

    Nodo<T>* front(){
        return head;
    }

    Nodo<T>* back(){
        return head->tail;
    }

    void pop(){
        Nodo<T>* temp = head;
        head = head->next;
        delete temp;        
    }

};

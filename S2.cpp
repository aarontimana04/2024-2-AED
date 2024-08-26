#include <iostream>
#include <string>
using namespace std;
//funciones

//struct
template <typename T>
struct Node{
  T data;
  Node* next;
};
//clases
template <typename T>
class List {
private:
  Node<T>* head;
public:
  List(): head(nullptr){};

  void insertar(T valor){
    Node<T>* n = new Node<T>;
    n->data = valor;
    if(head==nullptr){
      head=n;
    } else {
      head->next = n;
    }
  }

  void buscar_valor(T valor){
    Node<T>* temp=head;
    while(temp != nullptr){
      if(temp->data==valor){
        cout<<"Existe"<<endl;
        return;
      }else {
        temp=temp->next;
      }
    }
  }
};

//principal
int main(){
  List<string> l1;
  l1.insertar("hola");
  l1.insertar("estas");
  l1.insertar("utec");

  l1.buscar_valor("estas");

  return 0;
}




#include <iostream>

using namespace std;

template <typename T>
struct Nodo{
    T valor;
    Nodo<T>* derecha;
    Nodo<T>* izquierda;
    Nodo() : derecha(nullptr), izquierda(nullptr){};
    Nodo(T val) : valor(val), derecha(nullptr), izquierda(nullptr){};
};

template<typename T>
class BST{
    private:
    Nodo<T>* root;
    public:
    BST() : root(nullptr){};

    bool empty(Nodo<T>* root){
        return root == nullptr; 
    }

    void insertar(Nodo<T>* root, T valor){
        if (root == nullptr){
            Nodo<T>* nuevo = new Nodo(valor);
            root = nuevo;
            return;
        }
        if(valor<root->valor){
            return insertar(root->izquierda, valor);
        } else{
            return insertar(root->derecha, valor);
        }
    }

    bool buscar(Nodo<T>* root,T valor){
        if(root == nullptr){
            return false;
        }
        if(valor<root->valor){
            return buscar(root->izquierda, valor);
        } else if(valor>root->valor){
            return buscar(root->derecha, valor);
        } else{
            return true;
        }
    }

    //No propia implementacion (estudiar)
    void eliminar(Nodo<T>* &root, T valor) {
        if (root == nullptr) {
            return;  // El árbol está vacío, no hay nada que eliminar
        }

        if (valor < root->valor) {
            eliminar(root->izquierda, valor);  // Búsqueda en el subárbol izquierdo
        } else if (valor > root->valor) {
            eliminar(root->derecha, valor);    // Búsqueda en el subárbol derecho
        } else {
            // Nodo encontrado

            // Caso 1: Nodo con un hijo o sin hijos
            if (root->izquierda == nullptr) {
                Nodo<T>* temp = root->derecha;
                delete root;
                root = temp;
            } else if (root->derecha == nullptr) {
                Nodo<T>* temp = root->izquierda;
                delete root;
                root = temp;
            } else {
            // Caso 2: Nodo con dos hijos
                Nodo<T>* temp = minValueNode(root->derecha);  // Encuentra el sucesor
                root->valor = temp->valor;  // Copia el valor del sucesor
                eliminar(root->derecha, temp->valor);  // Elimina el sucesor
            }
        }
    }

    //Nodo con el valor minimo del arbol
    Nodo<T>* minValueNode(Nodo<T>* node) {
        Nodo<T>* current = node;
        while (current && current->izquierda != nullptr)
            current = current->izquierda;
        return current;
    }

    //estudiar hasta aquí


    void preorder(Nodo<T>* aux) {
        if (aux != nullptr) {
            cout << aux->valor << " ";
            preorder(aux->izquierda);
            preorder(aux->derecha);
        }
    }

    void inorder(Nodo<T>* aux) {
        if (aux != nullptr) {
            inorder(aux->izquierda);
            cout << aux->valor << " ";
            inorder(aux->derecha);
        }
    }

    void postorder(Nodo<T>* aux) {
        if (aux != nullptr) {
            postorder(aux->izquierda);
            postorder(aux->derecha);
            cout << aux->valor << " ";
        }
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }


};

#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T valor;
    int altura;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;
    Nodo() : valor(0), altura(1), izquierda(nullptr), derecha(nullptr) {};
    Nodo(T val) : valor(val), altura(1), izquierda(nullptr), derecha(nullptr) {};
};

template <typename T>
class AVL {
private:
    Nodo<T>* root;

public:
    AVL() : root(nullptr) {}

    bool empty(Nodo<T>* nodo) {
        return nodo == nullptr;
    }

    int altura(Nodo<T>* nodo) {
        if (nodo == nullptr)
            return -1;
        return nodo->altura;
    }

    int factorBalanceo(Nodo<T>* nodo) {
        if (nodo == nullptr)
            return 0;
        return altura(nodo->izquierda) - altura(nodo->derecha);
    }

    Nodo<T>* rotacionDerecha(Nodo<T>* y) {
        Nodo<T>* x = y->izquierda;
        Nodo<T>* T2 = x->derecha;

        // Realizamos la rotación
        x->derecha = y;
        y->izquierda = T2;

        // Actualizamos las alturas
        y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
        x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;

        // Retornamos la nueva raíz
        return x;
    }

    Nodo<T>* rotacionIzquierda(Nodo<T>* x) {
        Nodo<T>* y = x->derecha;
        Nodo<T>* T2 = y->izquierda;

        // Realizamos la rotación
        y->izquierda = x;
        x->derecha = T2;

        // Actualizamos las alturas
        x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
        y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;

        // Retornamos la nueva raíz
        return y;
    }

    void insertar(Nodo<T>* &root, T valor) {
        if (root == nullptr) {
            root = new Nodo<T>(valor);
            return;
        }
        if (valor < root->valor) {
            insertar(root->izquierda, valor);
        } else if (valor > root->valor) {
            insertar(root->derecha, valor);
        } else {
            return; // No se permiten valores duplicados
        }

        // Actualizamos la altura del nodo actual
        root->altura = 1 + max(altura(root->izquierda), altura(root->derecha));

        // Verificamos el balance del nodo actual
        int balance = factorBalanceo(root);

        // Caso 1: Rotación a la derecha (LL)
        if (balance > 1 && valor < root->izquierda->valor) {
            root = rotacionDerecha(root);
        }

        // Caso 2: Rotación a la izquierda (RR)
        if (balance < -1 && valor > root->derecha->valor) {
            root = rotacionIzquierda(root);
        }

        // Caso 3: Rotación doble izquierda-derecha (LR)
        if (balance > 1 && valor > root->izquierda->valor) {
            root->izquierda = rotacionIzquierda(root->izquierda);
            root = rotacionDerecha(root);
        }

        // Caso 4: Rotación doble derecha-izquierda (RL)
        if (balance < -1 && valor < root->derecha->valor) {
            root->derecha = rotacionDerecha(root->derecha);
            root = rotacionIzquierda(root);
        }
    }

    bool buscar(Nodo<T>* root, T valor) {
        if (root == nullptr) {
            return false;
        }
        if (valor > root->valor) {
            return buscar(root->derecha, valor);
        } else if (valor < root->valor) {
            return buscar(root->izquierda, valor);
        } else {
            return true;
        }
    }

    void eliminar(Nodo<T>* &root, T valor) {
        if (root == nullptr) {
            return;
        }

        if (valor < root->valor) {
            eliminar(root->izquierda, valor);
        } else if (valor > root->valor) {
            eliminar(root->derecha, valor);
        } else {
            if (root->izquierda == nullptr || root->derecha == nullptr) {
                Nodo<T>* temp = root->izquierda ? root->izquierda : root->derecha;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                Nodo<T>* temp = minValueNode(root->derecha);
                root->valor = temp->valor;
                eliminar(root->derecha, temp->valor);
            }
        }

        if (root == nullptr)
            return;

        root->altura = max(altura(root->izquierda), altura(root->derecha)) + 1;

        int balance = factorBalanceo(root);

        if (balance > 1 && factorBalanceo(root->izquierda) >= 0)
            root = rotacionDerecha(root);

        if (balance > 1 && factorBalanceo(root->izquierda) < 0) {
            root->izquierda = rotacionIzquierda(root->izquierda);
            root = rotacionDerecha(root);
        }

        if (balance < -1 && factorBalanceo(root->derecha) <= 0)
            root = rotacionIzquierda(root);

        if (balance < -1 && factorBalanceo(root->derecha) > 0) {
            root->derecha = rotacionDerecha(root->derecha);
            root = rotacionIzquierda(root);
        }
    }

    Nodo<T>* minValueNode(Nodo<T>* nodo) {
        Nodo<T>* actual = nodo;
        while (actual->izquierda != nullptr)
            actual = actual->izquierda;
        return actual;
    }
};

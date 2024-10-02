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

    bool empty(Nodo<T>* nodo) {
        return nodo == nullptr;
    }

    int altura(Nodo<T>* nodo) {
        if (nodo == nullptr)
            return 0;
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

        x->derecha = y;
        y->izquierda = T2;

        y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
        x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;

        return x;
    }

    Nodo<T>* rotacionIzquierda(Nodo<T>* x) {
        Nodo<T>* y = x->derecha;
        Nodo<T>* T2 = y->izquierda;

        y->izquierda = x;
        x->derecha = T2;

        x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
        y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;

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
            return;
        }

        root->altura = 1 + max(altura(root->izquierda), altura(root->derecha));

        int balance = factorBalanceo(root);

        if (balance > 1 && valor < root->izquierda->valor)
            root = rotacionDerecha(root);

        if (balance < -1 && valor > root->derecha->valor)
            root = rotacionIzquierda(root);

        if (balance > 1 && valor > root->izquierda->valor) {
            root->izquierda = rotacionIzquierda(root->izquierda);
            root = rotacionDerecha(root);
        }

        if (balance < -1 && valor < root->derecha->valor) {
            root->derecha = rotacionDerecha(root->derecha);
            root = rotacionIzquierda(root);
        }
    }

    bool buscar(Nodo<T>* root, T valor) {
        if (root == nullptr)
            return false;

        if (valor < root->valor)
            return buscar(root->izquierda, valor);

        if (valor > root->valor)
            return buscar(root->derecha, valor);

        return true;
    }

    void eliminar(Nodo<T>* &root, T valor) {
        if (root == nullptr)
            return;

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

    void printTree(Nodo<T> *root, string indent, bool last) {
        if (root != nullptr) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "   ";
            } else {
                cout << "L----";
                indent += "|  ";
            }
            cout << root->valor << endl;
            printTree(root->izquierda, indent, false);
            printTree(root->derecha, indent, true);
        }
    }

public:
    AVL() : root(nullptr) {}

    void insertar(T valor) {
        insertar(root, valor);
    }

    bool buscar(T valor) {
        return buscar(root, valor);
    }

    void eliminar(T valor) {
        eliminar(root, valor);
    }

    void printTree() {
        printTree(root, "", true);
    }
};

int main() {
    AVL<int> avlTree;

    avlTree.insertar(5);
    avlTree.insertar(2);
    avlTree.insertar(3);
    avlTree.insertar(8);
    avlTree.insertar(9);
    avlTree.insertar(7);

    cout << "Árbol AVL después de las inserciones:" << endl;
    avlTree.printTree();

    cout << "\nEliminando el valor 7" << endl;
    avlTree.eliminar(7);
    avlTree.printTree();

    cout << "\nEliminando el valor 3" << endl;
    avlTree.eliminar(3);
    avlTree.printTree();

    return 0;
}

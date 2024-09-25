//
// Created by alumno06 on 25/09/2024.
//

#ifndef FINAL_CPP_ARBOL_H
#define FINAL_CPP_ARBOL_H

//Crearemos un árbol de búsqueda binaria.
//Empecemos con un nodo, que tendrá un dato y punteros a sus hijos izquierdo y derecho

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node *left_child;
    Node *right_child;
};

template<typename T>
class BSTree {
    Node<T> *root;

    bool search(Node<T>* node, T value) {
        if (node == nullptr) {
            return false; // No se encontró el valor
        }

        if (node->data == value) {
            return true; // Valor encontrado
        }

        if (value < node->data) {
            return search(node->left_child, value); // Buscar en el subárbol izquierdo
        } else {
            return search(node->right_child, value); // Buscar en el subárbol derecho
        }
    }

    Node<T>* insert(Node<T>* node, T value) {
        // Si el árbol está vacío, crea un nuevo nodo y retorna
        if (node == nullptr) {
            node = new Node<T>();
            node->right_child = nullptr;
            node->left_child = nullptr;
            node->data = value;
            return node;
        }

        // Si el valor es menor que el valor del nodo actual, insertar en el subárbol izquierdo
        if (value < node->data) {
            node->left_child = insert(node->left_child, value);
        }
            // Si el valor es mayor que el valor del nodo actual, insertar en el subárbol derecho
        else if (value > node->data) {
            node->right_child = insert(node->right_child, value);
        }

        // Retornar el nodo (sin cambios si ya existía)
        return node;
    }

    Node<T>* remove(Node<T>* node, T value) {
        if (node == nullptr) {
            return node;  // El nodo no existe
        }

        // Buscar el nodo a eliminar
        if (value < node->data) {
            node->left_child = remove(node->left_child, value);
        } else if (value > node->data) {
            node->right_child = remove(node->right_child, value);
        } else {
            // Se ha encontrado el nodo

            // Si es un nodo hoja, se elimina y se vuelve nullptr (para que el padre apunte a nullptr)
            if (node->left_child == nullptr && node->right_child == nullptr) {
                delete node;
                return nullptr;
            }

            // Si tiene solo un hijo, se retorna el hijo del nodo eliminado, así el padre del nodo eliminado apunta al hijo de este último +.
            if (node->left_child == nullptr) {
                Node<T>* temp = node->right_child;
                delete node;
                return temp;
            }
            if (node->right_child == nullptr) {
                Node<T>* temp = node->left_child;
                delete node;
                return temp;
            }

            // Si tiene dos hijos, se busca la rama más a la izquierda de la rama derecha del nodo a eliminar. Aún se preserva el orden.
            Node<T>* temp = findMin(node->right_child);

            // Reemplazar el valor del nodo por el del sucesor
            node->data = temp->data;

            // Eliminar el sucesor in-order
            node->right_child = remove(node->right_child, temp->data);
        }

        return node;
    }

    // Función para encontrar el nodo con el valor mínimo (sucesor in-order)
    Node<T>* findMin(Node<T>* node) {
        while (node->left_child != nullptr) {
            node = node->left_child;
        }
        return node;
    }

    void preorder(Node<T>* root){
        if (root == nullptr) return;
        std::cout<<root->data<<' ';
        preorder(root->left_child);
        preorder(root->right_child);
    }

    void inorder(Node<T>* root){
        if (root == nullptr) return;
        inorder(root->left_child);
        std::cout<<root->data<<' ';
        inorder(root->right_child);
    }

    void postorder(Node<T>* root){
        if (root == nullptr) return;
        postorder(root->left_child);
        postorder(root->right_child);
        std::cout<<root->data<<' ';
    }

public:
    BSTree(): root(nullptr){}

    bool isEmpty() const{
        return (root == nullptr);
    }

    bool search(T value) {
        return search(root, value); // Llamada inicial desde la raíz
    }

    void insert(T value) {
        root = insert(root, value); // Llamada inicial desde la raíz
    }

    void remove(T value) {
        root = remove(root, value);
    }

    void preorder(){
        preorder(this->root);
    }

    void inorder(){
        inorder(this->root);
    }

    void postorder(){
        postorder(this->root);
    }
};


#endif //FINAL_CPP_ARBOL_H

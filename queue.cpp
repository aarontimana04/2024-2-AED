#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Nodo {
    T valor;
    Nodo<T>* siguiente;
    Nodo() : valor(T()), siguiente(nullptr) {};
    Nodo(const T& val) : valor(val), siguiente(nullptr) {};
};

template <typename T>
class iter_queue {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    iter_queue() : cabeza(nullptr), cola(nullptr) {}

    ~iter_queue() {
        while (!empty()) {
            pop();
        }
    }

    // Verifica si la cola está vacía
    bool empty() const {
        return cabeza == nullptr;
    }

    // Devuelve el tamaño de la cola
    int tamanio() const {
        Nodo<T>* temp = cabeza;
        int contador = 0;
        while (temp != nullptr) {
            contador++;
            temp = temp->siguiente;
        }
        return contador;
    }

    // Inserta un valor en la cola
    void push(const T& valor) {
        Nodo<T>* nnodo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = nnodo;
            cola = nnodo;
        } else {
            cola->siguiente = nnodo;
            cola = nnodo;
        }
    }

    // Devuelve el primer nodo de la cola
    T front() const {
        if (!empty()) {
            return cabeza->valor;
        }
        throw runtime_error("Queue vacía.");
    }

    // Devuelve el último nodo de la cola
    Nodo<T>* back() const {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return nullptr;
        } else {
            return cola;
        }
    }

    // Elimina el primer nodo de la cola
    void pop() {
        if (empty()) {
            cout << "Queue vacía." << endl;
            return;
        }

        Nodo<T>* temp = cabeza;
        cabeza = cabeza->siguiente;
        if (cabeza == nullptr) {
            cola = nullptr;
        }
        delete temp;
    }

    // Imprime la cola
    void print() const {
        if (empty()) {
            cout << "Queue vacía" << endl;
            return;
        }
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};

/*
class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n);
        iter_queue<pair<int, int>> q;  // Usamos iter_queue en lugar de queue

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            q.push({i, 1});
            while (!q.empty()) {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();
                
                for (auto& adj : g[node]) {
                    if (adj == node) continue; // Ignorar auto-bucle
                    if (vis[adj] == color) return false; // Conflicto de colores, no es bipartito
                    if (vis[adj]) continue;
                    
                    vis[adj] = (color == 1) ? 2 : 1;
                    q.push({adj, vis[adj]});
                }
            }
        }
        return true;
    }
};

*/

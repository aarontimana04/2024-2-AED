#include <iostream>
#include <string> // xd
using namespace std;

// Función que recibe parámetro por valor (no modifica la variable original)
void sumaPorValor(int n) {
    n++;
    cout << "Dentro de sumaPorValor - valor: " << n << endl;
}

// Función que recibe parámetro por puntero (puede modificar la variable original)
void sumaPorPuntero(int* n) {
    (*n)++;
    cout << "Dentro de sumaPorPuntero - valor: " << *n << endl;
}

// Función que recibe parámetro por referencia (modifica la variable original)
void sumaPorReferencia(int& n) {
    n++;
    cout << "Dentro de sumaPorReferencia - valor: " << n << endl;
}

int main() {
    cout << "=== CONCEPTOS BÁSICOS DE PUNTEROS ===" << endl;
    
    // 1. VARIABLE NORMAL
    int k = 10;
    cout << "\n1. Variable normal:" << endl;
    cout << "   Valor de k: " << k << endl;
    cout << "   Direccion de k: " << &k << endl;
    
    // 2. PUNTERO SIMPLE
    cout << "\n2. Puntero simple:" << endl;
    int* ptrK = &k;  // ptrK almacena la dirección de memoria de k
    
    cout << "   Valor de k: " << k << endl;
    cout << "   Direccion almacenada en ptrK: " << ptrK << endl;
    cout << "   Valor apuntado por ptrK: " << *ptrK << endl;
    cout << "   Direccion del propio puntero: " << &ptrK << endl;
    
    // 3. MODIFICACIÓN A TRAVÉS DE PUNTEROS
    cout << "\n3. Modificando variable a través del puntero:" << endl;
    *ptrK = 105;  // Modificamos k indirectamente
    cout << "   Nuevo valor de k: " << k << endl;
    cout << "   Valor via puntero: " << *ptrK << endl;
    cout << "   ¿Son iguales? " << (k == *ptrK ? "Sí" : "No") << endl;
    
    // 4. PUNTERO DOBLE
    cout << "\n4. Puntero doble (puntero a puntero):" << endl;
    int** ptrDoble = &ptrK;  // Almacena la dirección del puntero ptrK
    
    cout << "   Direccion del puntero ptrK: " << ptrDoble << endl;
    cout << "   Direccion almacenada en ptrK: " << *ptrDoble << endl;
    cout << "   Valor final (k): " << **ptrDoble << endl;
    
    // 5. REFERENCIAS
    cout << "\n5. Referencias:" << endl;
    int& refK = k;  // refK es un alias de k
    cout << "   Valor via referencia: " << refK << endl;
    cout << "   Direccion de la referencia: " << &refK << endl;
    cout << "   ¿Misma direccion que k? " << (&refK == &k ? "Sí" : "No") << endl;
    
    // 6. COMPARACIÓN DE PASO DE PARÁMETROS
    cout << "\n6. Comparación de paso de parámetros:" << endl;
    k = 20;  // Reiniciamos k
    
    cout << "\n   Valor inicial de k: " << k << endl;
    
    cout << "\n   a) Paso por valor:" << endl;
    sumaPorValor(k);
    cout << "   Valor de k después: " << k << " (sin cambios)" << endl;
    
    cout << "\n   b) Paso por puntero:" << endl;
    sumaPorPuntero(&k);
    cout << "   Valor de k después: " << k << " (modificado)" << endl;
    
    cout << "\n   c) Paso por referencia:" << endl;
    sumaPorReferencia(k);
    cout << "   Valor de k después: " << k << " (modificado)" << endl;
    
    // 7. ARITMÉTICA DE PUNTEROS
    cout << "\n7. Aritmética de punteros:" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int* ptrArr = arr;  // Apunta al primer elemento
    
    cout << "   Array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "   Acceso via puntero:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "   arr[" << i << "] = " << *(ptrArr + i) << endl;
    }
    
    // 8. PUNTEROS NULOS Y VALIDACIÓN
    cout << "\n8. Punteros nulos y validación:" << endl;
    int* ptrNulo = nullptr;
    cout << "   Puntero nulo: " << ptrNulo << endl;
    
    if (ptrNulo != nullptr) {
        cout << "   Puntero válido, valor: " << *ptrNulo << endl;
    } else {
        cout << "   Puntero es nulo, no se puede desreferenciar" << endl;
    }
    
    cout << "\n=== RESUMEN DE CONCEPTOS ===" << endl;
    cout << "• Puntero: Variable que almacena una dirección de memoria" << endl;
    cout << "• Operador &: Obtiene la dirección de una variable" << endl;
    cout << "• Operador *: Desreferencia un puntero (accede al valor)" << endl;
    cout << "• Referencia: Alias de una variable existente" << endl;
    cout << "• Puntero doble: Puntero que apunta a otro puntero" << endl;
    
    return 0;
}

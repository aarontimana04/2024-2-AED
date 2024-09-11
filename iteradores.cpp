#include <iostream>
#include <vector>
#include <list>

int main() {
    // Vector con acceso aleatorio
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    std::cout << "Recorriendo vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " "; // Acceso a los elementos
    }
    std::cout << std::endl;

    // Lista con acceso bidireccional
    std::list<int> lst = {100, 200, 300, 400, 500};
    
    std::cout << "Recorriendo lista de adelante hacia atrás: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Recorriendo lista de atrás hacia adelante: ";
    for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::find

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    // Encontrar el valor 30 usando std::find
    auto it = std::find(vec.begin(), vec.end(), 30);
    
    if (it != vec.end()) {
        std::cout << "Elemento encontrado: " << *it << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }

    return 0;
}

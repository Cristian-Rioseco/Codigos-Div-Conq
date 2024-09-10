#include <iostream>
#include <algorithm>  // Necesario para std::sort
#include <chrono>
#include <random>
using namespace std::chrono;
using namespace std;

int main() {
    int datos[10] = {1,2,3,4,5,6,7,8,9,10};
    // Obtener el tamaño del arreglo
    int tamano = sizeof(datos) / sizeof(datos[0]);
    auto inicio = high_resolution_clock::now();
    // Ordenar el arreglo en orden ascendente
    std::sort(datos, datos + tamano);
    auto fin = high_resolution_clock::now();
    auto duración = duration_cast<microseconds>(fin - inicio);
    // Mostrar el resultado ordenado
    std::cout << "Números ordenados: ";
    for (int i = 0; i < tamano; ++i) {
        std::cout << datos[i] << " ";  // Imprimir cada número del arreglo
    }
    cout << "Tiempo de ejecución: " << duración.count() << " microsegundos" << endl;
    return 0;  // Indicar que el programa terminó correctamente
}

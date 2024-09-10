#include <iostream>
#include <chrono>
#include <random> //para implementar el codigo y generar un arreglo de numeros random
using namespace std::chrono;
using namespace std;

// Función para intercambiar la posición de dos elementos
void intercambiar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Función para imprimir un array
void imprimirArray(int array[], int tamaño) {
  for (int i = 0; i < tamaño; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void ordenamientoSeleccion(int array[], int tamaño) {
  for (int paso = 0; paso < tamaño - 1; paso++) {
    int indice_minimo = paso;
    for (int i = paso + 1; i < tamaño; i++) {

      // Para ordenar en orden descendente, cambia < a > en esta línea.
      // Selecciona el elemento mínimo en cada bucle.
      if (array[i] < array[indice_minimo])
        indice_minimo = i;
    }

    // Coloca el mínimo en la posición correcta
    intercambiar(&array[indice_minimo], &array[paso]);
  }
}

// Código principal
int main() {

  //donde se inserta la data
  int datos[10] = {1,2,3,4,5,6,7,8,9,10};

  int tamaño = sizeof(datos) / sizeof(datos[0]);
  
  //toma del tiempo
  auto inicio = high_resolution_clock::now();
  ordenamientoSeleccion(datos, tamaño);
  auto fin = high_resolution_clock::now();
  auto duración = duration_cast<microseconds>(fin - inicio);

  cout << "Array ordenado en Orden Ascendente:\n";
  cout << "Tiempo de ejecución: " << duración.count() << " microsegundos" << endl;
  imprimirArray(datos, tamaño);
}

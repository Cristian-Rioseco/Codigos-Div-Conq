#include <iostream>
#include <chrono> 
#include <random>
using namespace std;
using namespace std::chrono; 

// Función para intercambiar elementos
void intercambiar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int tamano) {
  for (int i = 0; i < tamano; i++)
    cout << arreglo[i] << " ";
  cout << endl;
}

// Función para encontrar el punto de partición
int particion(int arreglo[], int bajo, int alto) {
  // Selecciona el último elemento como pivote
  int pivote = arreglo[alto];
  // Puntero para el elemento mayor
  int i = (bajo - 1);

  // Recorre cada elemento del arreglo y lo compara con el pivote
  for (int j = bajo; j < alto; j++) {
    if (arreglo[j] <= pivote) {
      // Si se encuentra un elemento menor que el pivote, intercámbialo
      i++;
      intercambiar(&arreglo[i], &arreglo[j]);
    }
  }
  
  // Intercambia el pivote con el elemento mayor en i
  intercambiar(&arreglo[i + 1], &arreglo[alto]);
  
  // Retorna el punto de partición
  return (i + 1);
}

// Función Quicksort recursiva
void ordenamientoRapido(int arreglo[], int bajo, int alto) {
  if (bajo < alto) {
    // Encuentra el pivote tal que los elementos menores que el pivote están a la izquierda
    // y los elementos mayores están a la derecha
    int pi = particion(arreglo, bajo, alto);
    
    // Llama recursivamente a Quicksort para las sublistas
    ordenamientoRapido(arreglo, bajo, pi - 1);
    ordenamientoRapido(arreglo, pi + 1, alto);
  }
}

int main() {
  int datos[10] = {1,2,3,4,5,6,7,8,9,10};
  int tamano = sizeof(datos) / sizeof(datos[0]);
  // Inicia el reloj
  auto inicio = high_resolution_clock::now();
  // Ejecuta Quicksort
  ordenamientoRapido(datos, 0, tamano - 1);
  // Detiene el reloj
  auto fin = high_resolution_clock::now();
  // Calcula el tiempo transcurrido
  auto duracion = duration_cast<microseconds>(fin - inicio);
  // Imprime el arreglo ordenado
  cout << "Arreglo ordenado en orden ascendente: \n";
  imprimirArreglo(datos, tamano);
  // Imprime el tiempo de ejecución
  cout << "Tiempo tomado por QuickSort: " << duracion.count() << " microsegundos" << endl;
  return 0;
}


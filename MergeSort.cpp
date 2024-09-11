#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std::chrono;
using namespace std;

// Mezcla dos subarreglos L y M dentro de arr
void merge(int arr[], int p, int q, int r) {
  
  // Crea L ← A[p..q] y M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  
  // Utiliza std::vector para asignar arreglos dinámicamente
  vector<int> L(n1);
  vector<int> M(n2);
  
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
    
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
    
  // Mantén el índice actual de los subarreglos y del arreglo principal
  int i = 0, j = 0, k = p;
  
  // Mientras no lleguemos al final de L o M, elige el mayor entre
  // los elementos de L y M y colócalo en la posición correcta en A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  
  // Cuando se acaben los elementos en L o M,
  // toma los elementos restantes y colócalos en A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide el arreglo en dos subarreglos, ordénalos y luego mézclalos
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m es el punto donde el arreglo se divide en dos subarreglos
    int m = l + (r - l) / 2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // Mezcla los subarreglos ordenados
    merge(arr, l, m, r);
  }
}

// Imprime el arreglo
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

//Codigo extraido de :https://www.programiz.com/dsa/merge-sort
// Programa principal
int main() {

  int datos[10] = {1,2,3,4,5,6,7,8,9,10};

  auto start = high_resolution_clock::now();
  int size = sizeof(datos) / sizeof(datos[0]);
  mergeSort(datos, 0, size - 1);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
  cout << "Arreglo ordenado: \n";
  printArray(datos, size);
  return 0;
}

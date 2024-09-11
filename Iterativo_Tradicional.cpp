#include <iostream>
#include <vector>

using namespace std;

// Función para multiplicar dos matrices
void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size(); // Asumiendo que las matrices son cuadradas y de tamaño n x n

    // Itera sobre las filas de la matriz A
    for (int i = 0; i < n; ++i) {
        // Itera sobre las columnas de la matriz B
        for (int j = 0; j < n; ++j) {
            // Inicializa el elemento C[i][j] en 0
            C[i][j] = 0;
            // Calcula el valor de C[i][j] como la suma de productos de A[i][k] y B[k][j]
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para imprimir una matriz
void printmatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3; // Tamaño de la matriz (n x n)

    // Definir dos matrices A y B de tamaño n x n
    vector<vector<int>> A = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
                             
    vector<vector<int>> B = {{9, 8, 7},
                             {6, 5, 4},
                             {3, 2, 1}};
                             
    // Matriz C para almacenar el resultado de la multiplicación
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Multiplica las matrices A y B
    multiplyMatrices(A, B, C);

    // Imprime la matriz resultante C
    cout << "Resultado de la multiplicación de matrices:" << endl;
    printmatrix(C);

    return 0;
}

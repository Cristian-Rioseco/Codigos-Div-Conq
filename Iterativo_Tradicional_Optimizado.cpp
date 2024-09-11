#include <iostream>
#include <vector>

using namespace std;

// Función para transponer una matriz
void transposeMatrix(const vector<vector<int>>& B, vector<vector<int>>& B_T) {
    int n = B.size(); // Asumiendo que la matriz es cuadrada
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B_T[i][j] = B[j][i];
        }
    }
}

// Función para multiplicar dos matrices con la optimización de la transposición
void multiplyMatricesOptimized(const vector<vector<int>>& A, const vector<vector<int>>& B_T, vector<vector<int>>& C) {
    int n = A.size(); // Asumiendo que las matrices son cuadradas y de tamaño n x n

    // Itera sobre las filas de la matriz A
    for (int i = 0; i < n; ++i) {
        // Itera sobre las columnas de la matriz C (que corresponde a las filas de B_T)
        for (int j = 0; j < n; ++j) {
            // Inicializa el elemento C[i][j] en 0
            C[i][j] = 0;
            // Calcula el valor de C[i][j] como la suma de productos de A[i][k] y B_T[j][k]
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }
}

// Función para imprimir una matriz
void printMatrix(const vector<vector<int>>& matrix) {
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
                             
    // Crear matrices para almacenar la transposición de B y el resultado
    vector<vector<int>> B_T(n, vector<int>(n, 0));
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Transponer la matriz B
    transposeMatrix(B, B_T);

    // Multiplicar matrices A y la transposición de B
    multiplyMatricesOptimized(A, B_T, C);

    // Imprimir la matriz resultante C
    cout << "Resultado de la multiplicación de matrices optimizada:" << endl;
    printMatrix(C);

    return 0;
}

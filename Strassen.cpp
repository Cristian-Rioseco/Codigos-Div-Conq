#include <bits/stdc++.h>
#include <random> // para generar un arreglo de números aleatorios
using namespace std::chrono;
using namespace std;

#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4

// Función para imprimir una submatriz
void print(string display, vector<vector<int>> matrix,
		int start_row, int start_column, int end_row,
		int end_column)
{
	cout << endl << display << " =>" << endl;
	for (int i = start_row; i <= end_row; i++) {
		for (int j = start_column; j <= end_column; j++) {
			cout << setw(10);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;
}

// Función para sumar dos matrices
void add_matrix(vector<vector<int>> matrix_A,
				vector<vector<int>> matrix_B,
				vector<vector<int>>& matrix_C,
				int split_index)
{
	for (auto i = 0; i < split_index; i++)
		for (auto j = 0; j < split_index; j++)
			matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

// Función para multiplicar dos matrices usando el algoritmo de Strassen
vector<vector<int>> multiply_matrix(vector<vector<int>> matrix_A,
				vector<vector<int>> matrix_B)
{
	int col_1 = matrix_A[0].size();
	int row_1 = matrix_A.size();
	int col_2 = matrix_B[0].size();
	int row_2 = matrix_B.size();

	// Verificar que el número de columnas de A es igual al número de filas de B
	if (col_1 != row_2) {
		cout << "\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B\n";
		return {};
	}

	vector<int> result_matrix_row(col_2, 0);
	vector<vector<int>> result_matrix(row_1, result_matrix_row);

	if (col_1 == 1) // Caso base: matrices 1x1
		result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
	else {
		int split_index = col_1 / 2;

		// Crear matrices para almacenar los subresultados
		vector<int> row_vector(split_index, 0);
		vector<vector<int>> result_matrix_00(split_index, row_vector);
		vector<vector<int>> result_matrix_01(split_index, row_vector);
		vector<vector<int>> result_matrix_10(split_index, row_vector);
		vector<vector<int>> result_matrix_11(split_index, row_vector);

		vector<vector<int>> a00(split_index, row_vector);
		vector<vector<int>> a01(split_index, row_vector);
		vector<vector<int>> a10(split_index, row_vector);
		vector<vector<int>> a11(split_index, row_vector);
		vector<vector<int>> b00(split_index, row_vector);
		vector<vector<int>> b01(split_index, row_vector);
		vector<vector<int>> b10(split_index, row_vector);
		vector<vector<int>> b11(split_index, row_vector);

		// Dividir las matrices en submatrices
		for (auto i = 0; i < split_index; i++)
			for (auto j = 0; j < split_index; j++) {
				a00[i][j] = matrix_A[i][j];
				a01[i][j] = matrix_A[i][j + split_index];
				a10[i][j] = matrix_A[split_index + i][j];
				a11[i][j] = matrix_A[i + split_index][j + split_index];
				b00[i][j] = matrix_B[i][j];
				b01[i][j] = matrix_B[i][j + split_index];
				b10[i][j] = matrix_B[split_index + i][j];
				b11[i][j] = matrix_B[i + split_index][j + split_index];
			}

		// Calcular los productos de las submatrices
		add_matrix(multiply_matrix(a00, b00),
				multiply_matrix(a01, b10),
				result_matrix_00, split_index);
		add_matrix(multiply_matrix(a00, b01),
				multiply_matrix(a01, b11),
				result_matrix_01, split_index);
		add_matrix(multiply_matrix(a10, b00),
				multiply_matrix(a11, b10),
				result_matrix_10, split_index);
		add_matrix(multiply_matrix(a10, b01),
				multiply_matrix(a11, b11),
				result_matrix_11, split_index);

		// Combinar los resultados en la matriz final
		for (auto i = 0; i < split_index; i++)
			for (auto j = 0; j < split_index; j++) {
				result_matrix[i][j] = result_matrix_00[i][j];
				result_matrix[i][j + split_index] = result_matrix_01[i][j];
				result_matrix[split_index + i][j] = result_matrix_10[i][j];
				result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
			}

		// Liberar memoria
		result_matrix_00.clear();
		result_matrix_01.clear();
		result_matrix_10.clear();
		result_matrix_11.clear();
		a00.clear();
		a01.clear();
		a10.clear();
		a11.clear();
		b00.clear();
		b01.clear();
		b10.clear();
		b11.clear();
	}
	return result_matrix;
}

// codigo extraido de : https://www.geeksforgeeks.org/strassens-matrix-multiplication/
// Código principal para ejecutar el algoritmo de Strassen
int main()
{
    // Definición de matrices de entrada
    vector<vector<int>> matrix_A = {
        {14,  7,  23,  5,  18,  9,  6,  12},
        {3,  15,  8,  11,  7,  20,  13,  14},
        {21,  12,  9,  17,  8,  15,  7,  22},
        {6,  18,  11,  12,  9,  3,  20,  15},
        {17,  22,  5,  13,  19,  12,  14,  8},
        {10,  14,  8,  21,  13,  9,  16,  11},
        {9,  20,  15,  7,  22,  18,  6,  12},
        {13,  11,  19,  8,  14,  10,  16,  23}
    };

    vector<vector<int>> matrix_B = {
        {8,  12,  5,  9,  15,  6,  14,  11},
        {7,  20,  11,  13,  8,  17,  9,  12},
        {16,  9,  20,  14,  7,  18,  13,  15},
        {11,  5,  18,  9,  12,  14,  10,  16},
        {14,  11,  6,  13,  20,  8,  17,  12},
        {9,  12,  8,  7,  11,  16,  15,  19},
        {12,  10,  14,  16,  13,  17,  11,  20},
        {7,  13,  18,  12,  15,  20,  8,  14}
    };

    // Medir el tiempo de ejecución
    auto inicio = high_resolution_clock::now();
	vector<vector<int>> result_matrix = multiply_matrix(matrix_A, matrix_B);
    auto fin = high_resolution_clock::now();
    auto duración = duration_cast<microseconds>(fin - inicio);

    // Imprimir la matriz resultante y el tiempo de ejecución
    print("Result Array", result_matrix, 0, 0, ROW_1 - 1, COL_2 - 1);
    cout << "Tiempo de ejecución: " << duración.count() << " microsegundos" << endl;
}

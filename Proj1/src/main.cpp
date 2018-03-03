#include "matrix.hpp"

#include <iostream>

using namespace std;


static void FillMatrix(Matrix &matrix);
static void PrintMatrix(Matrix &matrix);


int main(int argc, char const *argv[]) {
    size_t num_rows_A = 10;
    size_t num_cols_A = 10;
    size_t num_rows_B = 10;
    size_t num_cols_B = 10;

    Matrix matrix_A(num_rows_A, num_cols_A);
    FillMatrix(matrix_A);

    Matrix matrix_B(num_rows_B, num_cols_B);
    FillMatrix(matrix_B);

    cout << "Matrix A" << endl;
    PrintMatrix(matrix_A);

    return 0;
}

static void FillMatrix(Matrix &matrix) {
    for (size_t i = 0; i < matrix.num_rows; i++) {
        for (size_t j = 0; j < matrix.num_cols; j++) {
            matrix(i, j) = 1.0;
        }
    }
}

static void PrintMatrix(Matrix &matrix) {
    for (size_t i = 0; i < matrix.num_rows; i++) {
        for (size_t j = 0; j < matrix.num_cols; j++) {
            cout << matrix(i, j);
        }
        cout << endl;
    }

    cout << endl;
}

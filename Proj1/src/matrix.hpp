#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <cstddef>
#include <iostream>
#include <iomanip>

using namespace std;


class Matrix {
private:
    int *matrix_values;

public:
    size_t num_rows;
    size_t num_cols;

    Matrix(size_t num_rows, size_t num_cols);
    ~Matrix();

    int getMatrixValue(int index);
    void setMatrixValue(int index, int n);

    void fill();
    void fillZeros();
    void print();

    Matrix *basic_multiply(Matrix *matrix_B);
};

#endif // MATRIX_HPP_

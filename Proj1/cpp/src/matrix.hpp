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

    inline int &operator()(size_t row, size_t column) {
        return matrix_values[row * num_cols + column];
    }

    inline int operator()(size_t row, size_t column) const {
        return matrix_values[row * num_cols + column];
    }

    Matrix(size_t num_rows, size_t num_cols);
    ~Matrix();

    void fill(Matrix *matrix);
    void fill_zeros(Matrix *matrix);
    void print(Matrix *matrix);

    Matrix *basic_multiply(Matrix *matrix_A, Matrix *matrix_B);
    Matrix *line_multiply(Matrix *matrix_A, Matrix *matrix_B);
};

#endif // MATRIX_HPP_

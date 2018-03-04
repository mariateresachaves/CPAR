#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <cstddef>
#include <iostream>

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
    void print();
};

#endif // MATRIX_HPP_

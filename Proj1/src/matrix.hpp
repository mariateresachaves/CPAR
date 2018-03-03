#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <cstddef>
#include <ostream>
#include <iostream>

using namespace std;


class Matrix {
private:
    double *matrix_values;

public:
    size_t num_rows;
    size_t num_cols;

    inline double &operator()(size_t row, size_t column) {
        return matrix_values[row*column + column];
    }

    inline double operator()(size_t row, size_t column) const {
        return matrix_values[row*column + column];
    }

    Matrix(size_t num_rows, size_t num_cols);
    ~Matrix();
};

#endif // MATRIX_HPP_

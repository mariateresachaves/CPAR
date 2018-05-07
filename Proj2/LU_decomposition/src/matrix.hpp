#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <cstddef>
#include <iostream>
#include <iomanip>

using namespace std;


class Matrix {
private:
    double *matrix_values;

public:
    size_t num_rows;
    size_t num_cols;

    inline double &operator()(size_t row, size_t column) {
        return matrix_values[row * num_cols + column];
    }

    inline double operator()(size_t row, size_t column) const {
        return matrix_values[row * num_cols + column];
    }

    /**
     * Matrix constructor
     * @param num_rows Number of rows
     * @param num_cols Number of columns
     */
    Matrix(size_t num_rows, size_t num_cols);

    /**
     * Matrix destructor
     */
    ~Matrix();

    /**
     * Get the matrix values
     * @return Matrix values
     */
    double *get_values() {
        return matrix_values;
    }

    /**
     * Set the matrix values
     * @param values Values of the matrix
     */
    void set_values(double *values) {
        matrix_values = values;
    }

    /**
     * Fills the matrix with random numbers between 1 and 100
     * @param matrix Matrix to fill
     */
    void fill(Matrix *matrix);

    /**
     * Fills the matrix with zeros
     * @param matrix Matrix to fill
     */
    void fill_zeros(Matrix *matrix);

    /**
     * Print the matrix on a user friendly way
     * @param matrix Matrix to print
     */
    void print(Matrix *matrix);

    /**
     * Multiply matrix A by matrix B
     * @param  matrix_A Matrix A
     * @param  matrix_B Matrix B
     * @return          Result matrix of the multiplication
     */
    Matrix *line_multiply(Matrix *matrix_A, Matrix *matrix_B);
};

#endif // MATRIX_HPP_

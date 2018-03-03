#include "matrix.hpp"

using namespace std;


Matrix::Matrix(size_t num_rows_, size_t num_cols_) {
    if(num_rows_ <= 0)
        cerr << "[invalid_argument] Number of rows must be greater than zero." << endl;

    if(num_cols_ <= 0)
        cerr << "[invalid_argument]Number of columns must be greater than zero." << endl;

    num_rows = num_rows_;
    num_cols = num_cols_;

    matrix_values = new double[num_rows*num_cols];
}

Matrix::~Matrix() { delete[] matrix_values; }

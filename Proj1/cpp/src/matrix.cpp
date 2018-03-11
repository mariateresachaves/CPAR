#include "matrix.hpp"

using namespace std;


Matrix::Matrix(size_t num_rows_, size_t num_cols_) {
    if(num_rows_ <= 0) {
        cerr << "[Wrong_Args] Number of rows must be greater than zero" << endl;
        exit(1);
    }

    if(num_cols_ <= 0){
        cerr << "[Wrong_Args] Number of columns must be greater than zero" << endl;
        exit(1);
    }

    num_rows = num_rows_;
    num_cols = num_cols_;

    matrix_values = new int[num_rows*num_cols];
}

Matrix::~Matrix() { delete[] matrix_values; }

void Matrix::fill(Matrix *matrix) {
    for(size_t i = 0; i < num_rows; i++) {
        for(size_t j = 0; j < num_cols; j++) {
            (*matrix)(i,j) = (rand() % 100 + 1); //random number between 1 and 100
        }
    }
}

void Matrix::fillZeros(Matrix *matrix) {
    for(size_t i = 0; i < num_rows; i++) {
        for(size_t j = 0; j < num_cols; j++) {
            (*matrix)(i,j) = 0; //random number between 1 and 100
        }
    }
}

void Matrix::print(Matrix *matrix) {
    for(size_t i = 0; i < num_rows; i++) {
        for(size_t j = 0; j < num_cols; j++) {
            if(i==0 && j==0)
                cout << "[[" << (*matrix)(i,j) << ",";

            else if(j==0)
                cout << " [" << (*matrix)(i,j) << ",";

            else if(j==num_cols-1 && i==num_rows-1)
                cout << (*matrix)(i,j) << "]]";

            else if(j==num_cols-1)
                cout << (*matrix)(i,j) << "]";

            else
                cout << (*matrix)(i,j) << ",";
        }
        cout << endl;
    }

    cout << endl;
}

Matrix *Matrix::basic_multiply(Matrix *matrix_A, Matrix *matrix_B) {
    Matrix *result = new Matrix(matrix_A->num_rows, matrix_B->num_cols);
    fillZeros(result);

    for(size_t i=0; i<matrix_A->num_rows; i++) {
        for(size_t j=0; j<matrix_B->num_cols; j++) {
            int cell_result = 0;
            for(size_t k=0; k<matrix_A->num_cols; k++) {
                cell_result += (*matrix_A)(i,k) * (*matrix_B)(k,j);
            }
            (*result)(i,j) = cell_result;
        }
    }

    return result;
}

Matrix *Matrix::line_multiply(Matrix *matrix_A, Matrix *matrix_B) {
    Matrix *result = new Matrix(matrix_A->num_rows, matrix_B->num_cols);
    fillZeros(result);

    for(size_t i=0; i<matrix_A->num_rows; i++) {
        for(size_t k=0; k<matrix_A->num_cols; k++) {
            for(size_t j=0; j<matrix_B->num_cols; j++) {
                (*result)(i,j) += (*matrix_A)(i,k) * (*matrix_B)(k,j);
            }
        }
    }

    return result;
}

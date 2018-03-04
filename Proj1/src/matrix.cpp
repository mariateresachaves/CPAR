#include "matrix.hpp"

using namespace std;


Matrix::Matrix(size_t num_rows_, size_t num_cols_) {
    if(num_rows_ <= 0) {
        cerr << "[Wrong_Args] Number of rows must be greater than zero." << endl;
        exit(1);
    }

    if(num_cols_ <= 0){
        cerr << "[Wrong_Args] Number of columns must be greater than zero." << endl;
        exit(1);
    }

    num_rows = num_rows_;
    num_cols = num_cols_;

    matrix_values = new int[num_rows*num_cols];
}

Matrix::~Matrix() { delete[] matrix_values; }

void Matrix::fill() {
    for (size_t i = 0; i < num_rows; i++) {
        for (size_t j = 0; j < num_cols; j++) {
            setMatrixValue((i*j + j), (rand() % 100 + 1)); //random number between 1 and 100
        }
    }
}

void Matrix::print() {
    for (size_t i = 0; i < num_rows; i++) {
        for (size_t j = 0; j < num_cols; j++) {
            if(i==0 && j==0)
                cout << "[[" << getMatrixValue(i*j + j) << ",";

            else if(j==0)
                cout << " [" << getMatrixValue(i*j + j) << ",";

            else if(j==num_cols-1 && i==num_rows-1)
                cout << getMatrixValue(i*j + j) << "]]";

            else if(j==num_cols-1)
                cout << getMatrixValue(i*j + j) << "]";

            else
                cout << getMatrixValue(i*j + j) << ",";
        }
        cout << endl;
    }

    cout << endl;
}

int Matrix::getMatrixValue(int index) {
    return matrix_values[index];
}

void Matrix::setMatrixValue(int index, int n) {
    matrix_values[index] = n;
}

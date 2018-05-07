#ifndef MAIN_HPP_
#define MAIN_HPP_

#include "matrix.hpp"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <mpi.h>
#include <vector>

using namespace std;

#define FROM_MASTER 1
#define FROM_WORKER 2

string file_name;
string l_file_name;
string u_file_name;
size_t op = 0;
size_t size = 0;
MPI_Status status;

struct timespec t_start, t_stop;

namespace util {
    template <typename T> std::string to_string(const T& t) {
        std::string str {std::to_string (t)};
        int offset{1};

        if (str.find_last_not_of('0') == str.find('.')) {
            offset = 0;
        }

        str.erase(str.find_last_not_of('0') + offset, std::string::npos);

        return str;
    }
}

/**
 * Checks the righteness of the arguments passed
 * @param  argc Number of arguments
 * @param  argv Array with the arguments passed
 * @return      True if the arguments are right and false otherwise
 */
static bool right_args(int argc, char const *argv[]);

/**
 * Initialize matrices m, l and u with zeros
 * @param m Matrix m
 * @param l Matrix l
 * @param u Matrix u
 */
static void init_matrices(Matrix *m, Matrix *l, Matrix *u);

/**
 * Create csv file names depending on the size
 */
static void init_csv_filenames();

/**
 * Reads csv file regarding the matrix m and
 * initializes matrix m with the corresponding values
 * @param m Matrix m
 */
static void parse_csv(Matrix *m);

/**
 * Creates a csv file with a random matrix of size matrix_size
 * @param file_name   File name
 * @param matrix_size Size of the matrix
 */
void print_matrixes_csv(const char *file_name, size_t matrix_size);

/**
 * Print the execution time
 */
static void print_execution_time();

/**
 * Computes doolittle lu decomposition algorithm sequential mode
 * @param m Matrix m
 * @param l Matrix l
 * @param u Matrix u
 */
static void lu_decomposition_sequential(Matrix *m, Matrix *l, Matrix *u);

/**
 * Computes doolittle lu decomposition algorithm using OpenMP
 * @param m Matrix m
 * @param l Matrix l
 * @param u Matrix u
 */
static void lu_decomposition_OMP(Matrix *m, Matrix *l, Matrix *u);

/**
 * Computes doolittle lu decomposition algorithm using MPI
 * @param m Matrix m
 * @param l Matrix l
 * @param u Matrix u
 */
static void lu_decomposition_MPI(Matrix *m, Matrix *l, Matrix *u);

/**
 * Prints l and u matrices into corresponding files.
 * @param l Matrix l
 * @param u Matrix u
 */
static void print_results(Matrix *l, Matrix *u);

#endif // MATRIX_HPP_

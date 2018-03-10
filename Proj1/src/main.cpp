#include "matrix.hpp"
#include "papi.hpp"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <ctime>

#define M 1000000
#define MX 1024

using namespace std;

size_t size_A;
size_t size_B;

static bool right_args(int argc, char const *argv[]);
static bool right_sizes(char const *argv[]);


int main(int argc, char const *argv[]) {
    Papi papi = Papi();

    papi.Init();
    papi.InstallEvents();

    if(!right_args(argc, argv))
        exit(1);

    if(!right_sizes(argv))
        exit(1);

    float tot_FLOPS = 2*MX*MX*size_A;

    Matrix *matrix_A = new Matrix(size_A, size_A);
    matrix_A->fill(matrix_A);

    Matrix *matrix_B = new Matrix(size_B, size_B);
    matrix_B->fill(matrix_B);

    cout << "Basic Multiplication" << endl;

    clock_t begin = clock();

    papi.Start();

    // Gets the start time in clock cycles
    long long basic_start_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    long long basic_start_usec = papi.GetRealuSec();

    // Matrix *basic_result = matrix_A->basic_multiply(matrix_A, matrix_B);
    matrix_A->basic_multiply(matrix_A, matrix_B);

    // Gets the end time in clock cycles
    long long basic_end_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    long long basic_end_usec = papi.GetRealuSec();

    papi.StopAndReset();

    clock_t end = clock();

    cout << "MFlop/s = " << (tot_FLOPS/M)/(end-begin) << endl
         << "Time (clock cycles) = "
         << (basic_end_cycles - basic_start_cycles) << endl
         << "Time (seconds) = "
         << (basic_end_usec - basic_start_usec)*pow(10,-6) << endl
         << endl;

    cout << "Line Multiplication" << endl;

    clock_t begin2 = clock();

    papi.Start();

    // Gets the start time in clock cycles
    long long line_start_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    long long line_start_usec = papi.GetRealuSec();

    //Matrix *line_result = matrix_A->line_multiply(matrix_A, matrix_B);
    matrix_A->line_multiply(matrix_A, matrix_B);

    // Gets the end time in clock cycles
    long long line_end_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    long long line_end_usec = papi.GetRealuSec();

    papi.StopAndReset();

    clock_t end2 = clock();

    cout << "MFlop/s = " << (tot_FLOPS/M)/(end2-begin2) << endl
         << "Time (clock cycles) = "
         << (line_end_cycles - line_start_cycles) << endl
         << "Time (seconds) = "
         << (line_end_usec - line_start_usec)*pow(10,-6) << endl
         << endl;

    // Test Matrix Values
    /*cout << "Matrix A" << endl;
    matrix_A->print(matrix_A);
    cout << "Matrix B" << endl;
    matrix_A->print(matrix_B);
    cout << "Matrix AxB [BASIC]" << endl;
    matrix_A->print(basic_result);
    cout << "Matrix AxB [LINE]" << endl;
    matrix_A->print(line_result);*/

    return 0;
}

static bool right_args(int argc, char const *argv[]) {
    if(argc != 3) {
        cerr << "[Wrong_Args] usage: " << argv[0] << " "
             << "<size_matrix_A> <size_matrix_B>" << endl
             << "\t Where:" << endl
             << "\t\t <size_matrix_A> - matrix size_matrix_A x size_matrix_A"
             << endl
             << "\t\t <size_matrix_B> - matrix size_matrix_B x size_matrix_B"
             << endl;
        return false;
    }

    return true;
}

static bool right_sizes(char const *argv[]) {
    istringstream s_A(argv[1]);
    istringstream s_B(argv[2]);

    if(!(s_A >> size_A) || !(s_B >> size_B)) {
        cerr
            << "[Wrong_Args] <size_matrix_A> and <size_matrix_B> must be integers"
            << endl;
        return false;
    }

    return true;
}

#include "matrix.hpp"
#include "papi.hpp"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <math.h>

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

    Matrix *matrix_A = new Matrix(size_A, size_A);
    matrix_A->fill();

    Matrix *matrix_B = new Matrix(size_B, size_B);
    matrix_B->fill();

    papi.Start();

    // Gets the start time in clock cycles
    long start_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    long start_usec = papi.GetRealuSec();

    Matrix *result = matrix_A->basic_multiply(matrix_B);

    // Gets the end time in clock cycles
    long end_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    long end_usec = papi.GetRealuSec();

    papi.StopAndReset();

    cout << setw(8) << "" << setw(15) << "CLOCK CYCLES"
                          << setw(10) << "SECONDS" << endl;
    cout << setw(8) << "TIME" << setw(15) << (end_cycles - start_cycles)
                              << setw(10) << (end_usec - start_usec)*pow(10,-6) << endl;

    cout << endl;


    // Test Matrix Values
    /*cout << "Matrix A" << endl;
    matrix_A->print();
    cout << "Matrix B" << endl;
    matrix_B->print();
    cout << "Matrix AxB" << endl;
    result->print();*/

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

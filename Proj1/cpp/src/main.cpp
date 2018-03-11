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
int algorithm;

float tot_FLOPS;

clock_t begin_time;
clock_t end_time;

long long start_cycles;
long long end_cycles;

long long start_usec;
long long end_usec;

static bool right_args(int argc, char const *argv[]);
static bool right_sizes(char const *argv[]);
static bool right_algorithm(char const *argv[]);
static void printTimes();

int main(int argc, char const *argv[]) {
    Papi papi = Papi();

    papi.Init();
    papi.InstallEvents();

    if(!right_args(argc, argv))
        exit(1);

    if(!right_sizes(argv))
        exit(2);

    if(!right_algorithm(argv))
        exit(3);

    tot_FLOPS = 2*MX*MX*size_A;

    Matrix *matrix_A = new Matrix(size_A, size_A);
    matrix_A->fill(matrix_A);

    Matrix *matrix_B = new Matrix(size_B, size_B);
    matrix_B->fill(matrix_B);

    begin_time = clock();

    papi.Start();

    // Gets the start time in clock cycles
    start_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    start_usec = papi.GetRealuSec();

    switch (algorithm) {
        case 1:
        cout << "Basic Matrix Multiplication" << endl;
        // Matrix *basic_result = matrix_A->basic_multiply(matrix_A, matrix_B);
        matrix_A->basic_multiply(matrix_A, matrix_B);
        break;

        case 2:
        cout << "Line Matrix Multiplication" << endl;
        //Matrix *line_result = matrix_A->line_multiply(matrix_A, matrix_B);
        matrix_A->line_multiply(matrix_A, matrix_B);
        break;

        default:
        cerr << "Invalid Algorithm" << endl;
        break;
    }

    // Gets the end time in clock cycles
    end_cycles = papi.GetRealCycles();

    // Gets the start time in microseconds cycles
    end_usec = papi.GetRealuSec();

    papi.StopAndReset();

    end_time = clock();

    printTimes();

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
    if(argc != 4) {
        cerr << "[Wrong_Args] usage: " << argv[0] << " "
             << "<algorithm> <size_matrix_A> <size_matrix_B>" << endl
             << "\t Where:" << endl
             << "\t\t <algorithm> - type of algorithm to apply" << endl
             << "\t\t <size_matrix_A> - matrix size_matrix_A x size_matrix_A"
             << endl
             << "\t\t <size_matrix_B> - matrix size_matrix_B x size_matrix_B"
             << endl;
        return false;
    }

    return true;
}

static bool right_sizes(char const *argv[]) {
    istringstream s_A(argv[2]);
    istringstream s_B(argv[3]);

    if(!(s_A >> size_A) || !(s_B >> size_B)) {
        cerr
            << "[Wrong_Args] <size_matrix_A> and <size_matrix_B> must be integers"
            << endl;
        return false;
    }

    return true;
}

static bool right_algorithm(char const *argv[]) {
    istringstream s_algorithm(argv[1]);

    if(!(s_algorithm >> algorithm)) {
        cerr
            << "[Wrong_Args] <algorithm> must be an integer"
            << endl;
        return false;
    }

    return true;
}

static void printTimes() {
    cout << "MFLOP/s = " << (tot_FLOPS/M)/(end_time-begin_time) << endl
         << "Time (seconds) = "
         << (end_usec - start_usec)*pow(10,-6) << endl;
}

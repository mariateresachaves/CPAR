#ifndef MAIN_HPP_
#define MAIN_HPP_

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

#define BLOCK_LOW(i, n, p) ((i)*(n)/(p))
#define BLOCK_HIGH(i, n, p) (BLOCK_LOW((i)+1,n,p)-1)
#define BLOCK_SIZE(i, n, p) (BLOCK_LOW((i)+1,n,p)-BLOCK_LOW(i,n,p))

string se_file_name;
size_t op = 0;
size_t n;
int *primes;
MPI_Status status;
vector<bool> sieved_vector;

struct timespec t_start, t_stop;

/**
 * Checks the righteness of the arguments passed
 * @param  argc Number of arguments
 * @param  argv Array with the arguments passed
 * @return      True if the arguments are right and false otherwise
 */
static bool right_args(int argc, char const *argv[]);

/**
 * Print the execution time
 */
static void print_execution_time();

/**
 * Finds all prime numbers up to n using Sieve Eratosthenes algorithm
 */
static void sieve_eratosthenes_sequential();

/**
 * Finds all prime numbers up to n using Sieve Eratosthenes algorithm
 * using OpenMP
 */
static void sieve_eratosthenes_OMP();

/**
 * Finds all prime numbers up to n using Sieve Eratosthenes algorithm
 * using MPI
 */
static void sieve_eratosthenes_MPI();

/**
 * Print Sieve Eratosthenes results into corresponding file
 */
static void print_results();

/**
 * Count the number of primes numbers founded
 * @return Return the number of prime numbers
 */
static size_t count_primes();

#endif // MATRIX_HPP_

# Parallel Computing

# Project 1

## Performance Evaluation

In this project we will study the effect on the processor performance of the memory hierarchy when accessing large amounts of data. The product of two matrices will be used for this study. 

**1.** Implement the basic matrix  multiplication algorithm in C/C++,  i.e. the  algorithm  that multiplies one  line  of  the  first  matrix  by  each  column  of  the  second matrix. Implement  the same algorithm in other programming languages, such as JAVA, C#, Python, etc.

Register the  processing  time  for  the several implementations of  the  algorithm,  for  input matrices from 500x500 to 3000x3000 elements with increments in both dimensions of 500. Use the Performance API (PAPI) and Tiptop to collect relevant performance indicators of the program execution.

**2.** Implement  a C/C++ version  that  multiplies  an  element  from  the  first  matrix  by  the correspondent line of the second matrix.

Register the  processing  time  for  the two versions  of  the  algorithm,  for  input  matrices  from 500x500 to 3000x3000 elements with increments in both dimensions of 500.

Register the processing time from 5000x5000 to 10000x10000 with intervals of 1000.

Use PAPI and Tiptop to collect relevant performance indicators of the program execution.

**3.** Implement a parallel version of the two versions of the algorithm in C/C++ using OpenMP.

Register  the  processing time  for  input  matrices  from 500x500  to  3000x3000  elements with increments in both dimensions of 500 and using from 1 to 8 threads.

Use PAPI and Tiptop to collect relevant performance indicators of the program execution.

# Project 2

## Implementation and Performance Analysis of LU Decomposition and Sieve of Eratosthenes

Implement and evaluate serial and parallel versions of the following algorithms.

**1. LU  decomposition**

LU decomposition is  used  to solve systems  of  linear  equations,  as  a  key  step  when  inverting  a matrix,  or when computing  the  determinant  of  a  matrix.  Given  a  square  matrix A, LU decomposition factors matrix A as the product of a lower triangular matrix and an upper triangular matrix (A=LU).

Data range to consider (n): from 1,000 to 6,000, with a step of 1,000.

The application must receive  as  input  the  name  of  a CSV  file  storing  the input matrix A.  (e.g.,ludecomp A.csv) and must store the resulting L and U matrices in CSV files (L.csv and U.csv).

**2. The Sieve of Eratosthenes**

The Sieve of Eratosthenes is a simple algorithm that can be used to find all the prime numbers up to a given number N.

Data range to consider (n): from 100,000,000 to 600,000,000, with a step of 100,000,000.

The application must receive as input the maximum number to consider for primality testand must store the numbers found to be primes in a single line in a CSV file (primes.csv).

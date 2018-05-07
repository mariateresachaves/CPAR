#!/usr/bin/env bash

# Compile C++ code
make clean >/dev/null
make >/dev/null

echo "Running Sieve of Eratosthenes sequential..."
for i in $(seq 5); do ./bin/sieve_eratosthenes 1 100000000 >> results/SEQ/SE_100000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 1 200000000 >> results/SEQ/SE_200000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 1 300000000 >> results/SEQ/SE_300000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 1 400000000 >> results/SEQ/SE_400000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 1 500000000 >> results/SEQ/SE_500000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 1 600000000 >> results/SEQ/SE_600000000.txt; done

echo "Running Sieve of Eratosthenes OpenMP..."
echo ""
echo "Running with 1 thread..."
export OMP_NUM_THREADS=1
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 100000000 >> results/OMP/1T/SE_100000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 200000000 >> results/OMP/1T/SE_200000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 300000000 >> results/OMP/1T/SE_300000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 400000000 >> results/OMP/1T/SE_400000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 500000000 >> results/OMP/1T/SE_500000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 600000000 >> results/OMP/1T/SE_600000000.txt; done
echo ""
echo "Running with 2 threads..."
export OMP_NUM_THREADS=2
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 100000000 >> results/OMP/2T/SE_100000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 200000000 >> results/OMP/2T/SE_200000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 300000000 >> results/OMP/2T/SE_300000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 400000000 >> results/OMP/2T/SE_400000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 500000000 >> results/OMP/2T/SE_500000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 600000000 >> results/OMP/2T/SE_600000000.txt; done
echo ""
echo "Running with 4 threads..."
export OMP_NUM_THREADS=4
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 100000000 >> results/OMP/4T/SE_100000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 200000000 >> results/OMP/4T/SE_200000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 300000000 >> results/OMP/4T/SE_300000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 400000000 >> results/OMP/4T/SE_400000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 500000000 >> results/OMP/4T/SE_500000000.txt; done
for i in $(seq 5); do ./bin/sieve_eratosthenes 2 600000000 >> results/OMP/4T/SE_600000000.txt; done

echo "Running Sieve of Eratosthenes MPI..."
for i in $(seq 5); do mpiexec -np 5 ./bin/sieve_eratosthenes 3 100000000 >> results/MPI/SE_100000000.txt; done
for i in $(seq 5); do mpiexec -np 5 ./bin/sieve_eratosthenes 3 200000000 >> results/MPI/SE_200000000.txt; done
for i in $(seq 5); do mpiexec -np 5 ./bin/sieve_eratosthenes 3 300000000 >> results/MPI/SE_300000000.txt; done
for i in $(seq 5); do mpiexec -np 5 ./bin/sieve_eratosthenes 3 400000000 >> results/MPI/SE_400000000.txt; done
for i in $(seq 5); do mpiexec -np 5 ./bin/sieve_eratosthenes 3 500000000 >> results/MPI/SE_500000000.txt; done
for i in $(seq 5); do mpiexec -np 5 ./bin/sieve_eratosthenes 3 600000000 >> results/MPI/SE_600000000.txt; done

echo "Processing data..."
python process_data.py

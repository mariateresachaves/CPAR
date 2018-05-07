#!/usr/bin/env bash

# Compile C++ code
make clean >/dev/null
make >/dev/null

echo "Running LU Decomposition sequential..."
for i in $(seq 5); do ./bin/lu_decomposition 1 1000 >> results/SEQ/A_1000x1000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 1 2000 >> results/SEQ/A_2000x2000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 1 3000 >> results/SEQ/A_3000x3000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 1 4000 >> results/SEQ/A_4000x4000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 1 5000 >> results/SEQ/A_5000x5000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 1 6000 >> results/SEQ/A_6000x6000.txt; done

echo "Running LU Decomposition OMP..."
echo ""
echo "Running with 1 thread..."
export OMP_NUM_THREADS=1
for i in $(seq 5); do ./bin/lu_decomposition 2 1000 >> results/OMP/1T/A_1000x1000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 2000 >> results/OMP/1T/A_2000x2000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 3000 >> results/OMP/1T/A_3000x3000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 4000 >> results/OMP/1T/A_4000x4000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 5000 >> results/OMP/1T/A_5000x5000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 6000 >> results/OMP/1T/A_6000x6000.txt; done
echo ""
echo "Running with 2 threads..."
export OMP_NUM_THREADS=2
for i in $(seq 5); do ./bin/lu_decomposition 2 1000 >> results/OMP/2T/A_1000x1000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 2000 >> results/OMP/2T/A_2000x2000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 3000 >> results/OMP/2T/A_3000x3000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 4000 >> results/OMP/2T/A_4000x4000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 5000 >> results/OMP/2T/A_5000x5000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 6000 >> results/OMP/2T/A_6000x6000.txt; done
echo ""
echo "Running with 4 thread..."
export OMP_NUM_THREADS=4
for i in $(seq 5); do ./bin/lu_decomposition 2 1000 >> results/OMP/4T/A_1000x1000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 2000 >> results/OMP/4T/A_2000x2000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 3000 >> results/OMP/4T/A_3000x3000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 4000 >> results/OMP/4T/A_4000x4000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 5000 >> results/OMP/4T/A_5000x5000.txt; done
for i in $(seq 5); do ./bin/lu_decomposition 2 6000 >> results/OMP/4T/A_6000x6000.txt; done

# echo "Running LU Decomposition MPI..."
for i in $(seq 5); do mpiexec -np 10 ./bin/lu_decomposition 3 1000 >> results/MPI/A_1000x1000.txt; done
for i in $(seq 5); do mpiexec -np 10 ./bin/lu_decomposition 3 2000 >> results/MPI/A_2000x2000.txt; done
for i in $(seq 5); do mpiexec -np 10 ./bin/lu_decomposition 3 3000 >> results/MPI/A_3000x3000.txt; done
for i in $(seq 5); do mpiexec -np 10 ./bin/lu_decomposition 3 4000 >> results/MPI/A_4000x4000.txt; done
for i in $(seq 2); do mpiexec -np 10 ./bin/lu_decomposition 3 5000 >> results/MPI/A_5000x5000.txt; done
for i in $(seq 2); do mpiexec -np 10 ./bin/lu_decomposition 3 6000 >> results/MPI/A_6000x6000.txt; done

echo "Processing data..."
python process_data.py

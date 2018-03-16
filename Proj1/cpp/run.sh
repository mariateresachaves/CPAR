#!/usr/bin/env bash

# Compile C++ code
make clean >/dev/null
make >/dev/null

echo "╔═════════════════════╦══════════════════════════════════════════╗"
echo "║ CPU                 ║ Intel(R) Core(TM) i5-2450M CPU @ 2.50GHz ║"
echo "╠═════════════════════╬══════════════════════════════════════════╣"
echo "║ Number of CPU cores ║                    2                     ║"
echo "╠═════════════════════╬══════════════════════════════════════════╣"
echo "║ Level 1 cache size  ║         2x32 KB -> instructions          ║"
echo "║                     ║         2x32 KB -> data                  ║"
echo "╠═════════════════════╬══════════════════════════════════════════╣"
echo "║ Level 2 cache size  ║                 2x256 KB                 ║"
echo "╠═════════════════════╬══════════════════════════════════════════╣"
echo "║ Level 3 cache size  ║                   3 MB                   ║"
echo "╚═════════════════════╩══════════════════════════════════════════╝"

echo ""
echo "Running Basic Matrix Multiplication..."

rm -f results/imgs/*

rm -f results/1/*

echo "500x500..."

./bin/matrixmult 1 500 500 > results/1/500_500_1.txt
./bin/matrixmult 1 500 500 > results/1/500_500_2.txt
./bin/matrixmult 1 500 500 > results/1/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 1 1000 1000 > results/1/1000_1000_1.txt
./bin/matrixmult 1 1000 1000 > results/1/1000_1000_2.txt
./bin/matrixmult 1 1000 1000 > results/1/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 1 1500 1500 > results/1/1500_1500_1.txt
./bin/matrixmult 1 1500 1500 > results/1/1500_1500_2.txt
./bin/matrixmult 1 1500 1500 > results/1/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 1 2000 2000 > results/1/2000_2000_1.txt
./bin/matrixmult 1 2000 2000 > results/1/2000_2000_2.txt
./bin/matrixmult 1 2000 2000 > results/1/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 1 2500 2500 > results/1/2500_2500_1.txt
./bin/matrixmult 1 2500 2500 > results/1/2500_2500_2.txt
./bin/matrixmult 1 2500 2500 > results/1/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 1 3000 3000 > results/1/3000_3000_1.txt
./bin/matrixmult 1 3000 3000 > results/1/3000_3000_2.txt
./bin/matrixmult 1 3000 3000 > results/1/3000_3000_3.txt

echo ""
echo "Running Line Matrix Multiplication..."

rm -f results/2/*

echo "500x500..."

./bin/matrixmult 2 500 500 > results/2/500_500_1.txt
./bin/matrixmult 2 500 500 > results/2/500_500_2.txt
./bin/matrixmult 2 500 500 > results/2/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 2 1000 1000 > results/2/1000_1000_1.txt
./bin/matrixmult 2 1000 1000 > results/2/1000_1000_2.txt
./bin/matrixmult 2 1000 1000 > results/2/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 2 1500 1500 > results/2/1500_1500_1.txt
./bin/matrixmult 2 1500 1500 > results/2/1500_1500_2.txt
./bin/matrixmult 2 1500 1500 > results/2/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 2 2000 2000 > results/2/2000_2000_1.txt
./bin/matrixmult 2 2000 2000 > results/2/2000_2000_2.txt
./bin/matrixmult 2 2000 2000 > results/2/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 2 2500 2500 > results/2/2500_2500_1.txt
./bin/matrixmult 2 2500 2500 > results/2/2500_2500_2.txt
./bin/matrixmult 2 2500 2500 > results/2/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 2 3000 3000 > results/2/3000_3000_1.txt
./bin/matrixmult 2 3000 3000 > results/2/3000_3000_2.txt
./bin/matrixmult 2 3000 3000 > results/2/3000_3000_3.txt

echo ""
echo "Running OpenMP Basic Matrix Multiplication with 1 Thread..."

rm -f results/3/1T/*

export OMP_NUM_THREADS=1

echo "500x500..."

./bin/matrixmult 3 500 500 > results/3/1T/500_500_1.txt
./bin/matrixmult 3 500 500 > results/3/1T/500_500_2.txt
./bin/matrixmult 3 500 500 > results/3/1T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 3 1000 1000 > results/3/1T/1000_1000_1.txt
./bin/matrixmult 3 1000 1000 > results/3/1T/1000_1000_2.txt
./bin/matrixmult 3 1000 1000 > results/3/1T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 3 1500 1500 > results/3/1T/1500_1500_1.txt
./bin/matrixmult 3 1500 1500 > results/3/1T/1500_1500_2.txt
./bin/matrixmult 3 1500 1500 > results/3/1T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 3 2000 2000 > results/3/1T/2000_2000_1.txt
./bin/matrixmult 3 2000 2000 > results/3/1T/2000_2000_2.txt
./bin/matrixmult 3 2000 2000 > results/3/1T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 3 2500 2500 > results/3/1T/2500_2500_1.txt
./bin/matrixmult 3 2500 2500 > results/3/1T/2500_2500_2.txt
./bin/matrixmult 3 2500 2500 > results/3/1T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 3 3000 3000 > results/3/1T/3000_3000_1.txt
./bin/matrixmult 3 3000 3000 > results/3/1T/3000_3000_2.txt
./bin/matrixmult 3 3000 3000 > results/3/1T/3000_3000_3.txt

echo ""
echo "Running OpenMP Basic Matrix Multiplication with 2 Thread..."

rm -f results/3/2T/*

export OMP_NUM_THREADS=2

echo "500x500..."

./bin/matrixmult 3 500 500 > results/3/2T/500_500_1.txt
./bin/matrixmult 3 500 500 > results/3/2T/500_500_2.txt
./bin/matrixmult 3 500 500 > results/3/2T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 3 1000 1000 > results/3/2T/1000_1000_1.txt
./bin/matrixmult 3 1000 1000 > results/3/2T/1000_1000_2.txt
./bin/matrixmult 3 1000 1000 > results/3/2T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 3 1500 1500 > results/3/2T/1500_1500_1.txt
./bin/matrixmult 3 1500 1500 > results/3/2T/1500_1500_2.txt
./bin/matrixmult 3 1500 1500 > results/3/2T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 3 2000 2000 > results/3/2T/2000_2000_1.txt
./bin/matrixmult 3 2000 2000 > results/3/2T/2000_2000_2.txt
./bin/matrixmult 3 2000 2000 > results/3/2T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 3 2500 2500 > results/3/2T/2500_2500_1.txt
./bin/matrixmult 3 2500 2500 > results/3/2T/2500_2500_2.txt
./bin/matrixmult 3 2500 2500 > results/3/2T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 3 3000 3000 > results/3/2T/3000_3000_1.txt
./bin/matrixmult 3 3000 3000 > results/3/2T/3000_3000_2.txt
./bin/matrixmult 3 3000 3000 > results/3/2T/3000_3000_3.txt

echo ""
echo "Running OpenMP Basic Matrix Multiplication with 4 Thread..."

rm -f results/3/4T/*

export OMP_NUM_THREADS=4

echo "500x500..."

./bin/matrixmult 3 500 500 > results/3/4T/500_500_1.txt
./bin/matrixmult 3 500 500 > results/3/4T/500_500_2.txt
./bin/matrixmult 3 500 500 > results/3/4T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 3 1000 1000 > results/3/4T/1000_1000_1.txt
./bin/matrixmult 3 1000 1000 > results/3/4T/1000_1000_2.txt
./bin/matrixmult 3 1000 1000 > results/3/4T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 3 1500 1500 > results/3/4T/1500_1500_1.txt
./bin/matrixmult 3 1500 1500 > results/3/4T/1500_1500_2.txt
./bin/matrixmult 3 1500 1500 > results/3/4T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 3 2000 2000 > results/3/4T/2000_2000_1.txt
./bin/matrixmult 3 2000 2000 > results/3/4T/2000_2000_2.txt
./bin/matrixmult 3 2000 2000 > results/3/4T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 3 2500 2500 > results/3/4T/2500_2500_1.txt
./bin/matrixmult 3 2500 2500 > results/3/4T/2500_2500_2.txt
./bin/matrixmult 3 2500 2500 > results/3/4T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 3 3000 3000 > results/3/4T/3000_3000_1.txt
./bin/matrixmult 3 3000 3000 > results/3/4T/3000_3000_2.txt
./bin/matrixmult 3 3000 3000 > results/3/4T/3000_3000_3.txt

echo ""
echo "Running OpenMP Basic Matrix Multiplication with 8 Thread..."

rm -f results/3/8T/*

export OMP_NUM_THREADS=8

echo "500x500..."

./bin/matrixmult 3 500 500 > results/3/8T/500_500_1.txt
./bin/matrixmult 3 500 500 > results/3/8T/500_500_2.txt
./bin/matrixmult 3 500 500 > results/3/8T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 3 1000 1000 > results/3/8T/1000_1000_1.txt
./bin/matrixmult 3 1000 1000 > results/3/8T/1000_1000_2.txt
./bin/matrixmult 3 1000 1000 > results/3/8T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 3 1500 1500 > results/3/8T/1500_1500_1.txt
./bin/matrixmult 3 1500 1500 > results/3/8T/1500_1500_2.txt
./bin/matrixmult 3 1500 1500 > results/3/8T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 3 2000 2000 > results/3/8T/2000_2000_1.txt
./bin/matrixmult 3 2000 2000 > results/3/8T/2000_2000_2.txt
./bin/matrixmult 3 2000 2000 > results/3/8T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 3 2500 2500 > results/3/8T/2500_2500_1.txt
./bin/matrixmult 3 2500 2500 > results/3/8T/2500_2500_2.txt
./bin/matrixmult 3 2500 2500 > results/3/8T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 3 3000 3000 > results/3/8T/3000_3000_1.txt
./bin/matrixmult 3 3000 3000 > results/3/8T/3000_3000_2.txt
./bin/matrixmult 3 3000 3000 > results/3/8T/3000_3000_3.txt

echo ""
echo "Running OpenMP Line Matrix Multiplication with 1 Thread..."

rm -f results/4/1T/*

export OMP_NUM_THREADS=1

echo "500x500..."

./bin/matrixmult 4 500 500 > results/4/1T/500_500_1.txt
./bin/matrixmult 4 500 500 > results/4/1T/500_500_2.txt
./bin/matrixmult 4 500 500 > results/4/1T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 4 1000 1000 > results/4/1T/1000_1000_1.txt
./bin/matrixmult 4 1000 1000 > results/4/1T/1000_1000_2.txt
./bin/matrixmult 4 1000 1000 > results/4/1T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 4 1500 1500 > results/4/1T/1500_1500_1.txt
./bin/matrixmult 4 1500 1500 > results/4/1T/1500_1500_2.txt
./bin/matrixmult 4 1500 1500 > results/4/1T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 4 2000 2000 > results/4/1T/2000_2000_1.txt
./bin/matrixmult 4 2000 2000 > results/4/1T/2000_2000_2.txt
./bin/matrixmult 4 2000 2000 > results/4/1T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 4 2500 2500 > results/4/1T/2500_2500_1.txt
./bin/matrixmult 4 2500 2500 > results/4/1T/2500_2500_2.txt
./bin/matrixmult 4 2500 2500 > results/4/1T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 4 3000 3000 > results/4/1T/3000_3000_1.txt
./bin/matrixmult 4 3000 3000 > results/4/1T/3000_3000_2.txt
./bin/matrixmult 4 3000 3000 > results/4/1T/3000_3000_3.txt

echo ""
echo "Running OpenMP Line Matrix Multiplication with 2 Thread..."

rm -f results/4/2T/*

export OMP_NUM_THREADS=2

echo "500x500..."

./bin/matrixmult 4 500 500 > results/4/2T/500_500_1.txt
./bin/matrixmult 4 500 500 > results/4/2T/500_500_2.txt
./bin/matrixmult 4 500 500 > results/4/2T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 4 1000 1000 > results/4/2T/1000_1000_1.txt
./bin/matrixmult 4 1000 1000 > results/4/2T/1000_1000_2.txt
./bin/matrixmult 4 1000 1000 > results/4/2T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 4 1500 1500 > results/4/2T/1500_1500_1.txt
./bin/matrixmult 4 1500 1500 > results/4/2T/1500_1500_2.txt
./bin/matrixmult 4 1500 1500 > results/4/2T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 4 2000 2000 > results/4/2T/2000_2000_1.txt
./bin/matrixmult 4 2000 2000 > results/4/2T/2000_2000_2.txt
./bin/matrixmult 4 2000 2000 > results/4/2T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 4 2500 2500 > results/4/2T/2500_2500_1.txt
./bin/matrixmult 4 2500 2500 > results/4/2T/2500_2500_2.txt
./bin/matrixmult 4 2500 2500 > results/4/2T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 4 3000 3000 > results/4/2T/3000_3000_1.txt
./bin/matrixmult 4 3000 3000 > results/4/2T/3000_3000_2.txt
./bin/matrixmult 4 3000 3000 > results/4/2T/3000_3000_3.txt

echo ""
echo "Running OpenMP Line Matrix Multiplication with 4 Thread..."

rm -f results/4/4T/*

export OMP_NUM_THREADS=4

echo "500x500..."

./bin/matrixmult 4 500 500 > results/4/4T/500_500_1.txt
./bin/matrixmult 4 500 500 > results/4/4T/500_500_2.txt
./bin/matrixmult 4 500 500 > results/4/4T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 4 1000 1000 > results/4/4T/1000_1000_1.txt
./bin/matrixmult 4 1000 1000 > results/4/4T/1000_1000_2.txt
./bin/matrixmult 4 1000 1000 > results/4/4T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 4 1500 1500 > results/4/4T/1500_1500_1.txt
./bin/matrixmult 4 1500 1500 > results/4/4T/1500_1500_2.txt
./bin/matrixmult 4 1500 1500 > results/4/4T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 4 2000 2000 > results/4/4T/2000_2000_1.txt
./bin/matrixmult 4 2000 2000 > results/4/4T/2000_2000_2.txt
./bin/matrixmult 4 2000 2000 > results/4/4T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 4 2500 2500 > results/4/4T/2500_2500_1.txt
./bin/matrixmult 4 2500 2500 > results/4/4T/2500_2500_2.txt
./bin/matrixmult 4 2500 2500 > results/4/4T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 4 3000 3000 > results/4/4T/3000_3000_1.txt
./bin/matrixmult 4 3000 3000 > results/4/4T/3000_3000_2.txt
./bin/matrixmult 4 3000 3000 > results/4/4T/3000_3000_3.txt

echo ""
echo "Running OpenMP Line Matrix Multiplication with 8 Thread..."

rm -f results/4/8T/*

export OMP_NUM_THREADS=8

echo "500x500..."

./bin/matrixmult 4 500 500 > results/4/8T/500_500_1.txt
./bin/matrixmult 4 500 500 > results/4/8T/500_500_2.txt
./bin/matrixmult 4 500 500 > results/4/8T/500_500_3.txt

echo "1000x1000..."

./bin/matrixmult 4 1000 1000 > results/4/8T/1000_1000_1.txt
./bin/matrixmult 4 1000 1000 > results/4/8T/1000_1000_2.txt
./bin/matrixmult 4 1000 1000 > results/4/8T/1000_1000_3.txt

echo "1500x1500..."

./bin/matrixmult 4 1500 1500 > results/4/8T/1500_1500_1.txt
./bin/matrixmult 4 1500 1500 > results/4/8T/1500_1500_2.txt
./bin/matrixmult 4 1500 1500 > results/4/8T/1500_1500_3.txt

echo "2000x2000..."

./bin/matrixmult 4 2000 2000 > results/4/8T/2000_2000_1.txt
./bin/matrixmult 4 2000 2000 > results/4/8T/2000_2000_2.txt
./bin/matrixmult 4 2000 2000 > results/4/8T/2000_2000_3.txt

echo "2500x2500..."

./bin/matrixmult 4 2500 2500 > results/4/8T/2500_2500_1.txt
./bin/matrixmult 4 2500 2500 > results/4/8T/2500_2500_2.txt
./bin/matrixmult 4 2500 2500 > results/4/8T/2500_2500_3.txt

echo "3000x3000..."

./bin/matrixmult 4 3000 3000 > results/4/8T/3000_3000_1.txt
./bin/matrixmult 4 3000 3000 > results/4/8T/3000_3000_2.txt
./bin/matrixmult 4 3000 3000 > results/4/8T/3000_3000_3.txt

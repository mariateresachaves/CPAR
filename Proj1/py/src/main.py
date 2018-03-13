import sys
import random
import time
from matrix import Matrix, basic_multiply, line_multiply
from pypapi import papi_high, events as papi_events

size_A = 0
size_B = 0
algorithm = 0
M = 1000000
MX = 1024

def main():
    if not(right_args(len(sys.argv), sys.argv)):
        return 1

    size_A = int(sys.argv[2])
    size_B = int(sys.argv[3])
    tot_FLOPS = 2*MX*MX*size_A;

    if valid_algorithm(sys.argv[1]):
        algorithm = int(sys.argv[1])
    else:
        return 2

    matrix_A = Matrix(size_A, size_A)
    fill(matrix_A)

    matrix_B = Matrix(size_B, size_B)
    fill(matrix_B)

    # Test Matrix Values
    #print_matrix(matrix_A)
    #print_matrix(matrix_B)

    # Starts some counters
    papi_high.start_counters([papi_events.PAPI_L1_TCM, papi_events.PAPI_L2_TCM, papi_events.PAPI_TOT_INS])

    if algorithm == 1:
        print 'Basic Matrix Multiplication'
        start_time = time.time()
        result = basic_multiply(matrix_A, matrix_B)
        end_time = time.time()
        #print_matrix(result)

    if algorithm == 2:
        print 'Line Matrix Multiplication'
        start_time = time.time()
        result = line_multiply(matrix_A, matrix_B)
        end_time = time.time()
        #print_matrix(result)

    # Reads values from counters and reset them
    results = papi_high.read_counters()  # -> [int, int]

    # Print results
    print_times(results, tot_FLOPS, start_time, end_time)

    # Stop counters
    papi_high.stop_counters()  # -> []


def right_args(num_args, argv):
    if num_args != 4:
        print '[Wrong_Args] usage: ', argv[0], ' ', '<algorithm> <size_matrix_A> <size_matrix_B>\n'
        print '\t Where:\n'
        print '\t\t <algorithm> - type of algorithm to apply\n'
        print '\t\t <size_matrix_A> - matrix size_matrix_A x size_matrix_A\n'
        print '\t\t <size_matrix_B> - matrix size_matrix_B x size_matrix_B\n'
        return False

    return True

def valid_algorithm(alg):
    if (int(alg) == 1) or (int(alg) == 2):
        return True
    else:
        print '[Wrong_Algorithm] You must choose one of the following options:'
        print '\t1 - Basic Matrix Multiplication'
        print '\t2 - Line Matrix Multiplication'
        return False

def fill(matrix):
    for i in range(matrix.num_rows*matrix.num_cols):
        matrix.matrix_values[i] = random.randint(1,100)

def print_matrix(matrix):
    print '[',
    for i in range(matrix.num_rows*matrix.num_cols):
        print matrix.matrix_values[i] ,
    print ']'

def print_times(results, tot_FLOPS, start_time, end_time):
    print 'PAPI_L1_TCM = ', results[0]
    print 'PAPI_L2_TCM = ', results[1]
    print 'PAPI_TOT_INS = ', results[2]
    print 'MFLOP/s = ', (tot_FLOPS/M)/(end_time-start_time)
    print 'Time (seconds) = ', (end_time-start_time)

if __name__ == "__main__":
    main()

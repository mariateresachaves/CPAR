import sys
from matrix import Matrix

size_A = 0
size_B = 0
algorithm = 0

def main():
    if right_args(len(sys.argv), sys.argv):
        print 'Everything ok'
    else:
        return 1

    size_A = int(sys.argv[2])
    size_B = int(sys.argv[3])

    if valid_algorithm(sys.argv[1]):
        algorithm = int(sys.argv[1])
    else:
        return 2

    matrix_A = Matrix(size_A, size_A)
    matrix_B = Matrix(size_B, size_B)

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

if __name__ == "__main__":
    main()

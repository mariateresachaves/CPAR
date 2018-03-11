import sys

def main():
    if right_args(len(sys.argv), sys.argv):
        print 'Everything ok'
    else:
        return -1

def right_args(num_args, argv):
    if num_args != 4:
        print '[Wrong_Args] usage: ', argv[0], ' ', '<algorithm> <size_matrix_A> <size_matrix_B>\n'
        print '\t Where:\n'
        print '\t\t <algorithm> - type of algorithm to apply\n'
        print '\t\t <size_matrix_A> - matrix size_matrix_A x size_matrix_A\n'
        print '\t\t <size_matrix_B> - matrix size_matrix_B x size_matrix_B\n'
        return False

    return True

if __name__ == "__main__":
    main()

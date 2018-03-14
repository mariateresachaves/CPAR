from array import array

class Matrix:
    matrix_values = None
    num_rows = 0
    num_cols = 0

    def __init__(self, rows, columns):
        if rows <= 0:
            print '[Wrong_Args] Number of rows must be greater than zero'
            return 1

        if columns <= 0:
            print '[Wrong_Args] Number of columns must be greater than zero'
            return 1

        self.num_rows = rows
        self.num_cols = columns

        self.matrix_values = array("f", (0,) * (self.num_rows * self.num_cols))

def basic_multiply(matrix_A, matrix_B):
    result = Matrix(matrix_A.num_rows, matrix_B.num_cols)

    for i in range(matrix_A.num_rows):
        for j in range(matrix_B.num_cols):
            for k in range(matrix_A.num_cols):
                result.matrix_values[i*result.num_cols + j] += matrix_A.matrix_values[i*matrix_A.num_cols + k] * matrix_B.matrix_values[k*matrix_B.num_cols + j]

    return result

def line_multiply(matrix_A, matrix_B):
    result = Matrix(matrix_A.num_rows, matrix_B.num_cols)

    for i in range(matrix_A.num_rows):
        for k in range(matrix_A.num_cols):
            for j in range(matrix_B.num_cols):
                result.matrix_values[i*result.num_cols + j] += matrix_A.matrix_values[i*matrix_A.num_cols + k] * matrix_B.matrix_values[k*matrix_B.num_cols + j]

    return result

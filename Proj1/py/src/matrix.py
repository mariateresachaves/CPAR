from array import array
import random

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

        self.matrix_values = array("i", (random.randint(1,100),) * (self.num_rows * self.num_cols))

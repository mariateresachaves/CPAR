import sys
import numpy as np
import time
import random

def basic_matrix_mult (A, B):
    n = len(A[0])

    C = [[0 for row in range(n)] for col in range(n)]

    for i in range(n):
        for k in range(n):
            for j in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C

# Fill 2 matrices with random values between 1 and 100
A = [[random.randint(1,100) for row in range(500)] for col in range(500)]
B = [[random.randint(1,100) for row in range(500)] for col in range(500)]

start_time = time.time()

C = basic_matrix_mult(A, B)

print("--- %s seconds ---" % (time.time() - start_time))

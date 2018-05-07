import matplotlib.pyplot as plt

SIZES = [1000, 2000, 3000, 4000, 5000, 6000]

LU_SEQ = [0, 0, 0, 0, 0, 0]
LU_OMP_1T = [0, 0, 0, 0, 0, 0]
LU_OMP_2T = [0, 0, 0, 0, 0, 0]
LU_OMP_4T = [0, 0, 0, 0, 0, 0]
LU_MPI = [0, 0, 0, 0, 3000, 6000]

# LU Decomposition Sequential
for i in range(1000,7000,1000):
    s = "results/SEQ/A_%dx%d.txt" % (i,i)

    text_file = open(s, "r")
    lines = text_file.readlines()
    text_file.close()

    avg = 0.0
    s = 0.0
    count = 0
    for value in lines:
        s += float(value)
        count += 1

    avg = s/count

    LU_SEQ[i/1000-1] = avg

# LU Decomposition OMP 1 Thread
for i in range(1000,7000,1000):
    s = "results/OMP/1T/A_%dx%d.txt" % (i,i)

    text_file = open(s, "r")
    lines = text_file.readlines()
    text_file.close()

    avg = 0.0
    s = 0.0
    count = 0
    for value in lines:
        s += float(value)
        count += 1

    avg = s/count

    LU_OMP_1T[i/1000-1] = avg

# LU Decomposition OMP 2 Threads
for i in range(1000,7000,1000):
    s = "results/OMP/2T/A_%dx%d.txt" % (i,i)

    text_file = open(s, "r")
    lines = text_file.readlines()
    text_file.close()

    avg = 0.0
    s = 0.0
    count = 0
    for value in lines:
        s += float(value)
        count += 1

    avg = s/count

    LU_OMP_2T[i/1000-1] = avg

# LU Decomposition OMP 4 Threads
for i in range(1000,7000,1000):
    s = "results/OMP/4T/A_%dx%d.txt" % (i,i)

    text_file = open(s, "r")
    lines = text_file.readlines()
    text_file.close()

    avg = 0.0
    s = 0.0
    count = 0
    for value in lines:
        s += float(value)
        count += 1

    avg = s/count

    LU_OMP_4T[i/1000-1] = avg

# LU Decomposition MPI
for i in range(1000,5000,1000):
    s = "results/MPI/A_%dx%d.txt" % (i,i)

    text_file = open(s, "r")
    lines = text_file.readlines()
    text_file.close()

    avg = 0.0
    s = 0.0
    count = 0
    for value in lines:
        s += float(value)
        count += 1

    avg = s/count

    LU_MPI[i/1000-1] = avg

### PLOT ###
fig = plt.figure()

plt.plot(SIZES, LU_SEQ, 'o', color='forestgreen', ls='-', label='Sequential')
plt.plot(SIZES, LU_OMP_1T, 'o', color='midnightblue', ls='-', label='OpenMP 1 Thread')
plt.plot(SIZES, LU_OMP_2T, 'o', color='darkorange', ls='-', label='OpenMP 2 Threads')
plt.plot(SIZES, LU_OMP_4T, 'o', color='purple', ls='-', label='OpenMP 4 Threads')
plt.plot(SIZES, LU_MPI, 'o', color='red', ls='-', label='MPI')
plt.title('LU Decomposition')
plt.axis([0, 7000, 0, 2000])
plt.xlabel('Matrix Size')
plt.ylabel('Execution Time (s)')
plt.legend()
#plt.show()
fig.savefig('results/imgs/lu_decomposition.png')

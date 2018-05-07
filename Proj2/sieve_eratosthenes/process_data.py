import matplotlib.pyplot as plt

SIZES = [100000000, 200000000, 300000000, 400000000, 500000000, 600000000]

SIEVE_SEQ = [0, 0, 0, 0, 0, 0]
SIEVE_OMP_1T = [0, 0, 0, 0, 0, 0]
SIEVE_OMP_2T = [0, 0, 0, 0, 0, 0]
SIEVE_OMP_4T = [0, 0, 0, 0, 0, 0]
SIEVE_MPI = [0, 0, 0, 0, 0, 0]

# Sieve Eratosthenes Sequential
for i in range(100000000,700000000,100000000):
    s = "results/SEQ/SE_%d.txt" % (i)

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

    SIEVE_SEQ[i/100000000-1] = avg

# Sieve Eratosthenes OpenMP 1 Thread
for i in range(100000000,700000000,100000000):
    s = "results/OMP/1T/SE_%d.txt" % (i)

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

    SIEVE_OMP_1T[i/100000000-1] = avg

# Sieve Eratosthenes OpenMP 2 Threads
for i in range(100000000,700000000,100000000):
    s = "results/OMP/2T/SE_%d.txt" % (i)

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

    SIEVE_OMP_2T[i/100000000-1] = avg

# Sieve Eratosthenes OpenMP 4 Threads
for i in range(100000000,700000000,100000000):
    s = "results/OMP/4T/SE_%d.txt" % (i)

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

    SIEVE_OMP_4T[i/100000000-1] = avg

# Sieve Eratosthenes MPI
for i in range(100000000,700000000,100000000):
    s = "results/MPI/SE_%d.txt" % (i)

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

    SIEVE_MPI[i/100000000-1] = avg

### PLOT ###
fig = plt.figure()

plt.plot(SIZES, SIEVE_SEQ, 'o', color='forestgreen', ls='-', label='Sequential')
plt.plot(SIZES, SIEVE_OMP_1T, 'o', color='midnightblue', ls='-', label='OpenMP 1 Thread')
plt.plot(SIZES, SIEVE_OMP_2T, 'o', color='darkorange', ls='-', label='OpenMP 2 Threads')
plt.plot(SIZES, SIEVE_OMP_4T, 'o', color='purple', ls='-', label='OpenMP 4 Threads')
plt.plot(SIZES, SIEVE_MPI, 'o', color='red', ls='-', label='MPI')
plt.title('Sieve Eratosthenes')
plt.axis([0, 700000000, 0, 17])
plt.xlabel('N')
plt.ylabel('Execution Time (s)')
plt.legend()
#plt.show()
fig.savefig('results/imgs/sieve_eratosthenes.png')

import matplotlib.pyplot as plt

M = 1000000.0

SIZES = [500, 1000, 1500, 2000, 2500, 3000]

L1_DCM_B = [0, 0, 0, 0, 0, 0]
L1_ICM_B = [0, 0, 0, 0, 0, 0]
L1_TCM_B = [0, 0, 0, 0, 0, 0]
L2_TCM_B = [0, 0, 0, 0, 0, 0]
L3_TCM_B = [0, 0, 0, 0, 0, 0]
TOT_INS_B = [0, 0, 0, 0, 0, 0]
MFLOPs_B = [0, 0, 0, 0, 0, 0]
TIME_B = [0, 0, 0, 0, 0, 0]

L1_DCM_L = [0, 0, 0, 0, 0, 0]
L1_ICM_L = [0, 0, 0, 0, 0, 0]
L1_TCM_L = [0, 0, 0, 0, 0, 0]
L2_TCM_L = [0, 0, 0, 0, 0, 0]
L3_TCM_L = [0, 0, 0, 0, 0, 0]
TOT_INS_L = [0, 0, 0, 0, 0, 0]
MFLOPs_L = [0, 0, 0, 0, 0, 0]
TIME_L = [0, 0, 0, 0, 0, 0]

TIME_1T_B = [0, 0, 0, 0, 0, 0]
TIME_2T_B = [0, 0, 0, 0, 0, 0]
TIME_4T_B = [0, 0, 0, 0, 0, 0]
TIME_8T_B = [0, 0, 0, 0, 0, 0]

TIME_1T_L = [0, 0, 0, 0, 0, 0]
TIME_2T_L = [0, 0, 0, 0, 0, 0]
TIME_4T_L = [0, 0, 0, 0, 0, 0]
TIME_8T_L = [0, 0, 0, 0, 0, 0]

# Basic Matrix Multiplication
print "Processing data of Basic Matrix Multiplication..."
for i in range(500,3500,500):
    for j in range(1,4):
        s = "results/1/%d_%d_%d.txt" % (i,i,j)

        text_file = open(s, "r")
        lines = text_file.readlines()
        text_file.close()

        L1_DCM = int(((lines[1].split("= ", 1 ))[1].split("\n"))[0])
        L1_ICM = int(((lines[2].split("= ", 1 ))[1].split("\n"))[0])
        L1_TCM = int(((lines[3].split("= ", 1 ))[1].split("\n"))[0])
        L2_TCM = int(((lines[4].split("= ", 1 ))[1].split("\n"))[0])
        L3_TCM = int(((lines[5].split("= ", 1 ))[1].split("\n"))[0])
        TOT_INS = int(((lines[6].split("= ", 1 ))[1].split("\n"))[0])
        MFLOPs = float(((lines[7].split("= ", 1 ))[1].split("\n"))[0])
        TIME = float(((lines[8].split("= ", 1 ))[1].split("\n"))[0])

        if j == 1:
            L1_DCM_B[i/500 -1] = L1_DCM
            L1_ICM_B[i/500 -1] = L1_ICM
            L1_TCM_B[i/500 -1] = L1_TCM
            L2_TCM_B[i/500 -1] = L2_TCM
            L3_TCM_B[i/500 -1] = L3_TCM
            TOT_INS_B[i/500 -1] = TOT_INS
            MFLOPs_B[i/500 -1] = MFLOPs
            TIME_B[i/500 -1] = TIME

        if (L1_DCM < L1_DCM_B[i/500 - 1]):
            L1_DCM_B[i/500 -1] = L1_DCM

        if(L1_ICM < L1_ICM_B[i/500 - 1]):
            L1_ICM_B[i/500 -1] = L1_ICM

        if(L1_TCM < L1_TCM_B[i/500 - 1]):
            L1_TCM_B[i/500 -1] = L1_TCM

        if(L2_TCM < L2_TCM_B[i/500 - 1]):
            L2_TCM_B[i/500 -1] = L2_TCM

        if(L3_TCM < L3_TCM_B[i/500 - 1]):
            L3_TCM_B[i/500 -1] = L3_TCM

        if(TOT_INS < TOT_INS_B[i/500 - 1]):
            TOT_INS_B[i/500 -1] = TOT_INS

        if(MFLOPs < MFLOPs_B[i/500 - 1]):
            MFLOPs_B[i/500 -1] = MFLOPs

        if(TIME < TIME_B[i/500 - 1]):
            TIME_B[i/500 -1] = TIME

# Line Matrix Multiplication
print "Processing data of Line Matrix Multiplication..."
for i in range(500,3500,500):
    for j in range(1,4):
        s = "results/2/%d_%d_%d.txt" % (i,i,j)

        text_file = open(s, "r")
        lines = text_file.readlines()
        text_file.close()

        L1_DCM = int(((lines[1].split("= ", 1 ))[1].split("\n"))[0])
        L1_ICM = int(((lines[2].split("= ", 1 ))[1].split("\n"))[0])
        L1_TCM = int(((lines[3].split("= ", 1 ))[1].split("\n"))[0])
        L2_TCM = int(((lines[4].split("= ", 1 ))[1].split("\n"))[0])
        L3_TCM = int(((lines[5].split("= ", 1 ))[1].split("\n"))[0])
        TOT_INS = int(((lines[6].split("= ", 1 ))[1].split("\n"))[0])
        MFLOPs = float(((lines[7].split("= ", 1 ))[1].split("\n"))[0])
        TIME = float(((lines[8].split("= ", 1 ))[1].split("\n"))[0])

        if j == 1:
            L1_DCM_L[i/500 -1] = L1_DCM
            L1_ICM_L[i/500 -1] = L1_ICM
            L1_TCM_L[i/500 -1] = L1_TCM
            L2_TCM_L[i/500 -1] = L2_TCM
            L3_TCM_L[i/500 -1] = L3_TCM
            TOT_INS_L[i/500 -1] = TOT_INS
            MFLOPs_L[i/500 -1] = MFLOPs
            TIME_L[i/500 -1] = TIME

        if (L1_DCM < L1_DCM_L[i/500 - 1]):
            L1_DCM_L[i/500 -1] = L1_DCM

        if(L1_ICM < L1_ICM_L[i/500 - 1]):
            L1_ICM_L[i/500 -1] = L1_ICM

        if(L1_TCM < L1_TCM_L[i/500 - 1]):
            L1_TCM_L[i/500 -1] = L1_TCM

        if(L2_TCM < L2_TCM_L[i/500 - 1]):
            L2_TCM_L[i/500 -1] = L2_TCM

        if(L3_TCM < L3_TCM_L[i/500 - 1]):
            L3_TCM_L[i/500 -1] = L3_TCM

        if(TOT_INS < TOT_INS_L[i/500 - 1]):
            TOT_INS_L[i/500 -1] = TOT_INS

        if(MFLOPs < MFLOPs_L[i/500 - 1]):
            MFLOPs_L[i/500 -1] = MFLOPs

        if(TIME < TIME_L[i/500 - 1]):
            TIME_L[i/500 -1] = TIME

### L1_DCM ###
fig = plt.figure()

plt.plot(SIZES, L1_DCM_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, L1_DCM_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Level 1 Data Cache Misses')
plt.axis([500, 3500, 0, 40000000000])
plt.xlabel('Matrix Size')
plt.ylabel('L1_DCM')
plt.legend()
#plt.show()
fig.savefig('results/imgs/l1_dcm_B_L.png')

### L1_ICM ###
fig = plt.figure()

plt.plot(SIZES, L1_ICM_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, L1_ICM_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Level 1 Instruction Cache Misses')
plt.axis([500, 3500, 0, 2800000])
plt.xlabel('Matrix Size')
plt.ylabel('L1_ICM')
plt.legend()
#plt.show()
fig.savefig('results/imgs/l1_icm_B_L.png')

### L1_TCM ###
fig = plt.figure()

plt.plot(SIZES, L1_TCM_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, L1_TCM_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Level 1 Total Cache Misses')
plt.axis([500, 3500, 0, 40000000000])
plt.xlabel('Matrix Size')
plt.ylabel('L1_TCM')
plt.legend()
#plt.show()
fig.savefig('results/imgs/l1_tcm_B_L.png')

### L2_TCM ###
fig = plt.figure()

plt.plot(SIZES, L2_TCM_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, L2_TCM_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Level 2 Total Cache Misses')
plt.axis([500, 3500, 0, 22000000000])
plt.xlabel('Matrix Size')
plt.ylabel('L2_TCM')
plt.legend()
#plt.show()
fig.savefig('results/imgs/l2_tcm_B_L.png')

### L3_TCM ###
fig = plt.figure()

plt.plot(SIZES, L3_TCM_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, L3_TCM_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Level 3 Total Cache Misses')
plt.axis([500, 3500, 0, 1800000000])
plt.xlabel('Matrix Size')
plt.ylabel('L3_TCM')
plt.legend()
#plt.show()
fig.savefig('results/imgs/l3_tcm_B_L.png')

### TOT_INS ###
fig = plt.figure()

plt.plot(SIZES, TOT_INS_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, TOT_INS_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Total Instructions Executed')
plt.axis([500, 3500, 0, 230000000000])
plt.xlabel('Matrix Size')
plt.ylabel('TOT_INS')
plt.legend()
#plt.show()
fig.savefig('results/imgs/tot_ins_B_L.png')

### MFLOPs ###
fig = plt.figure()

plt.plot(SIZES, MFLOPs_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, MFLOPs_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Million Floating-Point Operations Per Second')
plt.axis([500, 3500, 0, 14000000000])
plt.xlabel('Matrix Size')
plt.ylabel('MFLOPs')
plt.legend()
#plt.show()
fig.savefig('results/imgs/mflops_B_L.png')

### TIME ###
fig = plt.figure()

plt.plot(SIZES, TIME_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, TIME_L, 'o', color='midnightblue', ls='-', label='Linear Matrix Multiplication')
plt.title('Execution Time')
plt.axis([500, 3500, 0, 300])
plt.xlabel('Matrix Size')
plt.ylabel('TIME')
plt.legend()
#plt.show()
fig.savefig('results/imgs/time_B_L.png')

# OMP Basic Matrix Multiplication
print "Processing execution time of OpenMP Basic Matrix Multiplication..."
p = 0
t = pow(2,p)
while (t!=16):
    p+=1
    for i in range(500,3500,500):
        for j in range(1,4):
            s = "results/3/%dT/%d_%d_%d.txt" % (t,i,i,j)

            text_file = open(s, "r")
            lines = text_file.readlines()
            text_file.close()

            TIME = float(((lines[8].split("= ", 1 ))[1].split("\n"))[0])

            if t == 1:
                if j == 1:
                    TIME_1T_B[i/500 -1] = TIME

                if (TIME < TIME_1T_B[i/500 - 1]):
                    TIME_1T_B[i/500 -1] = TIME

            if t == 2:
                if j == 1:
                    TIME_2T_B[i/500 -1] = TIME

                if (TIME < TIME_2T_B[i/500 - 1]):
                    TIME_2T_B[i/500 -1] = TIME

            if t == 4:
                if j == 1:
                    TIME_4T_B[i/500 -1] = TIME

                if (TIME < TIME_4T_B[i/500 - 1]):
                    TIME_4T_B[i/500 -1] = TIME

            if t == 8:
                if j == 1:
                    TIME_8T_B[i/500 -1] = TIME

                if (TIME < TIME_8T_B[i/500 - 1]):
                    TIME_8T_B[i/500 -1] = TIME

    t=pow(2,p)

### TIME ###
fig = plt.figure()

plt.plot(SIZES, TIME_1T_B, 'o', color='forestgreen', ls='-', label='1 Thread')
plt.plot(SIZES, TIME_2T_B, 'o', color='midnightblue', ls='-', label='2 Threads')
plt.plot(SIZES, TIME_4T_B, 'o', color='darkorange', ls='-', label='4 Threads')
plt.plot(SIZES, TIME_8T_B, 'o', color='purple', ls='-', label='8 Threads')
plt.title('OpenMP Basic Matrix Multiplication Execution Time')
plt.axis([500, 3500, 0, 300])
plt.xlabel('Matrix Size')
plt.ylabel('TIME')
plt.legend()
#plt.show()
fig.savefig('results/imgs/time_omp_B.png')

# OMP Line Matrix Multiplication
print "Processing execution time of OpenMP Line Matrix Multiplication..."
p = 0
t = pow(2,p)
while (t!=16):
    p+=1
    for i in range(500,3500,500):
        for j in range(1,4):
            s = "results/4/%dT/%d_%d_%d.txt" % (t,i,i,j)

            text_file = open(s, "r")
            lines = text_file.readlines()
            text_file.close()

            TIME = float(((lines[8].split("= ", 1 ))[1].split("\n"))[0])

            if t == 1:
                if j == 1:
                    TIME_1T_L[i/500 -1] = TIME

                if (TIME < TIME_1T_L[i/500 - 1]):
                    TIME_1T_L[i/500 -1] = TIME

            if t == 2:
                if j == 1:
                    TIME_2T_L[i/500 -1] = TIME

                if (TIME < TIME_2T_L[i/500 - 1]):
                    TIME_2T_L[i/500 -1] = TIME

            if t == 4:
                if j == 1:
                    TIME_4T_L[i/500 -1] = TIME

                if (TIME < TIME_4T_L[i/500 - 1]):
                    TIME_4T_L[i/500 -1] = TIME

            if t == 8:
                if j == 1:
                    TIME_8T_L[i/500 -1] = TIME

                if (TIME < TIME_8T_L[i/500 - 1]):
                    TIME_8T_L[i/500 -1] = TIME

    t=pow(2,p)

### TIME ###
fig = plt.figure()

plt.plot(SIZES, TIME_1T_L, 'o', color='forestgreen', ls='-', label='1 Thread')
plt.plot(SIZES, TIME_2T_L, 'o', color='midnightblue', ls='-', label='2 Threads')
plt.plot(SIZES, TIME_4T_L, 'o', color='darkorange', ls='-', label='4 Threads')
plt.plot(SIZES, TIME_8T_L, 'o', color='purple', ls='-', label='8 Threads')
plt.title('OpenMP Basic Matrix Multiplication Execution Time')
plt.axis([500, 3500, 0, 15])
plt.xlabel('Matrix Size')
plt.ylabel('TIME')
plt.legend()
#plt.show()
fig.savefig('results/imgs/time_omp_L.png')

### TIME 1 THREAD COMPARISON ###
print "Processing execution time of OpenMP for 1 threads comparison..."
fig = plt.figure()

plt.plot(SIZES, TIME_1T_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, TIME_1T_L, 'o', color='midnightblue', ls='-', label='Line Matrix Multiplication')
plt.title('OpenMP Execution Time With 1 Thread')
plt.axis([500, 3500, 0, 270])
plt.xlabel('Matrix Size')
plt.ylabel('TIME')
plt.legend()
#plt.show()
fig.savefig('results/imgs/time_omp_1T.png')

### TIME 2 THREAD COMPARISON ###
print "Processing execution time of OpenMP for 2 threads comparison..."
fig = plt.figure()

plt.plot(SIZES, TIME_2T_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, TIME_2T_L, 'o', color='midnightblue', ls='-', label='Line Matrix Multiplication')
plt.title('OpenMP Execution Time With 2 Threads')
plt.axis([500, 3500, 0, 180])
plt.xlabel('Matrix Size')
plt.ylabel('TIME')
plt.legend()
#plt.show()
fig.savefig('results/imgs/time_omp_2T.png')

### TIME 4 THREAD COMPARISON ###
print "Processing execution time of OpenMP for 4 threads comparison..."
fig = plt.figure()

plt.plot(SIZES, TIME_4T_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, TIME_4T_L, 'o', color='midnightblue', ls='-', label='Line Matrix Multiplication')
plt.title('OpenMP Execution Time With 4 Threads')
plt.axis([500, 3500, 0, 180])
plt.xlabel('Matrix Size')
plt.ylabel('TIME')
plt.legend()
#plt.show()
fig.savefig('results/imgs/time_omp_4T.png')

### TIME 8 THREAD COMPARISON ###
print "Processing execution time of OpenMP for 8 threads comparison..."
fig = plt.figure()

plt.plot(SIZES, TIME_8T_B, 'o', color='forestgreen', ls='-', label='Basic Matrix Multiplication')
plt.plot(SIZES, TIME_8T_L, 'o', color='midnightblue', ls='-', label='Line Matrix Multiplication')
plt.title('OpenMP Execution Time With 8 Threads')
plt.axis([500, 3500, 0, 180])
plt.xlabel('Matrix Size')
plt.ylabel('TIME')
plt.legend()
#plt.show()
fig.savefig('results/imgs/time_omp_8T.png')

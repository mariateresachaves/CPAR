## Folder organization

**Proj2**
├── **LU_decomposition**
│   ├── **bin**
│   │   └── lu_decomposition
│   ├── **LU_inputs**
│   │   ├── A_1000x1000.csv
│   │   ├── ...
│   ├── **LU_outputs**
│   │   ├── L_1000x1000.csv
│   │   ├── ...
│   │   ├── U_1000x1000.csv
│   │   ├── ...
│   ├── **LU_spoil**
│   │   ├── L_1000x1000.csv
│   │   ├── ...
│   │   ├── U_1000x1000.csv
│   │   ├── ...
│   ├── makefile
│   ├── process_data.py
│   ├── **results**
│   │   ├── **imgs**
│   │   │   └── lu_decomposition.png
│   │   ├── **MPI**
│   │   │   ├── A_1000x1000.txt
│   │   │   ├── ...
│   │   ├── **OMP**
│   │   │   ├── **1T**
│   │   │   │   ├── A_1000x1000.txt
│   │   │   │   ├── ...
│   │   │   ├── **2T**
│   │   │   │   ├── A_1000x1000.txt
│   │   │   │   ├── ...
│   │   │   └── **4T**
│   │   │       ├── A_1000x1000.txt
│   │   │       ├── ...
│   │   └── **SEQ**
│   │       ├── A_1000x1000.txt
│   │       ├── ...
│   ├── run.sh
│   ├── **src**
│   │   ├── main.cpp
│   │   ├── main.hpp
│   │   ├── matrix.cpp
│   │   └── matrix.hpp
│   └── **tmp**
│       ├── main.cpp.o
│       └── matrix.cpp.o
├── README.md
├── **sieve_eratosthenes**
│   ├── **bin**
│   │   └── sieve_eratosthenes
│   ├── makefile
│   ├── process_data.py
│   ├── **results**
│   │   ├── **imgs**
│   │   │   └── sieve_eratosthenes.png
│   │   ├── **MPI**
│   │   │   ├── SE_100000000.txt
│   │   │   ├── ...
│   │   ├── **OMP**
│   │   │   ├── **1T**
│   │   │   │   ├── SE_100000000.txt
│   │   │   │   ├── ...
│   │   │   ├── **2T**
│   │   │   │   ├── SE_100000000.txt
│   │   │   │   ├── ...
│   │   │   └── **4T**
│   │   │       ├── SE_100000000.txt
│   │   │       ├── ...
│   │   └── **SEQ**
│   │       ├── SE_100000000.txt
│   │       ├── ...
│   ├── run.sh
│   ├── **SE_outputs**
│   │   ├── SE_100000000.csv
│   │   ├── ...
│   ├── **src**
│   │   ├── main.cpp
│   │   └── main.hpp
│   └── **tmp**
│       └── main.cpp.o
└── specs.sh

## How to run LU Decomposition algorithm

Inside of folder LU_decomposition run the command:

````
> ./bin/lu_decomposition <algorithm> <size_matrix>
````

where:
    **algorithm** stands for the type of algorithm, which can be:
        **1** - Sequential
        **2** - Using OpenMP

        **3** - Using MPI
            For this option the run command is a bit different:
            ````
            > mpiexec -np <processes> ./bin/lu_decomposition <algorithm> <size_matrix>
            ````

            where **processes** are the number of processes

    **n** stands for the dimension of the square matrix


The file run.sh is a script that contains all the commands needed to make a
performance evaluation. To execute this command:
    ````
    > sh run.sh
    ````

## How to run Sieve of Eratosthenes algorithm

Inside the folder sieve_eratosthenes run the command:
````
> ./bin/sieve_eratosthenes <algorithm> <n>
````

where:
    **algorithm** stands for the type of algorithm, which can be:
        **1** - Sequential
        **2** - Using OpenMP

        **3** - Using MPI
            For this option the run command is a bit different:
            ````
            > mpiexec -np <processes> ./bin/sieve_eratosthenes <algorithm> <n>
            ````

            where **processes** are the number of processes

    **n** stands for the number up to the algorithm should find prime numbers

The file run.sh is a script that contains all the commands needed to make a
performance evaluation. To execute this command:
````
> sh run.sh
````

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

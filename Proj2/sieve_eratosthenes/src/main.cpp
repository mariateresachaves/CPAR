#include "main.hpp"


int main(int argc, char const *argv[]) {
    bool on = true;

    if(!right_args(argc, argv))
        exit(1);

    primes = new int [n+1];

    while(on) {
        se_file_name = "SE_outputs/SE_" + to_string(n) + ".csv";

        switch(op) {
            case 1:
                // cout << "1. Sieve of Eratosthenes Sequential [" << n << "]"
                //      << endl;

                sieve_eratosthenes_sequential();

                print_results();

                print_execution_time();

                on = false;
                break;

            case 2:
                // cout << "2. Sieve of Eratosthenes OpenMP [" << n << "]"
                //      << endl;

                sieve_eratosthenes_OMP();

                print_results();

                print_execution_time();

                on = false;
                break;

            case 3:
                // cout << "3. Sieve of Eratosthenes MPI [" << n << "]"
                //      << endl;

                sieve_eratosthenes_MPI();

                on = false;
                break;

            default:
                cerr << "Option " << op << " is not a valid operation"
                     << endl;
                on = false;
                break;
        }
    }

    delete primes;

    return 0;
}

static bool right_args(int argc, char const *argv[]) {
    if(argc != 3) {
        cerr << "[Wrong_Args] usage: " << argv[0] << " "
             << "<algorithm> <n>" << endl
             << "\t Where:" << endl
             << "\t\t <algorithm> - type of algorithm to apply" << endl
             << "\t\t <n> - prime numbers up to n" << endl;
        return false;
    }

    else {
        istringstream arg1(argv[1]);
        istringstream arg2(argv[2]);

        if(!(arg1 >> op) || !(arg2 >> n)) {
                cerr << "[Wrong_Args] <algorithm> and <n> "
                     << "must be integers" << endl;
                return false;
        }
    }

    return true;
}

static void print_execution_time() {
    cout //<< "Time = "
         << (float) ((t_stop.tv_sec - t_start.tv_sec)
            + (t_stop.tv_nsec - t_start.tv_nsec)/1000000000.0)
         //<< "s"
         << endl;
}

static void sieve_eratosthenes_sequential() {
    size_t i, j;

    clock_gettime(CLOCK_MONOTONIC, &t_start);

    for(i = 0; i <= n; i++)
        primes[i] = 1;

    primes[0] = 0;
    primes[1] = 0;

    for(i = 2; i <= sqrt(n); i++)
        if(primes[i] == 1)
            for(j = 2; i*j <= n; j++)
                primes[i*j] = 0;

    clock_gettime(CLOCK_MONOTONIC, &t_stop);
}

static void sieve_eratosthenes_OMP() {
    size_t i, j;
    size_t sqrt_n = sqrt(n);

    clock_gettime(CLOCK_MONOTONIC, &t_start);

    #pragma omp parallel for
    for(i = 0; i <= n; i++)
        primes[i] = 1;

    primes[0] = 0;
    primes[1] = 0;

    #pragma omp parallel for schedule(dynamic)
    for(i = 2; i <= sqrt_n; i++)
        if(primes[i] == 1)
            for(j = 2; i*j <= n; j++)
                primes[i*j] = 0;

    clock_gettime(CLOCK_MONOTONIC, &t_stop);
}

static void sieve_eratosthenes_MPI() {
    double start_time=0, end_time=0;
    int rank, size;
    size_t k, start_block, multiple, block_primes, start_value, all_blocks_primes;

    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // DEBUG
    //cout << "size (" << size << ") | rank(" << rank << ")" << endl;

    size_t number_odd_elements = n / 2;

    unsigned long blockSize = BLOCK_SIZE(rank, number_odd_elements, size);
    unsigned long blockLow = BLOCK_LOW(rank, number_odd_elements, size) * 2 + 1;
    unsigned long blockHigh = BLOCK_HIGH(rank, number_odd_elements, size) * 2 + 1;

    sieved_vector.resize(blockSize, false);

    MPI_Barrier(MPI_COMM_WORLD);

    if(rank == 0)
        start_time = MPI_Wtime();

    for(k = 3; k <= static_cast<size_t>(sqrt(n)); ) {
        if(k*k < blockLow) {
            start_block = blockLow;

            if(blockLow%k != 0) {
                start_block += -(blockLow % k) + k;

                if (start_block%2 == 0)
                    start_block += k;
            }
        }
        else
            start_block = k*k;

        for (multiple=start_block; multiple<=blockHigh; multiple+=2*k)
            sieved_vector[(multiple - blockLow) / 2] = true;

        if (rank == 0)
            k += 2;

        MPI_Bcast(&k, 1, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
    }

    block_primes = 0;
    start_value = blockLow;

    if(rank == 0) {
        // DEBUG
        //cout << "2 rank(" << rank << ")" << endl;
        start_value += 2;
        block_primes += 1;
    }

    for(size_t number = start_value; number <= blockHigh; number += 2)
        if(!sieved_vector[(number - blockLow) / 2])
            // DEBUG
            //cout << number << " rank(" << rank << ")" << endl;
            block_primes++;

    all_blocks_primes = 0;
    MPI_Reduce(&block_primes, &all_blocks_primes, 1, MPI_UNSIGNED, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        end_time = MPI_Wtime();
        // DEBUG
        // cout << "Primes found: " << all_blocks_primes << endl;
        cout << end_time - start_time << endl;
    }

    MPI_Finalize();
}

static void print_results() {
    ofstream se_file(se_file_name.c_str());
    size_t i, j = 0;
    string se;
    string comma = ",";

    size_t num_primes = count_primes();
    string *p = new string [num_primes];

    // cout << "Saving results..." << endl << endl;

    if(se_file.is_open()) {
        for(i = 0; i <= n; i++) {
            if(primes[i] == 1) {
                p[j++] = to_string(i);
            }
        }

        for(i=0; i < num_primes; i++) {
            if(i == num_primes-1) {
                se_file << p[i];
            }
            else {
                se_file << p[i];
                se_file << comma;
            }
        }
    }

    se_file.close();
}

static size_t count_primes() {
    size_t i, k = 0;

    for(i=0; i < n; i++) {
        if(primes[i] == 1)
            k++;
    }

    return k;
}

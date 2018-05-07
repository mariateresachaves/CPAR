#include "main.hpp"


int main(int argc, char const *argv[]) {
    bool on = true;

    if(!right_args(argc, argv))
        exit(1);

    // DEBUG
    //m->print(m);

    while(on) {
        init_csv_filenames();

        Matrix *m = new Matrix(size, size);
        Matrix *l = new Matrix(size, size);
        Matrix *u = new Matrix(size, size);

        init_matrices(m, l, u);

        // Generate matrices files (csv format)
        /*cout << "Creating lu_decomp_1000.csv ..." << endl;
        print_matrixes_csv("lu_decomp_1000.csv", 1000);

        cout << "Creating lu_decomp_2000.csv ..." << endl;
        print_matrixes_csv("lu_decomp_2000.csv", 2000);

        cout << "Creating lu_decomp_3000.csv ..." << endl;
        print_matrixes_csv("lu_decomp_3000.csv", 3000);

        cout << "Creating lu_decomp_4000.csv ..." << endl;
        print_matrixes_csv("lu_decomp_4000.csv", 4000);

        cout << "Creating lu_decomp_5000.csv ..." << endl;
        print_matrixes_csv("lu_decomp_5000.csv", 5000);

        cout << "Creating lu_decomp_6000.csv ..." << endl;
        print_matrixes_csv("lu_decomp_6000.csv", 6000);*/

        parse_csv(m);

        switch(op) {
            case 1:
                //cout << "1. LU Decomposition Sequential [" << size << "x"
                //     << size << "]" << endl;

                // DEBUG
                /*(*m)(0,0)=1.0; (*m)(0,1)=2.0; (*m)(0,2)=3.0;
                (*m)(1,0)=4.0; (*m)(1,1)=5.0; (*m)(1,2)=6.0;
                (*m)(2,0)=7.0; (*m)(2,1)=8.0; (*m)(2,2)=9.0;*/

                lu_decomposition_sequential(m, l, u);

                print_results(l, u);

                print_execution_time();

                on = false;
                break;

            case 2:
                //cout << "2. LU Decomposition OpenMP [" << size << "x"
                //     << size << "]" << endl;

                lu_decomposition_OMP(m, l, u);

                print_results(l, u);

                print_execution_time();

                on = false;
                break;

            case 3:
                //cout << "3. LU Decomposition MPI [" << size << "x"
                //     << size << "]" << endl;

                lu_decomposition_MPI(m, l, u);

                on = false;
                break;

            default:
                cerr << "Option " << op << " is not a valid operation"
                     << endl;
                on = false;
                break;
        }

        // DEBUG
        /*cout << "Matrix M: " << endl;
        m->print(m);
        cout << "Matrix L: " << endl;
        l->print(l);
        cout << "Matrix U: " << endl;
        u->print(u);*/
    }

    return 0;
}

static bool right_args(int argc, char const *argv[]) {
    if(argc != 3) {
        cerr << "[Wrong_Args] usage: " << argv[0] << " "
             << "<algorithm> <size_matrix>" << endl
             << "\t Where:" << endl
             << "\t\t <algorithm> - type of algorithm to apply" << endl
             << "\t\t <size_matrix> - matrix size" << endl;
        return false;
    }

    else {
        istringstream arg1(argv[1]);
        istringstream arg2(argv[2]);

        if(!(arg1 >> op) || !(arg2 >> size)) {
            cerr << "[Wrong_Args] <algorithm> and <size_matrix> "
                 << "must be integers" << endl;
            return false;
        }
    }

    return true;
}

static void init_matrices(Matrix *m, Matrix *l, Matrix *u) {
    m->fill_zeros(m);
    l->fill_zeros(l);
    u->fill_zeros(u);
}

static void init_csv_filenames() {
    file_name = "LU_inputs/A_" + to_string(size)
                               + "x" + to_string(size) + ".csv";

    l_file_name = "LU_outputs/L_" + to_string(size)
                                  + "x" + to_string(size) + ".csv";

    u_file_name = "LU_outputs/U_" + to_string(size)
                                  + "x" + to_string(size) + ".csv";
}

static void parse_csv(Matrix *m) {
    ifstream myfile(file_name);
    string line;
    size_t i, j;
    vector<double> vect;
    double val;

    if(myfile.is_open()) {
            while(getline(myfile,line)) {
                stringstream ss(line);

                while(ss >> val) {
                   vect.push_back(val);

                   if(ss.peek() == ',')
                       ss.ignore();
                }
            }

            vector<double>::iterator it_begin = vect.begin();
            vector<double>::iterator it_end = vect.end();

            for(i=0; i < size; i++) {
                for(j=0; j < size; j++) {
                    (*m)(i,j) = *it_begin;
                    it_begin++;
                }
            }

            myfile.close();
    }

    else
        cout << "Unable to open file" << endl;
}

void print_matrixes_csv(const char* file_name, size_t matrix_size) {
    ofstream myfile(file_name);
    size_t i, j;
    string val;
    string comma = ",";

    if(myfile.is_open()) {
        for(i = 0; i < matrix_size; i++) {
            for(j = 0; j < matrix_size; j++) {
                val =  to_string(static_cast <double>(rand()) / static_cast <double>(101));

                if(j == matrix_size-1) {
                    myfile << val;
                }

                else {
                    myfile << val;
                    myfile << comma;
                }
            }
            myfile << endl;
        }
        myfile.close();
    }

    else
        cout << "Unable to open file" << endl;
}

static void print_execution_time() {
    cout << (float) ((t_stop.tv_sec - t_start.tv_sec)
            + (t_stop.tv_nsec - t_start.tv_nsec)/1000000000.0) << endl;

    /*cout << "Time = "
         << (float) ((t_stop.tv_sec - t_start.tv_sec)
            + (t_stop.tv_nsec - t_start.tv_nsec)/1000000000.0)
         << "s"
         << endl;*/
}

static void lu_decomposition_sequential(Matrix *m, Matrix *l, Matrix *u) {
    size_t i, k, j;
    double s;

    clock_gettime(CLOCK_MONOTONIC, &t_start);

    for(i = 0; i < size; i++) {
        // Upper Triangular
        for(k = i; k < size; k++) {
            // Summation of L(i, j) * U(j, k)
            s = 0;
            for(j = 0; j < i; j++)
                s += ((*l)(i,j) * (*u)(j,k));

            // Evaluating U(i, k)
            (*u)(i,k) = (*m)(i,k) - s;

            s = 0;
            if(i == k)
                (*l)(i,i) = 1; // Diagonal as 1
            else {
                for(j = 0; j < i; j++)
                    s += ((*l)(k,j) * (*u)(j,i));

                // Evaluating L(k, i)
                (*l)(k,i) = ((*m)(k,i) - s) / (*u)(i,i);
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &t_stop);
}

static void lu_decomposition_OMP(Matrix *m, Matrix *l, Matrix *u) {
    size_t i, k, j;
    double s=0;

    clock_gettime(CLOCK_MONOTONIC, &t_start);

    #pragma omp parallel for private(s,i,j,k)
    for(i = 0; i < size; i++) {
        // Upper Triangular
        for(k = i; k < size; k++) {
            // Summation of L(i, j) * U(j, k)
            s = 0;
            for(j = 0; j < i; j++)
                s += ((*l)(i,j) * (*u)(j,k));

            // Evaluating U(i, k)
            (*u)(i,k) = (*m)(i,k) - s;

            s = 0;
            if(i == k)
                (*l)(i,i) = 1.0; // Diagonal as 1
            else {
                for(j = 0; j < i; j++)
                    s += ((*l)(k,j) * (*u)(j,i));

                // Evaluating L(k, i)
                (*l)(k,i) = ((*m)(k,i) - s) / (*u)(i,i);
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &t_stop);
}

static void lu_decomposition_MPI(Matrix *m, Matrix *l, Matrix *u) {
    size_t i, k, j;
    double s=0;
    int dest, src, myrank, nproc, rows, mtype, offset;
    double start_time, end_time;

    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Find out rank, size
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if(myrank == 0) {
        //cout << "Size = " << size << ", number of nodes = " << nproc << endl;

        start_time = MPI_Wtime();

        rows = size / nproc;
        mtype = FROM_MASTER;
        offset = rows;

        for(dest = 1; dest < nproc; dest++) {
            // DEBUG
            //cout << " sending " << rows << " rows to task " << dest << endl;

            MPI_Send(&offset, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
            MPI_Send(&rows, 1, MPI_INT, dest, mtype, MPI_COMM_WORLD);
            MPI_Send(&(*m)(offset,0), rows*size, MPI_FLOAT, dest, mtype,
                MPI_COMM_WORLD);
            offset += rows;
        }

        for(i = 0; i < size; i++) {
            // Upper Triangular
            for(k = i; k < size; k++) {
                // Summation of L(i, j) * U(j, k)
                s = 0;
                for (j = 0; j < i; j++)
                    s += ((*l)(i,j) * (*u)(j,k));

                // Evaluating U(i, k)
                (*u)(i,k) = (*m)(i,k) - s;

                s = 0;
                if (i == k)
                    (*l)(i,i) = 1.0; // Diagonal as 1
                else {
                    for (j = 0; j < i; j++)
                        s += ((*l)(k,j) * (*u)(j,i));

                    // Evaluating L(k, i)
                    (*l)(k,i) = ((*m)(k,i) - s) / (*u)(i,i);
                }
            }
        }

        mtype = FROM_WORKER;

        for(src = 1; src < nproc; src++) {
            MPI_Recv(&(*l)(offset, 0), rows*size, MPI_FLOAT, src, mtype,
                MPI_COMM_WORLD, &status);
            MPI_Recv(&(*u)(offset, 0), rows*size, MPI_FLOAT, src, mtype,
                MPI_COMM_WORLD, &status);

            // DEBUG
            /*cout << " recvd " << rows << " rows from task "
                 << src << " , offset = " <<  offset << endl;*/
        }

        end_time = MPI_Wtime();

        cout << end_time-start_time << endl;

        /*cout << endl << "Execution time on " << nproc
             << " nodes: " << end_time-start_time << endl << endl;*/
    }

    else {
        mtype = FROM_MASTER;

        MPI_Recv(&offset, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD, &status);
        MPI_Recv(&rows, 1, MPI_INT, 0, mtype, MPI_COMM_WORLD, &status);
        MPI_Recv(&(*m)(offset,0), rows*size, MPI_FLOAT, 0, mtype,
            MPI_COMM_WORLD, &status);

        // DEBUG
        /*cout << "Rank = " << myrank << ", offset = " << offset
             << ", row = " << rows
             << ", m[offset][0] = " << (*m)(offset,0) << endl;*/

        for(i = 0; i < size; i++) {
            // Upper Triangular
            for(k = i; k < size; k++) {
                // Summation of L(i, j) * U(j, k)
                s = 0;
                for(j = 0; j < i; j++)
                    s += ((*l)(i,j) * (*u)(j,k));

                // Evaluating U(i, k)
                (*u)(i,k) = (*m)(i,k) - s;

                s = 0;
                if(i == k)
                    (*l)(i,i) = 1.0; // Diagonal as 1
                else {
                    for(j = 0; j < i; j++)
                        s += ((*l)(k,j) * (*u)(j,i));

                    // Evaluating L(k, i)
                    (*l)(k,i) = ((*m)(k,i) - s) / (*u)(i,i);
                }
            }
        }

        // DEBUG
        /*cout << "Rank = " << myrank << ", offset = " << offset
             << ", row = " << rows << ", c[offset][0] = " << (*m)(offset, 0)
             << endl;*/

        mtype = FROM_WORKER;

        MPI_Send(&(*l)(offset, 0), rows*size, MPI_FLOAT, 0, mtype,
            MPI_COMM_WORLD);
        MPI_Send(&(*u)(offset, 0), rows*size, MPI_FLOAT, 0, mtype,
            MPI_COMM_WORLD);
    }

    MPI_Finalize();

    print_results(l, u);
}

static void print_results(Matrix *l, Matrix *u) {
    ofstream u_file(u_file_name.c_str());
    ofstream l_file(l_file_name.c_str());
    size_t i, j;
    string s_l, s_u;
    string comma = ",";

    //cout << "Saving results..." << endl << endl;

    if(l_file.is_open() && u_file.is_open()) {
        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                s_l = util::to_string<>((*l)(i,j));
                s_u = util::to_string<>((*u)(i,j));

                if(j == size-1) {
                    l_file << s_l;
                    u_file << s_u;
                }
                else {
                    l_file << s_l;
                    l_file << comma;
                    u_file << s_u;
                    u_file << comma;
                }
            }
            l_file << endl;
            u_file << endl;
        }
        l_file.close();
        u_file.close();
    }
}

#include <iostream>
#include "../GEMM.cpp"

using namespace std;

void runGEMM_Simple(string path , int bs)
{
    take_matrix_input(path);
    cout << "Algorithm name : GEMM Simple\n" << "Result matrix: " <<endl;
    auto start = chrono::high_resolution_clock::now();

    multiplysimple();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    printmc();

    cout << "Execution time : " << sduration.count() << "ms" << endl;
}

void runGEMM_Bloncking(string path , int bs)
{
    cout << "Algorithm name : GEMM Blocking\n" << "Result matrix: " <<endl;
    auto start = chrono::high_resolution_clock::now();

    multiplyblocking(bs);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    printmc();

    cout << "Execution time : " << duration.count() << "ms" << endl;
}
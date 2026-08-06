#include <iostream>
#include "../src/GEMM.cpp"

using namespace std;

void runGEMM_Simple(string path)
{
    take_matrix_input(path);
    cout << "Algorithm name : GEMM Simple\n" << "Result matrix: " <<endl;
    auto start = chrono::high_resolution_clock::now();

    multiplysimple();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    printmc();

    cout << "Execution time : " << duration.count() << "ms" << endl;
}

void runGEMM_Blocking(string path , int bs)
{
    cout << "Algorithm name : GEMM Blocking\n" << "Result matrix: " <<endl;
    auto start = chrono::high_resolution_clock::now();

    multiplyblocking(bs);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    printmc();

    cout << "Execution time : " << duration.count() << "ms" << endl;
}
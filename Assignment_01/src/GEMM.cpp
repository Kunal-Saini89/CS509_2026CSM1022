#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <random>

using namespace std;

int m , k , n;
vector<vector<int>> ma ,mb ,mc;

void take_matrix_input(string path)
{
    ifstream file(path);
    if(!file.is_open())
    {
        throw runtime_error("Input file isn't opened properly\n"); // throw a runtime error if file opened isn't successful
    }

    string line;
    getline(file , line);
    stringstream ss(line);

    ss >> m >> k >> n;

    for(int i = 0; i < m; i++) // building Matrix A (ma)
    {
        getline(file , line);

        ss.clear();
        ss.str(line);

        vector<int> temp;
        for(int j = 0; j < k; j++)
        {
            int x;
            ss >> x;
            temp.push_back(x);
        }
        ma.push_back(temp);
    }

    for(int i = 0; i < k; i++) //Building Matrix B (mb)
    {
        getline(file , line);

        ss.clear();
        ss.str(line);
        
        vector<int> temp;
        for(int j = 0; j < n; j++)
        {
            int x;
            ss >> x;
            temp.push_back(x);
        }
        mb.push_back(temp);
    }
}

void multiplysimple()
{
    mc = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) //Actual Multiplication logic
    {
        for (int j = 0; j < n; j++) 
        {
            for (int x = 0; x < k; x++)
            {
                mc[i][j] += ma[i][x] * mb[x][j];
            }
        }
    }
}

void multiplyblocking(int bs = 4) //Blocking multiplication with block size as a argument
{
    mc = vector<vector<int>>(m, vector<int>(n, 0));
    for(int bi = 0; bi < m; bi += bs)
    {
        for(int bj = 0; bj < n ; bj += bs)
        {
            for(int bx = 0; bx < k; bx += bs)
            {

                for(int i = bi;  i < min(bi + bs , m) ; i++)
                {
                    for(int j = bj;  j < min(bj + bs , n) ; j++)
                    {
                        for(int x = bx;  x < min(bx + bs , k) ; x++)
                        {
                            mc[i][j] += ma[i][x] * mb[x][j];
                        }
                    }
                }

            }
        }
    }
}

void printmc()
{
    for (int i = 0; i < m; i++) // Printing the result matrix
    {
        for (int j = 0; j < n; j++) 
        {
            cout << mc[i][j] << " ";
        }
        cout << "\n";
    }
}

void printGEMM_Simple(string path)
{
    take_matrix_input(path);//filling up A and B matrices for multiplication

    cout << "Algorithm name : GEMM Simple\n" << "Result matrix: " <<endl;

    multiplysimple();

    //printmc();
}

void printGEMM_Blocking(String path , int bs)
{
    take_matrix_input(path);//filling up A and B matrices for multiplication
    
    cout << "Algorithm name : GEMM Blocking\n" << "Result matrix: " <<endl;

    multiplyblocking(bs);

    //printmc();
}
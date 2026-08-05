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

int getRandomInt(int min, int max) {
    // 1. Initialize random number generator engine with a seed
    std::random_device rd;  // Obtains a random seed from hardware
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // 2. Define the inclusive range [min, max]
    std::uniform_int_distribution<int> distrib(min, max);

    // 3. Generate and return the random number
    return distrib(gen);
}

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
            temp.push_back(getRandomInt(0 , 10));
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
            temp.push_back(getRandomInt(0 , 10));
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

int main() 
{
    take_matrix_input("Input.txt");//filling up A and B matrices for multiplication 

    cout << "Algorithm name : GEMM Simple\n" << "Result matrix: " <<endl;
    auto start = chrono::high_resolution_clock::now();

    multiplysimple();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    //printmc();

    cout << "Execution time : " << duration.count() << "ms" << endl;

    cout << endl;

    cout << "Algorithm name : GEMM Blocking\n" << "Result matrix: " <<endl;
    start = chrono::high_resolution_clock::now();

    multiplyblocking(10);

    end = chrono::high_resolution_clock::now();
    duration = end - start;

    //printmc();

    cout << "Execution time : " << duration.count() << "ms" << endl;
    return 0;
}
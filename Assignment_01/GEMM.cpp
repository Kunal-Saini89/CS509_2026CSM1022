#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <chrono>

using namespace std;

int m , k , n;
vector<vector<int>> ma ,mb ,mc;

void take_matrix_input(string path)
{
    ifstream file(path);
    if(!file.is_open())
    {
        throw runtime_error("Input file isn't opened properly\n"); //// throw a runtime error if file opened isn't successful
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
    for (int i = 0; i < m; i++) //Actual Multiplication logic
    {
        vector<int> temp;
        for (int j = 0; j < n; j++) 
        {
            int t = 0;
            for (int x = 0; x < k; x++)
            {
                t += ma[i][x] * mb[x][j];
            }
            temp.push_back(t);
        }
        mc.push_back(temp);
    }
}

void multiplyblocking()
{
    
}

int main() 
{
    cout << "GEMM Simple\n" << "Result matrix: " <<endl;
    auto start = chrono::high_resolution_clock::now();

    take_matrix_input("Input.txt");
    multiplysimple();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    for (int i = 0; i < m; i++) // Printing the result matrix
    {
        for (int j = 0; j < n; j++) 
        {
            cout << mc[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Execution time : " << duration.count() << "ms" << endl;
    return 0;
}
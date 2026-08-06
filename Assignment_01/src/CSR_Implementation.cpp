#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;

int convert(string path , vector<int> &row_ptr, vector<int> &col_idx , vector<int> &values , bool needwieght = true) // return source
{
    ifstream file(path);
    if(!file.is_open())
    {
        throw runtime_error("Input file isn't opened properly\n"); // throw a runtime error if file opened isn't successful
    }

    int vcount , ecount , u ,degree;
    string line;
    getline(file , line);
    stringstream ss(line);

    ss >> vcount >> ecount;

    while(getline(file , line))
    {
        ss.clear();
        ss.str(line);

        if(line[0] == 'S' || line[0] == 's')// end of the graph representation
        {
            break;
        }
        ss >> u >> degree;

        row_ptr.push_back(col_idx.size()); // adding start index of neighbors of a node 
        for(int i = 0 ; i < degree ; i++)
        {
            int temp;
            ss >> temp;
            col_idx.push_back(temp);
            if(needwieght)
            {
                ss >> temp;
                values.push_back(temp);
            }
        }
    }
     ss >> line;
    int x;
    ss >> x;
    row_ptr.push_back(col_idx.size());
    return x;
}

void printCSR(string path , bool needwieght = false)
{
    vector<int> row_ptr , col_idx , values;
    auto start = chrono::high_resolution_clock::now();

    convert(path , row_ptr , col_idx , values , needwieght);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Algo took " << duration.count() << " ms" << endl;

    for(int n : row_ptr)
    {
        cout << " " << n << " ";
    }
    cout << endl;
    for(int n : col_idx)
    {
        cout << " " << n << " ";
    }
    cout << endl;
    for(int n : values)
    {
        cout << " " << n << " ";
    }
    cout << endl;
}
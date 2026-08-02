#include <iostream>

using namespace std;

int main() 
{
    int m = 3, k = 4, n = 2;

    int ma[m][k] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    int mb[k][n] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}};
    int mc[m][n] = {0};

    for (int i = 0; i < m; i++) //Actual Multiplication logic
    {
        for (int j = 0; j < n; j++) 
        {
            mc[i][j] = 0;     
            for (int x = 0; x < k; x++)
            {
                mc[i][j] += ma[i][x] * mb[x][j];
            }
        }
    }

    cout << "Result Matrix C:\n"; //Printing the resultant matrix
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << mc[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
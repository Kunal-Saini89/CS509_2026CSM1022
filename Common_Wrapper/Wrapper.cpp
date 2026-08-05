#include <iostream>
#include <fstream>
#include <stdexcept>
#include "../Assignment_01/Driver/GEMMDriver.cpp"
#include "../Assignment_01/Driver/CSRDriver.cpp"


using namespace std;

int main()
{
    cout<< "Enter 1 for GEMM Simple" << endl;
    cout<< "Enter 2 for GEMM Blocking" << endl;
    cout << "Enter 3 for CSR" << endl;
    cout << "Enter 4 to exit" << endl;
    int op , bs;
    cin >> op;
    
    switch(op)
    {
        case 1:
        {
            
        }

        case 2:
        {

        }

        case 3:
        {

        }

        case 4:
        {

        }

        default :
        {
            throw runtime_error("This operation is invalid !!");
        }
    }

    switch(op)
    {
        case 1:
        {
            runGEMM_Simple();
        }

        case 2:
        {

        }

        case 3:
        {

        }

        case 4:
        {

        }

        default :
        {
            throw runtime_error("This operation is invalid !!");
        }
    }
    return 0;
}
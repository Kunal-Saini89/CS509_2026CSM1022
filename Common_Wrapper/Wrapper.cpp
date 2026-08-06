#include <iostream>
#include <fstream>
#include <stdexcept>
#include "../Assignment_01/Driver/GEMMDriver.cpp"
#include "../Assignment_01/Driver/CSRDriver.cpp"


using namespace std;

int main()
{
    cout << "Give your Test case in the input file " << endl;
    cout << endl;
    cout << endl;
    cout<< "Enter 1 for GEMM Simple" << endl;
    cout<< "Enter 2 for GEMM Blocking" << endl;
    cout << "Enter 3 for CSR" << endl;
    cout << "Enter 4 to exit" << endl;
    cout << "Enter opertaion : ";
    int op , bs;
    cin >> op;
    cout << endl;
    
    switch(op)
    {
        case 1:
        {
            runGEMM_Simple("../Assignment_01/Input.txt");
            break;
        }

        case 2:
        {
            cout << "Enter block size :  ";
            cin >> bs;
            runGEMM_Blocking("../Assignment_01/Input.txt" , bs);
            break;
        }

        case 3:
        {
            cout << "Enter 1 if need weights OR 0 if no weights : ";
            int x;
            cin >> x;

            if(x == 1)
            {
                runCSR("../Assignment_01/Input.txt" , true);
            }
            else
            {
                runCSR("../Assignment_01/Input.txt" , false);
            }
            break;
        }

        case 4:
        {
            cout << "Exiting the program" << endl;
            exit(0);
        }

        default :
        {
            throw runtime_error("This operation is invalid !!");
        }
    }
    return 0;
}
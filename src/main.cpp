#include <cstdlib>
#include <iostream>
#include "DenseMatrix.h"

using namespace std;

int main()
{
    DenseMatrix<int> mymat(3, 3);
    mymat.set(1, 1, 5);
    int a = mymat.get(1, 1);
    cout << a << "\n";
    mymat.print();


    return 0;
}

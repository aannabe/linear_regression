#include "DenseMatrix.h"
#include "MatrixOperations.h"
#include "Utilities.h"

int main() {
    DenseMatrix A(2, 3);
    DenseMatrix B(3, 2);
    DenseMatrix C(2, 2);

    A.set(0, 0, 1.1f); A.set(0, 1, 2.2f); A.set(0, 2, 3.3f);
    A.set(1, 0, 4.4f); A.set(1, 1, 5.5f); A.set(1, 2, 6.6f);

    B.set(0, 0, 7.0f);  B.set(0, 1, 8.0f);
    B.set(1, 0, 9.0f);  B.set(1, 1, 10.0f);
    B.set(2, 0, 11.0f); B.set(2, 1, 12.0f);

    C.set(0, 0, 1.0f); C.set(0, 1, 3.0f);
    C.set(1, 0, 2.0f); C.set(1, 1, 5.0f);

    auto D = MatrixOperations::multiply(A, B);
    //D->print();

    //A.print();
    auto At = A.transpose();
    //At->print();

    auto Ci = C.inverse();
    //Ci->print();

    DenseMatrix X(1, 1);
    DenseMatrix Y(1, 1);

    loadCSV("data/data_Y1X.csv", X, Y);

    auto beta = MatrixOperations::linearRegression(X, Y);
    beta->print();

    return 0;
}


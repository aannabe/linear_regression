#include "DenseMatrix.h"
#include "MatrixOperations.h"

int main() {
    DenseMatrix A(2, 3);
    DenseMatrix B(3, 2);

    A.set(0, 0, 1.1f); A.set(0, 1, 2.2f); A.set(0, 2, 3.3f);
    A.set(1, 0, 4.4f); A.set(1, 1, 5.5f); A.set(1, 2, 6.6f);

    B.set(0, 0, 7.0f);  B.set(0, 1, 8.0f);
    B.set(1, 0, 9.0f);  B.set(1, 1, 10.0f);
    B.set(2, 0, 11.0f); B.set(2, 1, 12.0f);

    auto C = MatrixOperations::multiply(A, B);
    C->print();

    A.print();
    auto At = A.transpose();
    At->print();

    return 0;
}


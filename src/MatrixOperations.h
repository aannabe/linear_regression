#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "DenseMatrix.h"

// Utility class: provides matrix operations like multiplication for DenseMatrix class.
// All methods are static — no state is stored.

class MatrixOperations {
public:
    // Using a static smart pointer below to multiply A * B and return a new matrix as unique_ptr<DenseMatrix>
    static std::unique_ptr<DenseMatrix> multiply(const DenseMatrix& A, const DenseMatrix& B);
};

#endif // MATRIX_OPERATIONS_H

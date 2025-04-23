#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <memory> // For std::unique_ptr
#include "BaseMatrix.h"

// Utility class: provides matrix operations like multiplication.
// All methods are static — no state is stored.

class MatrixOperations {
public:
    // Using a static smart pointer below to multiply A * B and return a new matrix as unique_ptr<BaseMatrix>
    static std::unique_ptr<BaseMatrix> multiply(const BaseMatrix& A, const BaseMatrix& B);
};

#endif // MATRIX_OPERATIONS_H

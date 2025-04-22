#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "BaseMatrix.h"
#include <memory> // For std::unique_ptr

// Utility class: provides matrix operations like multiplication.
// All methods are static — no state is stored.

template<typename T>
class MatrixOperations {
public:
    // Using a static smart pointer below to multiply A * B and return a new matrix as unique_ptr<BaseMatrix>
    static std::unique_ptr<BaseMatrix<T>> multiply(const BaseMatrix<T>& A, const BaseMatrix<T>& B);
};

#endif // MATRIX_OPERATIONS_H

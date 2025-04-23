#include "MatrixOperations.h"
#include "DenseMatrix.h"

// Multiply two matrices A * B and return result as a new matrix.
std::unique_ptr<DenseMatrix> MatrixOperations::multiply(const DenseMatrix& A, const DenseMatrix& B) {
    // Check dimensions match: (A.cols must == B.rows)
    if (A.numCols() != B.numRows())
        throw std::invalid_argument("Incompatible matrix dimensions");

    // Create a new DenseMatrix to store the result
    // Use std::make_unique to return a smart pointer (heap allocated)
    auto result = std::make_unique<DenseMatrix>(A.numRows(), B.numCols());

    // Perform multiplication
    for (int i = 0; i < A.numRows(); ++i) {
        for (int j = 0; j < B.numCols(); ++j) {
            double sum = 0.0;
            for (int k = 0; k < A.numCols(); ++k) {
                // Use virtual get() to retrieve values.
                sum += A.get(i, k) * B.get(k, j);
            }
            result->set(i, j, sum); // Use virtual set()
        }
    }

    return result; // Return smart pointer; no need to manually delete
}

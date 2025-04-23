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

std::unique_ptr<DenseMatrix> MatrixOperations::linearRegression(const DenseMatrix& X, const DenseMatrix& Y) {
    // Y = X*beta + err
    // Y:    [n x 1] (n: number of observations)
    // X:    [n x p] (p: number of regressors)
    // beta: [p x 1]
    // beta = (X^T X)^{-1} (X^T Y)

    // Check dimensions:
    if (X.numRows() != Y.numRows())
        throw std::invalid_argument("Incompatible X and Y matrices for linear regression!");

    auto Xt = X.transpose();

    auto XtX = MatrixOperations::multiply(*Xt, X);

    auto XtX_inv = XtX->inverse();

    auto XtY = MatrixOperations::multiply(*Xt, Y);

    auto beta = MatrixOperations::multiply(*XtX_inv, *XtY);

    return beta;
}

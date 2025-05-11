#include "DenseMatrix.h"

// Constructor
DenseMatrix::DenseMatrix(int r, int c) : BaseMatrix(r, c), data(r, std::vector<double>(c, 0.0)) {}
// Syntax for initializing a 2D matrix with 0 initial values:
// std::vector<std::vector<double>> name(ROW_COUNT, std::vector<double>(COLUMN_COUNT));

// Get element
double DenseMatrix::get(int r, int c) const {
    return data[r][c];
}

// Set element
void DenseMatrix::set(int r, int c, double value) {
    data[r][c] = value;
}

// Print matrix
void DenseMatrix::print() const {
    std::cout.precision(12);
    for (const auto& row : data) {
        for (const auto& val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}

// Transpose method
std::unique_ptr<DenseMatrix> DenseMatrix::transpose() const {
    // Note: transpose has cols * rows
    auto result = std::make_unique<DenseMatrix>(this->cols, this->rows);

    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            result->set(j, i, this->get(i, j));
        }
    }

    return result;
}

std::unique_ptr<DenseMatrix> DenseMatrix::inverse() const {
    // For inverse to exist, it needs to:
    //    1) Have n x n square form
    //    2) Be non-singular (invertible, det(A) != 0)

    if (this-> rows != this->cols)
        throw std::runtime_error("Matrix must be square to compute the inverse!");

    int n = this->rows;
    DenseMatrix augmented(n, 2 * n); // augmented matrix that holds [A | I]

    // Step 1: Form [A | I]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented.set(i, j, this->get(i, j)); // Copying A
        }
        augmented.set(i, n + i, 1.0); // Add identity
    }

    // Step 2: Gauss-Jordan elimination
    for (int i = 0; i < n; ++i) {
        double pivot = augmented.get(i, i);
        if (pivot == 0.0) {
        // if pivot is 0, we need to push it lower by exchanging with another row:
        bool found = false;
        for (int y = i + 1; y < n; ++y) {
            if (augmented.get(y, i) != 0) {
                // Swap rows:
                for (int x = 0; x < 2 * n; ++x) {
                    double c1 = augmented.get(i, x);
                    double c2 = augmented.get(y, x);
                    augmented.set(i, x, c2);
                    augmented.set(y, x, c1);
                }
                pivot = augmented.get(i, i);
                found = true;
                break;
            }
        }
        if(!found)
            throw std::runtime_error("Matrix is singular and can not be inverted!");
        }

        // Normalize pivot row
        for (int j = 0; j < 2 * n; ++j)
            augmented.set(i, j, augmented.get(i, j) / pivot);

        // Eliminate other rows
        for (int k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = augmented.get(k, i);
            for (int j = 0; j < 2 * n; ++j) {
                double value = augmented.get(k, j) - factor * augmented.get(i, j);
                augmented.set(k, j, value);
            }
        }
    }

    // Step 3: Extract right half as the invere
    auto inverse = std::make_unique<DenseMatrix>(n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            inverse->set(i, j, augmented.get(i, n + j));
    return inverse;
}


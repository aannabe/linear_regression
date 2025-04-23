#include "DenseMatrix.h"

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
    for (const auto& row : data) {
        for (const auto& val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}

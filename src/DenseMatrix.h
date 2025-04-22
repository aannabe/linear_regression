#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "BaseMatrix.h"

using namespace std;

// Template class DenseMatrix inherits from BaseMatrix<T>
template<typename T>
class DenseMatrix : public BaseMatrix<T> {
private:
    std::vector<std::vector<T>> data;

public:
    // Constructor
    DenseMatrix(int r, int c);

    T get(int r, int c) const override;
    void set(int r, int c, T value) override;
    void print() const override;
};

// Constructor (Template functions need to be implemented in the header files)
template<typename T>
DenseMatrix<T>::DenseMatrix(int r, int c)
    : BaseMatrix<T>(r, c), data(r, std::vector<T>(c, T())) {}
    // std::vector<std::vector<int> > vector_name(
    //     ROW_COUNT,
    //     std::vector<int>(COLUMN_COUNT)); // Defaults to zero initial value

// Get element
template<typename T>
T DenseMatrix<T>::get(int r, int c) const {
    return data[r][c];
}

// Set element
template<typename T>
void DenseMatrix<T>::set(int r, int c, T value) {
    data[r][c] = value;
}

// Print matrix
template<typename T>
void DenseMatrix<T>::print() const {
    for (const auto& row : data) {
        for (const auto& val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}

#endif // DENSE_MATRIX_HH

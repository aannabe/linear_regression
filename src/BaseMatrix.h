#ifndef BASE_MATRIX_H
#define BASE_MATRIX_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr
#include <stdexcept>

// Abstract base class that defines a general interface for all matrix-like structures (eg, dense vs. sparse).
// Any class inheriting this must implement the pure virtual functions.

class BaseMatrix {
protected:
    int rows, cols; // All matrix types will have these data members.

public:
    // Constructor that initializes the matrix dimensions.
    // Uses a member initializer list, which is more efficient than assignment inside the constructor body.
    BaseMatrix(int r, int c) : rows(r), cols(c) {}

    // Virtual destructor ensures proper cleanup when deleting derived class objects via a BaseMatrix pointer.
    // = default means use the compiler-generated destructor.
    virtual ~BaseMatrix() = default;

    // The below get() and set() methods need to be virtual since BaseMatrix class will not hold matrix data.
    // Actual data will be hold by the derived classes, which will need to implement these methods themselves.

    // Gets the value at the given (row, col) position.
    // const-qualified since it doesn’t modify the matrix.
    virtual double get(int row, int col) const = 0;

    // Sets the value at the given (row, col) position.
    virtual void set(int row, int col, double value) = 0;

    // Utility function to print the matrix to the console.
    // It is virtual since dense vs. sparse matrix printing could use different print behavior.
    // It needs to be implemented (via overriding) for each dense and sparse matrices separately.
    virtual void print() const = 0;

    // Below two functions get the number of rows and columns.
    // They are not virtual: no need to re-implement via overriding.
    int numRows() const { return rows; }
    int numCols() const { return cols; }

};

#endif  // BASE_MATRIX_H

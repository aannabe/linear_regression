#ifndef BASE_MATRIX_H
#define BASE_MATRIX_H

// Abstract base class that defines a general interface for all matrix-like structures.
// Any class inheriting this must implement the pure virtual functions.

// Template class: T is the type of matrix elements (e.g., int, float, double)
template<typename T>
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

    // Gets the value at the given (row, col) position.
    // const-qualified since it doesn’t modify the matrix.
    virtual T get(int row, int col) const = 0;

    // Sets the value at the given (row, col) position.
    virtual void set(int row, int col, T value) = 0;

    // Utility function to print the matrix to the console.
    virtual void print() const = 0;

    // Below two functions get the number of rows and columns.
    // They are not virtual: no need to re-implement via overriding.
    int numRows() const { return rows; }
    int numCols() const { return cols; }

};

#endif  // BASE_MATRIX_H

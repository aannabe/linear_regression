#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include "BaseMatrix.h"

class DenseMatrix : public BaseMatrix {
private:
    std::vector<std::vector<double>> data;

public:
    // Constructor
    DenseMatrix(int r, int c);

    double get(int r, int c) const override;
    void set(int r, int c, double value) override;
    void print() const override;
};

#endif // DENSE_MATRIX_HH

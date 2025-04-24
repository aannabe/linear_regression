#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include "DenseMatrix.h"

// Load CSV into X and Y where the first column is Y, rest are features

void loadCSV(const std::string& filename, DenseMatrix& X, DenseMatrix& Y);

#endif // UTILITIES_H

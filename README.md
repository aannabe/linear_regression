# LinReg: Minimal Linear Algebra in C++ with Linear Regression

This project is a self-contained C++ implementation of a **minimal linear algebra library**, and a **linear regression engine**.
The goal is to demonstrate how to implement the simplest linear regression from scratch, including the matrix operations such as multiplication, transpose, and inverse (via Gauss-Jordan elimination).

The results are validated in the below Figure and compared against the `scikit-learn` implementation in Python.
![Regression Comparison](validate/comparison.png)

## Approach

This repo uses the closed-form solution to linear regression of $~Y = X \beta + \varepsilon$, computed as $~~~\beta = (X^T X)^{-1} X^T Y~~~$ where:

$Y~$: ($[n \times 1]$) target values   
$X~$: ($[n \times p]$) input matrix   
$\beta~$: ($[p \times 1]$) learned coefficients (including the bias term, automatically added)   

and:

$n~$: number of samples or observations   
$p~$: number of features   
$\varepsilon~$: error in the model

## Build

C++11 or later required.
```
make
```

## Inputs
- The Y and X data are given in `data/data_Y_3X.csv`, where the first column is Y and the rest is X.
- In `main.cpp`, the above csv file is read, and after `./linreg`, the $\beta$ values are printed.

## Design

### Classes:

- `BaseMatrix`: Abstract base class for deriving matrix-like classes.
- `DenseMatrix`: Inherits from `BaseMatrix` and stores dense 2D data using `std::vector`.
- Inheritance is used to allow for extensible designs like `SparseMatrix` in the future.
- Smart pointers are used (C++11 or later) to ensure memory safety.

### Methods:
- Single-matrix operations, such as transpose or inverse, are methods of the `DenseMatrix` objects.
- Two-matrix operations, such as multiplications or linear-regression are implemented in the `MatrixOperations` class.
- The `linearRegression()` method adds the bias term automatically for intercept values and returns the $\beta$ values.

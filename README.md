# LinReg: Minimal Linear Algebra in C++ with Linear Regression

This project is a self-contained C++ implementation of a **minimal linear algebra library**, and a **linear regression engine**.
The goal is to demonstrate how to implement the simplest linear regression from scratch, including the matrix operations such as multiplication, transpose, and inverse (via Gauss-Jordan elimination).

The results are validated below by comparing against numpy's least-squares (lstsq) and singular-value-decomposition (svd) routines.

| Method             | $\beta_0$   | $\beta_1$   | $\beta_2$   | $\beta_3$   | $\beta_4$   |
| ------------------ | ----------- | ----------- | ----------- | ----------- | ----------- |
| numpy.linalg.lstsq |  3.78468983 | -3.00517361 |  1.99251052 | -1.01022950 |  0.06021616 |
| numpy.linalg.svd   |  3.78468983 | -3.00517361 |  1.99251052 | -1.01022950 |  0.06021616 |
| LinReg (inverse)   |  3.78468983 | -3.00517361 |  1.99251052 | -1.01022950 |  0.06021616 |
| True values        |  4.00000000 | -3.00000000 |  2.00000000 | -1.00000000 |  0.00100000 |

## Approach

This repo uses the closed-form solution to linear regression, namely the normal equation, for $~Y = X \beta + \varepsilon$, computed as $~~~\beta = (X^T X)^{-1} X^T Y~~~$ where:

$Y~$: ($[n \times 1]$) target/reference values,   
$X~$: ($[n \times p]$) input/design matrix,   
$\beta~$: ($[p \times 1]$) regression coefficients (including the bias term, automatically added),   

and:

$n~$: number of samples or observations,   
$p~$: number of features,   
$\varepsilon~$: error in the model.

Derivation of the normal equation: [Video](https://youtu.be/zRIXAC-0yIY?si=sW2O8pCfUe8sjrBI).

The $(X^T X)^{-1}$ inverse matrix is computed using the Gauss-Jordan elimination method.
This is only for demonstration purposes and is not recommended in practice due to numerical instability.
SVD or QR decomposition approaches are generally recommended.

## Build

C++11 or later required.
```
make
```

## Inputs
- The Y and X data are given in `data/data_y_beta.csv`, where the first column is Y and the rest is X.
- In `main.cpp`, the above csv file is read, and after `./linreg`, the $\beta$ values are printed.

## Design

### Classes:

- `BaseMatrix`: Abstract base class for deriving matrix-like classes.
- `DenseMatrix`: Inherits from `BaseMatrix` and stores dense 2D data using `std::vector`.
- Inheritance is used to allow for extensible designs like `SparseMatrix` in the future.
- Smart pointers are used (C++11 or later) to ensure memory safety.

### Methods:
- Single-matrix operations, such as transpose or inverse, are methods of the `DenseMatrix` objects.
- Two-matrix operations, such as multiplications or linear regression, are implemented in the `MatrixOperations` class.
- The `linearRegression()` method adds the bias term automatically for intercept values and returns the $\beta$ values.

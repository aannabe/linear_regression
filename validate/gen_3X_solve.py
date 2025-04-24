#!/usr/bin/env python3

import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression

# Set random seed for reproducibility
np.random.seed(42)

# Parameters
n_samples = 100
true_beta = [3.5, -2.0, 1.2]  # Coefficients for X1, X2, X3
bias = 5.0

# Generate random features
X = np.random.randn(n_samples, 3)

# Generate target with noise
noise = np.random.normal(0, 1.0, size=n_samples)
Y = bias + X @ true_beta + noise # @ is the matrix multiplication operator

# Combine y and X into one matrix for saving
data = np.column_stack((Y, X))

# Save to CSV: first column is y, then X
df = pd.DataFrame(data)
df.to_csv("../data/data_Y3X.csv", index=False, header=False)

# Run linear regression (for comparison with C++)
model = LinearRegression()
model.fit(X, Y)

print("True regression coefficients:")
print("Intercept (bias):", bias)
print("Coefficients:", true_beta)
print("\n")
print("sklearn linear regression coefficients:")
print("Intercept (bias):", model.intercept_)
print("Coefficients:", model.coef_)

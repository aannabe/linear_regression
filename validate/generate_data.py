#!/usr/bin/env python3

import numpy as np
import pandas as pd

# Set random seed for reproducibility
np.random.seed(42)

n_samples = 200

# Parameters
bias = 4.0  # True beta_0 (intercept)
true_beta = [-3.0, 2.0, -1.0, 1e-3] # True beta_i i > 0

# Generate random samples
X = np.random.rand(n_samples, len(true_beta)) # uniform
X = X * 10

# Generate target with noise
sigma = 1.0
noise = np.random.normal(0, sigma, size=n_samples)
Y = bias + X @ true_beta + noise # @ is the matrix multiplication operator

# Combine Y and X into one matrix for saving
data = np.column_stack((Y, X))

# Save to CSV: first column is y, then X
df = pd.DataFrame(data)
df.to_csv("../data/data_y_beta.csv", index=False, header=False)


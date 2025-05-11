#!/usr/bin/env python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

np.set_printoptions(formatter={'float': '{: 0.8f}'.format})

# Load the CSV (no headers)
df = pd.read_csv("../data/data_y_beta.csv", header=None)
y = df.iloc[:,0].values
x = df.iloc[:,1:].values

# Add bias term (intercept)
X_design = np.hstack([np.ones((x.shape[0], 1)), x])

# Least Squares Fit
beta_ls, *_ = np.linalg.lstsq(X_design, y, rcond=None)
y_pred_ls = X_design @ beta_ls
print("np.linalg.lstsq: ",   beta_ls)

# Singular Value Decomposition Fit
U, S, Vt = np.linalg.svd(X_design, full_matrices=False)
S_inv = np.diag(1 / S)
beta_svd = Vt.T @ S_inv @ U.T @ y
y_pred_svd = X_design @ beta_svd
print("np.linalg.svd:   ",   beta_svd)

# C++ Regression Results
beta_cpp = np.array([3.78468983464, -3.00517360712, 1.99251051818, -1.01022950388, 0.0602161581])
print("LinReg (inverse):",   beta_cpp)

# True Values
beta_true = np.array([4.0, -3.0, 2.0, -1.0, 0.001])
print("True values:     ",   beta_true)


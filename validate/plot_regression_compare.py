#!/usr/bin/env python3

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Load the CSV (no headers)
df = pd.read_csv("../data/data_Y1X.csv", header=None)
y = df[0].values
X = df[1].values.reshape(-1, 1)  # reshape for sklearn

# Fit using scikit-learn
model = LinearRegression()
model.fit(X, y)

py_bias = model.intercept_
py_weight = model.coef_[0]

print(f"Python model: y = {py_bias:.3f} + {py_weight:.3f} * x")

# C++ regression results
cpp_bias = 5.2104
cpp_weight = -3.51561

print(f"C++ model:    y = {cpp_bias:.3f} + {cpp_weight:.3f} * x")

# Create fitted lines
x_line = np.linspace(X.min(), X.max(), 200).reshape(-1, 1)
y_py = py_bias + py_weight * x_line
y_cpp = cpp_bias + cpp_weight * x_line

# Plot
fig, ax = plt.subplots(figsize=(6.4, 4.8), dpi=300)

# Data points
ax.scatter(X, y, label="Data", s=50, alpha=0.5, edgecolor="k")

# Regression lines
ax.plot(x_line, y_py, label="Python (scikit-learn)", color="blue", linewidth=2)
ax.plot(x_line, y_cpp, label="C++ (LinReg, this repo)", color="red", linestyle="--", linewidth=2)

# Labels and styling
ax.set_title("Result validation using scikit-learn", fontsize=14, weight="bold")
ax.set_xlabel("Feature X", fontsize=14)
ax.set_ylabel("Target Y", fontsize=14)
ax.tick_params(axis='both', which='major', direction='in', labelsize=14)
ax.tick_params(axis='both', which='minor', direction='in', labelsize=14)
ax.minorticks_on()
ax.legend(fontsize=12, loc="best")
ax.grid(visible=True, alpha=0.5, linestyle=':')
ax.set_xlim(X.min() - 0.5, X.max() + 0.5)
plt.tight_layout()
plt.savefig('comparison.png', dpi=300)
#plt.show()

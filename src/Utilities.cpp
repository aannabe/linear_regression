#include "Utilities.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

void loadCSV(const std::string& filename, DenseMatrix&X, DenseMatrix& Y) {
    // Assumes the CSV file has the following structure:
    // 1st column: Y data
    // After 1st column: X features

    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    std::vector<std::vector<double>> x_data;
    std::vector<double> y_data;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<double> row;

        while (std::getline(ss, token, ',')) {
            row.push_back(std::stod(token));
        }

        if (row.size() < 2)
            throw std::runtime_error("Each row must have at least two columns.");

        y_data.push_back(row[0]);
        row.erase(row.begin());
        x_data.push_back(row);
    }

    int rows = y_data.size();
    int cols = x_data[0].size();

    X = DenseMatrix(rows, cols);
    Y = DenseMatrix(rows, 1);

    for (int i = 0; i < rows; ++i) {
        Y.set(i, 0, y_data[i]);
        for (int j = 0; j < cols; ++j) {
            X.set(i, j, x_data[i][j]);
        }
    }
}

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

template <typename T>
class Matrix {
    vector<vector<T>> data;

public:
    Matrix(size_t rows, size_t cols) : data(rows, vector<T>(cols, T())) {}

    Matrix(const vector<vector<T>>& d) : data(d) {}

    friend ostream& operator<<(ostream& os, const Matrix& m) {
        for (const auto& row : m.data) {
            for (const auto& el : row) {
                os << el << ' ';
            }
            os << endl;
        }
        return os;
    }

    Matrix operator+(const Matrix &m) {
        if (data.size() != m.data.size() || data[0].size() != m.data[0].size()) {
            throw invalid_argument("Matrices must have the same size");
        }

        int rows = data.size();
        int cols = data[0].size();

        Matrix new_m(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                new_m.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return new_m;
    }

    Matrix operator*(const Matrix &m) {
        if (data[0].size() != m.data.size()) {
            throw invalid_argument("Left matrix must have the same size of cols as right matrix of rows");
        }

        int rows = data.size();
        int cols = data[0].size();
        int cols_m = m.data[0].size();

        Matrix new_m(rows, cols_m);

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols_m; k++) {
                for (int j = 0; j < cols; j++) {
                    new_m.data[i][k] += data[i][j] * m.data[j][k];
                }
            }
        }
        return new_m;
    }

    Matrix operator*(const vector<T> &v) {
        return *this * Matrix(v);
    }
};

// Test functions
void testConstructorAndPrint() {
    Matrix<int> m(2, 3);
    ostringstream os;
    os << m;
    cout << "Test Constructor and Print: " << (os.str() == "0 0 0 \n0 0 0 \n" ? "PASS" : "FAIL") << endl;
}

void testAddition() {
    Matrix<int> m1({{1, 2}, {3, 4}});
    Matrix<int> m2({{5, 6}, {7, 8}});
    Matrix<int> m3 = m1 + m2;
    ostringstream os;
    os << m3;
    cout << "Test Addition: " << (os.str() == "6 8 \n10 12 \n" ? "PASS" : "FAIL") << endl;
}

void testMultiplication() {
    Matrix<int> m1({{1, 2}, {3, 4}});
    Matrix<int> m2({{5, 6}, {7, 8}});
    Matrix<int> m3 = m1 * m2;
    ostringstream os;
    os << m3;
    cout << "Test Multiplication: " << (os.str() == "19 22 \n43 50 \n" ? "PASS" : "FAIL") << endl;
}

int main() {
    testConstructorAndPrint();
    testAddition();
    testMultiplication();
}
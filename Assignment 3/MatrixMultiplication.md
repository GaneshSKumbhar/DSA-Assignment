# Matrix Multiplication (Row-Major vs Column-Major Order)

## Theory
Matrix multiplication is a fundamental operation in numerical computing.  
The performance of multiplication is not only dependent on the number of operations but also on **memory access patterns**.

- **Row-major order**: Memory is accessed row by row. This matches the storage of C++ (row-major layout). It results in better cache performance.
- **Column-major order**: Memory is accessed column by column. This can lead to **cache misses** because elements are not stored contiguously in memory.

This experiment compares the performance of **row-major** and **column-major** order access patterns for multiplying two matrices.

---

## Algorithm

### Row-Major Multiplication
1. Traverse each row of `A`.
2. For each row, compute the dot product with each column of `B`.
3. Store result in matrix `C`.

### Column-Major Multiplication
1. Traverse each column of `B`.
2. For each column, compute the dot product with each row of `A`.
3. Store result in matrix `C`.

---

## Code

```cpp
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

using Matrix = vector<vector<double>>;

// Allocate an n x n matrix initialized with zeros
Matrix allocateMatrix_cpp(int n) {
    return Matrix(n, vector<double>(n, 0.0));
}

// Initialize matrix with random integers in [0,9]
void initializeMatrix_cpp(Matrix& mat) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);

    int n = mat.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = dis(gen);
}

// Row-major order matrix multiplication
void multiplyRowMajor_cpp(const Matrix& A, const Matrix& B, Matrix& C) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// Column-major order matrix multiplication
void multiplyColMajor_cpp(const Matrix& A, const Matrix& B, Matrix& C) {
    int n = A.size();
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    Matrix A = allocateMatrix_cpp(n);
    Matrix B = allocateMatrix_cpp(n);
    Matrix C = allocateMatrix_cpp(n);

    initializeMatrix_cpp(A);
    initializeMatrix_cpp(B);

    // Row-major multiplication timing
    auto start = high_resolution_clock::now();
    multiplyRowMajor_cpp(A, B, C);
    auto end = high_resolution_clock::now();
    duration<double> rowTime = end - start;
    cout << "Row-major multiplication time: " << rowTime.count() << " seconds\n";

    // Column-major multiplication timing
    start = high_resolution_clock::now();
    multiplyColMajor_cpp(A, B, C);
    end = high_resolution_clock::now();
    duration<double> colTime = end - start;
    cout << "Column-major multiplication time: " << colTime.count() << " seconds\n";

    return 0;
}
```

## Sample Output

**Input:**  
```
Enter matrix size (n x n): 500
```

**Output:**  
```
Row-major multiplication time: 0.842391 seconds
Column-major multiplication time: 1.653728 seconds
```


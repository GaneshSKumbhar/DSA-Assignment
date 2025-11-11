#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

using Matrix_gsk = vector<vector<double>>;

// Allocate an n x n matrix initialized with zeros
Matrix_gsk allocateMatrix_gsk(int n_gsk) {
    return Matrix_gsk(n_gsk, vector<double>(n_gsk, 0.0));
}

// Initialize matrix with random integers in [0,9]
void initializeMatrix_gsk(Matrix_gsk& mat_gsk) {
    random_device rd_gsk;
    mt19937 gen_gsk(rd_gsk());
    uniform_int_distribution<> dis_gsk(0, 9);

    int n_gsk = mat_gsk.size();
    for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++)
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++)
            mat_gsk[i_gsk][j_gsk] = dis_gsk(gen_gsk);
}

// Row-major order matrix multiplication
void multiplyRowMajor_gsk(const Matrix_gsk& A_gsk, const Matrix_gsk& B_gsk, Matrix_gsk& C_gsk) {
    int n_gsk = A_gsk.size();
    for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) {
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++) {
            double sum_gsk = 0.0;
            for (int k_gsk = 0; k_gsk < n_gsk; k_gsk++) {
                sum_gsk += A_gsk[i_gsk][k_gsk] * B_gsk[k_gsk][j_gsk];
            }
            C_gsk[i_gsk][j_gsk] = sum_gsk;
        }
    }
}

// Column-major order matrix multiplication
void multiplyColMajor_gsk(const Matrix_gsk& A_gsk, const Matrix_gsk& B_gsk, Matrix_gsk& C_gsk) {
    int n_gsk = A_gsk.size();
    for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++) {
        for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) {
            double sum_gsk = 0.0;
            for (int k_gsk = 0; k_gsk < n_gsk; k_gsk++) {
                sum_gsk += A_gsk[i_gsk][k_gsk] * B_gsk[k_gsk][j_gsk];
            }
            C_gsk[i_gsk][j_gsk] = sum_gsk;
        }
    }
}

int main() {
    int n_gsk;
    cout << "Enter matrix size (n x n): ";
    cin >> n_gsk;

    Matrix_gsk A_gsk = allocateMatrix_gsk(n_gsk);
    Matrix_gsk B_gsk = allocateMatrix_gsk(n_gsk);
    Matrix_gsk C_gsk = allocateMatrix_gsk(n_gsk);

    initializeMatrix_gsk(A_gsk);
    initializeMatrix_gsk(B_gsk);

    // Row-major multiplication timing
    auto start_gsk = high_resolution_clock::now();
    multiplyRowMajor_gsk(A_gsk, B_gsk, C_gsk);
    auto end_gsk = high_resolution_clock::now();
    duration<double> rowTime_gsk = end_gsk - start_gsk;
    cout << "Row-major multiplication time: " << rowTime_gsk.count() << " seconds\n";

    // Column-major multiplication timing
    start_gsk = high_resolution_clock::now();
    multiplyColMajor_gsk(A_gsk, B_gsk, C_gsk);
    end_gsk = high_resolution_clock::now();
    duration<double> colTime_gsk = end_gsk - start_gsk;
    cout << "Column-major multiplication time: " << colTime_gsk.count() << " seconds\n";

    return 0;
}

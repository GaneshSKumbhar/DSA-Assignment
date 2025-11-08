#include <iostream>
#include <iomanip>
using namespace std;

struct Sparse_gsk {
    int row_gsk, col_gsk;
    float val_gsk;
};

void fastTranspose_gsk(Sparse_gsk* sparse_gsk, Sparse_gsk* transpose_gsk) {
    int m_gsk = sparse_gsk[0].row_gsk;
    int n_gsk = sparse_gsk[0].col_gsk;
    int nz_gsk = sparse_gsk[0].val_gsk;

    transpose_gsk[0].row_gsk = n_gsk;
    transpose_gsk[0].col_gsk = m_gsk;
    transpose_gsk[0].val_gsk = nz_gsk;

    if (nz_gsk > 0) {
        int* rowTerms_gsk = new int[n_gsk]();
        int* startingPos_gsk = new int[n_gsk];

        // Count number of elements in each column
        for (int i_gsk = 1; i_gsk <= nz_gsk; i_gsk++)
            rowTerms_gsk[sparse_gsk[i_gsk].col_gsk]++;

        // Starting position of each row in transpose
        startingPos_gsk[0] = 1;
        for (int i_gsk = 1; i_gsk < n_gsk; i_gsk++)
            startingPos_gsk[i_gsk] = startingPos_gsk[i_gsk - 1] + rowTerms_gsk[i_gsk - 1];

        // Place elements in transpose
        for (int i_gsk = 1; i_gsk <= nz_gsk; i_gsk++) {
            int colIndex_gsk = sparse_gsk[i_gsk].col_gsk;
            int pos_gsk = startingPos_gsk[colIndex_gsk];
            transpose_gsk[pos_gsk].row_gsk = sparse_gsk[i_gsk].col_gsk;
            transpose_gsk[pos_gsk].col_gsk = sparse_gsk[i_gsk].row_gsk;
            transpose_gsk[pos_gsk].val_gsk = sparse_gsk[i_gsk].val_gsk;
            startingPos_gsk[colIndex_gsk]++;
        }

        delete[] rowTerms_gsk;
        delete[] startingPos_gsk;
    }
}

void displaySparse_gsk(Sparse_gsk* sparse_gsk) {
    int n_gsk = sparse_gsk[0].val_gsk;
    cout << "Row\tCol\tValue\n";
    for (int i_gsk = 0; i_gsk <= n_gsk; i_gsk++)
        cout << sparse_gsk[i_gsk].row_gsk << "\t" << sparse_gsk[i_gsk].col_gsk << "\t" << fixed << setprecision(2) << sparse_gsk[i_gsk].val_gsk << "\n";
}

int main() {
    int m_gsk, n_gsk;
    cout << "Enter number of rows and columns: ";
    cin >> m_gsk >> n_gsk;

    float** matrix_gsk = new float*[m_gsk];
    for (int i_gsk = 0; i_gsk < m_gsk; i_gsk++)
        matrix_gsk[i_gsk] = new float[n_gsk];

    cout << "Enter matrix elements:\n";
    for (int i_gsk = 0; i_gsk < m_gsk; i_gsk++)
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++)
            cin >> matrix_gsk[i_gsk][j_gsk];

    int count_gsk = 0;
    for (int i_gsk = 0; i_gsk < m_gsk; i_gsk++)
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++)
            if (matrix_gsk[i_gsk][j_gsk] != 0.0f)
                count_gsk++;

    Sparse_gsk* sparse_gsk = new Sparse_gsk[count_gsk + 1];
    Sparse_gsk* transpose_gsk = new Sparse_gsk[count_gsk + 1];

    sparse_gsk[0].row_gsk = m_gsk;
    sparse_gsk[0].col_gsk = n_gsk;
    sparse_gsk[0].val_gsk = count_gsk;

    int k_gsk = 1;
    for (int i_gsk = 0; i_gsk < m_gsk; i_gsk++)
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++)
            if (matrix_gsk[i_gsk][j_gsk] != 0.0f) {
                sparse_gsk[k_gsk].row_gsk = i_gsk;
                sparse_gsk[k_gsk].col_gsk = j_gsk;
                sparse_gsk[k_gsk].val_gsk = matrix_gsk[i_gsk][j_gsk];
                k_gsk++;
            }

    cout << "\nOriginal Sparse Matrix (Triplet form):\n";
    displaySparse_gsk(sparse_gsk);

    fastTranspose_gsk(sparse_gsk, transpose_gsk);

    cout << "\nFast Transpose Sparse Matrix (Triplet form):\n";
    displaySparse_gsk(transpose_gsk);

    for (int i_gsk = 0; i_gsk < m_gsk; i_gsk++)
        delete[] matrix_gsk[i_gsk];
    delete[] matrix_gsk;
    delete[] sparse_gsk;
    delete[] transpose_gsk;

    return 0;
}

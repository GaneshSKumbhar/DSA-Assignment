#include <iostream>
#include <vector>
using namespace std;

// Odd-order (Siamese method)
void generateOddMagicSquare_gsk(int n_gsk, vector<vector<int>>& square_gsk) {
    int num_gsk, row_gsk = 0, col_gsk = n_gsk / 2, next_row_gsk, next_col_gsk;
    for (num_gsk = 1; num_gsk <= n_gsk * n_gsk; num_gsk++) {
        square_gsk[row_gsk][col_gsk] = num_gsk;
        next_row_gsk = row_gsk - 1;
        next_col_gsk = col_gsk + 1;

        if (next_row_gsk < 0) next_row_gsk = n_gsk - 1;
        if (next_col_gsk == n_gsk) next_col_gsk = 0;

        if (square_gsk[next_row_gsk][next_col_gsk] != 0) {
            next_row_gsk = (row_gsk + 1) % n_gsk;
            next_col_gsk = col_gsk;
        }
        row_gsk = next_row_gsk;
        col_gsk = next_col_gsk;
    }
}

// Doubly-even order (n % 4 == 0)
void generateDoublyEvenMagicSquare_gsk(int n_gsk, vector<vector<int>>& square_gsk) {
    int num_gsk = 1;
    int total_gsk = n_gsk * n_gsk;

    for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) {
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++) {
            if ((i_gsk % 4 == j_gsk % 4) || ((i_gsk % 4 + j_gsk % 4) == 3))
                square_gsk[i_gsk][j_gsk] = total_gsk - num_gsk + 1;
            else
                square_gsk[i_gsk][j_gsk] = num_gsk;
            num_gsk++;
        }
    }
}

// Verifies all rows, columns, and diagonals
bool verifyMagicSquare_gsk(int n_gsk, vector<vector<int>>& square_gsk, int magicSum_gsk) {
    int sum_gsk;

    // Check rows
    for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) {
        sum_gsk = 0;
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++) sum_gsk += square_gsk[i_gsk][j_gsk];
        if (sum_gsk != magicSum_gsk) return false;
    }
    // Check columns
    for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++) {
        sum_gsk = 0;
        for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) sum_gsk += square_gsk[i_gsk][j_gsk];
        if (sum_gsk != magicSum_gsk) return false;
    }
    // Main diagonal
    sum_gsk = 0;
    for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) sum_gsk += square_gsk[i_gsk][i_gsk];
    if (sum_gsk != magicSum_gsk) return false;

    // Secondary diagonal
    sum_gsk = 0;
    for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) sum_gsk += square_gsk[i_gsk][n_gsk - i_gsk - 1];
    if (sum_gsk != magicSum_gsk) return false;

    return true;
}

int main() {
    int n_gsk;
    cout << "Enter value of n: ";
    cin >> n_gsk;

    if (n_gsk < 3) {
        cout << "Error: n must be >= 3." << endl;
        return 1;
    }

    // Create n x n vector initialized with 0
    vector<vector<int>> square_gsk(n_gsk, vector<int>(n_gsk, 0));

    // Construct magic square
    if (n_gsk % 2 == 1)
        generateOddMagicSquare_gsk(n_gsk, square_gsk);
    else if (n_gsk % 4 == 0)
        generateDoublyEvenMagicSquare_gsk(n_gsk, square_gsk);
    else {
        cout << "Singly even (n % 4 == 2) magic square not implemented in this simple version." << endl;
        return 1;
    }

    // Print magic square
    cout << "\nMagic Square of order " << n_gsk << ":\n";
    for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) {
        for (int j_gsk = 0; j_gsk < n_gsk; j_gsk++)
            cout << square_gsk[i_gsk][j_gsk] << "\t";
        cout << endl;
    }

    int magicSum_gsk = n_gsk * (n_gsk * n_gsk + 1) / 2;
    cout << "\nMagic Sum: " << magicSum_gsk << endl;

    // Verify
    if (verifyMagicSquare_gsk(n_gsk, square_gsk, magicSum_gsk))
        cout << "Verification: This IS a valid magic square!" << endl;
    else
        cout << "Verification: This is NOT a valid magic square." << endl;

    return 0;
}

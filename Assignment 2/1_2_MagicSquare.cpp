#include <iostream>
#include <vector>
using namespace std;

// Odd-order (Siamese method)
void generateOddMagicSquare(int n, vector<vector<int>>& square) {
    int num, row = 0, col = n / 2, next_row, next_col;
    for (num = 1; num <= n * n; num++) {
        square[row][col] = num;
        next_row = row - 1;
        next_col = col + 1;

        if (next_row < 0) next_row = n - 1;
        if (next_col == n) next_col = 0;

        if (square[next_row][next_col] != 0) {
            next_row = (row + 1) % n;
            next_col = col;
        }
        row = next_row;
        col = next_col;
    }
}

// Doubly-even order (n % 4 == 0)
void generateDoublyEvenMagicSquare(int n, vector<vector<int>>& square) {
    int num = 1;
    int total = n * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 4 == j % 4) || ((i % 4 + j % 4) == 3))
                square[i][j] = total - num + 1;
            else
                square[i][j] = num;
            num++;
        }
    }
}

// Verifies all rows, columns, and diagonals
bool verifyMagicSquare(int n, vector<vector<int>>& square, int magicSum) {
    int sum;

    // Check rows
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) sum += square[i][j];
        if (sum != magicSum) return false;
    }
    // Check columns
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 0; i < n; i++) sum += square[i][j];
        if (sum != magicSum) return false;
    }
    // Main diagonal
    sum = 0;
    for (int i = 0; i < n; i++) sum += square[i][i];
    if (sum != magicSum) return false;

    // Secondary diagonal
    sum = 0;
    for (int i = 0; i < n; i++) sum += square[i][n - i - 1];
    if (sum != magicSum) return false;

    return true;
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    if (n < 3) {
        cout << "Error: n must be >= 3." << endl;
        return 1;
    }

    // Create n x n vector initialized with 0
    vector<vector<int>> square(n, vector<int>(n, 0));

    // Construct magic square
    if (n % 2 == 1)
        generateOddMagicSquare(n, square);
    else if (n % 4 == 0)
        generateDoublyEvenMagicSquare(n, square);
    else {
        cout << "Singly even (n % 4 == 2) magic square not implemented in this simple version." << endl;
        return 1;
    }

    // Print magic square
    cout << "\nMagic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << square[i][j] << "\t";
        cout << endl;
    }

    int magicSum = n * (n * n + 1) / 2;
    cout << "\nMagic Sum: " << magicSum << endl;

    // Verify
    if (verifyMagicSquare(n, square, magicSum))
        cout << "Verification: This IS a valid magic square!" << endl;
    else
        cout << "Verification: This is NOT a valid magic square." << endl;

    return 0;
}

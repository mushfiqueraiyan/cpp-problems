#include <iostream>
#include <vector>
using namespace std;


// Add two matrices
vector<vector<int>> add(const vector<vector<int>>& A,
                         const vector<vector<int>>& B) {

    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}


// Subtract two matrices
vector<vector<int>> sub(const vector<vector<int>>& A,
                         const vector<vector<int>>& B) {

    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}


// Normal multiplication for 1x1 matrix
vector<vector<int>> strassen(const vector<vector<int>>& A,
                              const vector<vector<int>>& B) {

    int n = A.size();

    // Base case
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }


    int half = n / 2;

    // Create submatrices
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));

    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));


    // Divide matrices into 4 parts
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];

            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];


            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];

            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }


    // Strassen's 7 multiplications

    // P1 = A11 * (B12 - B22)
    vector<vector<int>> P1 =
        strassen(A11, sub(B12, B22));

    // P2 = (A11 + A12) * B22
    vector<vector<int>> P2 =
        strassen(add(A11, A12), B22);

    // P3 = (A21 + A22) * B11
    vector<vector<int>> P3 =
        strassen(add(A21, A22), B11);

    // P4 = A22 * (B21 - B11)
    vector<vector<int>> P4 =
        strassen(A22, sub(B21, B11));

    // P5 = (A11 + A22) * (B11 + B22)
    vector<vector<int>> P5 =
        strassen(add(A11, A22), add(B11, B22));

    // P6 = (A12 - A22) * (B21 + B22)
    vector<vector<int>> P6 =
        strassen(sub(A12, A22), add(B21, B22));

    // P7 = (A11 - A21) * (B11 + B12)
    vector<vector<int>> P7 =
        strassen(sub(A11, A21), add(B11, B12));


    // Calculate C11, C12, C21, C22

    // C11 = P5 + P4 - P2 + P6
    vector<vector<int>> C11 =
        add(sub(add(P5, P4), P2), P6);

    // C12 = P1 + P2
    vector<vector<int>> C12 =
        add(P1, P2);

    // C21 = P3 + P4
    vector<vector<int>> C21 =
        add(P3, P4);

    // C22 = P5 + P1 - P3 - P7
    vector<vector<int>> C22 =
        sub(sub(add(P5, P1), P3), P7);


    // Combine the four parts
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            C[i][j] = C11[i][j];

            C[i][j + half] = C12[i][j];

            C[i + half][j] = C21[i][j];

            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}


int main() {

    int n;

    // Ask user for matrix size
    cout << "Enter the size of the matrix: ";
    cin >> n;


    // Create matrices of user's size
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));


    // Input first matrix
    cout << "\nEnter First " << n << "x" << n << " Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }


    // Input second matrix
    cout << "\nEnter Second " << n << "x" << n << " Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }


    // Find next power of 2
    int newSize = 1;

    while (newSize < n) {
        newSize *= 2;
    }


    // Create padded matrices
    vector<vector<int>> A_padded(newSize,
                                 vector<int>(newSize, 0));

    vector<vector<int>> B_padded(newSize,
                                 vector<int>(newSize, 0));


    // Copy original matrices into padded matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            A_padded[i][j] = A[i][j];

            B_padded[i][j] = B[i][j];
        }
    }


    // Perform Strassen multiplication
    vector<vector<int>> C_padded =
        strassen(A_padded, B_padded);


    // Print only original n x n result
    cout << "\nResult of Strassen Matrix Multiplication:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << C_padded[i][j] << "\t";
        }

        cout << endl;
    }


    return 0;
}
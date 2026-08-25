#include <iostream>
using namespace std;


const int N = 2;


void add(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}


void mul(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void strassen(int A[4][4], int B[4][4], int C[4][4]) {
    int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    int C11[N][N], C12[N][N], C21[N][N], C22[N][N];

    int P1[N][N], P2[N][N], P3[N][N], P4[N][N], P5[N][N], P6[N][N], P7[N][N];
    int temp1[N][N], temp2[N][N];

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + N];
            A21[i][j] = A[i + N][j];
            A22[i][j] = A[i + N][j + N];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + N];
            B21[i][j] = B[i + N][j];
            B22[i][j] = B[i + N][j + N];
        }
    }
    
    // P1 = A11 * (B12 - B22)
    sub(B12, B22, temp1);
    mul(A11, temp1, P1);

    // P2 = (A11 + A12) * B22
    add(A11, A12, temp1);
    mul(temp1, B22, P2);

    // P3 = (A21 + A22) * B11
    add(A21, A22, temp1);
    mul(temp1, B11, P3);

    // P4 = A22 * (B21 - B11)
    sub(B21, B11, temp1);
    mul(A22, temp1, P4);

    // P5 = (A11 + A22) * (B11 + B22)
    add(A11, A22, temp1);
    add(B11, B22, temp2);
    mul(temp1, temp2, P5);

    // P6 = (A12 - A22) * (B21 + B22)
    sub(A12, A22, temp1);
    add(B21, B22, temp2);
    mul(temp1, temp2, P6);

    // P7 = (A11 - A21) * (B11 + B12)
    sub(A11, A21, temp1);
    add(B11, B12, temp2);
    mul(temp1, temp2, P7);


    // C11 = P5 + P4 - P2 + P6
    add(P5, P4, temp1);
    sub(temp1, P2, temp2);
    add(temp2, P6, C11);

    // C12 = P1 + P2
    add(P1, P2, C12);

    // C21 = P3 + P4
    add(P3, P4, C21);

    // C22 = P5 + P1 - P3 - P7
    add(P5, P1, temp1);
    sub(temp1, P3, temp2);
    sub(temp2, P7, C22);


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j]         = C11[i][j];
            C[i][j + N]     = C12[i][j];
            C[i + N][j]     = C21[i][j];
            C[i + N][j + N] = C22[i][j];
        }
    }
}

int main() {
    int A[4][4], B[4][4], C[4][4];

    cout << "Enter First 4x4 Matrix: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> A[i][j];
        }
    }

    cout << endl;

    cout << "Enter Second 4x4 Matrix: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> B[i][j];
        }
    }

    strassen(A, B, C);

    cout << "\nResult of Strassen Matrix Multiplication: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
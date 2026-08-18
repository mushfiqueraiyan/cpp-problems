#include <iostream>
using namespace std;

int N = 2;

void add(int A[N][N], int B[N][N], int C[N][N]){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

}

void sub(int A[N][N], int B[N][N], int C[N][N]){
for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void stressen(int A[N][N], int B[N][N], int C[N][N]){
    int A11[2][2], int A12[2][2], int A21[2][2], int A22[2][2];
    int B11[2][2], int B12[2][2], int B21[2][2], int B22[2][2];

    int P1[2][2],P2[2][2],P3[2][2],P4[2][2],P5[2][2],P6[2][2],P7[2][2];

    int temp1[2][2], temp2[2][2];

    for(int i = 0;i< N; i++){
        for(int j = 0; j < N; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+2];
            A21[i][j] = A[i+2][j];
            A22[i][j] = A[i+2][j+2];


            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+2];
            B21[i][j] = B[i+2][j];
            B22[i][j] = B[i+2][j+2];

        }
    }

}

int main(){

   int A[4][4], B[4][4], C[4][4];

   cout << "Enter First 4x4 Matrix: " << endl;

   for(int i = 0; i < 4; i++){
    fot(int j = 0; j < 4; j++){
        cin >> A[i][j];
    }
   }

   for(int i = 0; i < 4; i++){
    fot(int j = 0; j < 4; j++){
        cin >> B[i][j];
    }
   }

   stressen(A,B,C);

   cout << "\nResult of Stressen Matrix Multiplication: " << endl;

   for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        cout << C[i][j]
    }
   }

    return 0;
}
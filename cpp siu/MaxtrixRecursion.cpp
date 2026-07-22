#include <iostream>
using namespace std;
int A[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int B[3][3] = {
    {10, 11, 12},
    {13, 14, 15},
    {16, 17, 18}
};

int C[3][3] = {0};

void multiply(int i,int j, int k){
    if(k == 3){
        return;
    }

    C[i][j] += A[i][k] * B[k][j];

    multiply(i,j,k+1);
}

void calculateColumns(int i,int j){

    if(j == 3 ){
        return;
    }

    multiply(i,j,0);
    calculateColumns(i,j+1);

}

void calculateRows(int i){
    if(i == 3){
        return;
    }

    calculateColumns(i,0);
    calculateRows(i+1);
}


int main(){

    calculateRows(0);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j <3; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
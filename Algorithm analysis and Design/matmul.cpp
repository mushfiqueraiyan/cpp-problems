#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matmul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();

   
    vector<vector<int>> res(n, vector<int>(n, 0));

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return res;
}

vector<vector<int>> matSUb(const vector<vector<int>> &A, vector<vector<int>> &B){
    int n = A.size();

    vector<vector<int>> res(r, vector<int>(c,0));

    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n ; j++){
            res[i][j] = A[i][j] - B[i][j];
        }
    }

    return res;
}


int main(){

    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6}
    };

     vector<vector<int>> B = {
        {7,8,9},
        {10,11,12}
    };

    vector<vector<int>> mul= matmul(A,B);
    vector<vector<int>> sub= matSUb(A,B);


    cout << "Multiplication: " << endl;

    for(int i = 0; i < mul.size(); i++){
        for(int j = 0; j < mul[0].size(); j++){
            cout << mul[i][j] << " ";
        }

        cout << endl;
    }

    cout << "Substraction: " << endl; 

    for(int i = 0; i < sub.size(); i++){
        for(int j = 0; j < sub[0].size(); j++){
            cout << sub[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
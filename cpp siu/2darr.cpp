#include <iostream>
using namespace std;


int main (){

    int r ,c;

    cout << "Enter the number of elements of row: ";
    cin >> r;

    cout << "Enter the number of elements of col: ";
    cin >> c;

    int arr[r][c] = {0};

    cout << "Input: " << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0 ; j < c ; j ++){
            cin >> arr[i][j];
        }
    }
   cout << endl;
    cout << "Output: " << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0 ; j < c ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
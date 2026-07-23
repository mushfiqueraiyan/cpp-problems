#include <iostream>
using namespace std;
int main(){

    int marks[10] = {5,10,15,20};
    int n = 4;
    int position = 3;
    int value = 12;

    for(int i = n; i >=position; i--){
        marks[i] = marks[i-1];
    }

    marks[position-1] = value;
    n++;

    for(int i = 0; i < n; i++){
        cout << marks[i] << " ";
    }

    return 0;
}
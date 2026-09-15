#include <iostream>
using namespace std;


void insertion(int arr[], int n){
    if(n<=0){
        return;
    }

    insertion(arr, n-1);

    int key = arr[n-1];
    int j = n - 2;

    while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = key;
}

int main(){

    int arr[] = {7,2,3,9,12,8,11};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion(arr,n);

    for(int x : arr){
        cout << x << " ";
    }
    

    return 0;
}
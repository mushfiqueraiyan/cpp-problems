#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++){
        R[i] = arr[mid  + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while ( i < n1 && j < n2){
        if(L[i] < R[i]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left >= right){
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid,right);
}


int main (){

    int arr[] = {20,10,40,60,68,32,44};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    for(int x: arr){
        cout << x << " ";
    }
    return 0;
}
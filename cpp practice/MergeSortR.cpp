#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right){

    


}

void megeSort(int arr[], int left, int right){

    if(left>=right){
        return;
    }

    int mid = left + (right - left) / 2;

    megeSort(arr,left,mid,right);
    merge(arr,mid+1, right);
    merge(arr,left, mid,right);

}

int main(){
    int arr[] = {20,10,1,50,65,32,22,11};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    for(int i =0; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
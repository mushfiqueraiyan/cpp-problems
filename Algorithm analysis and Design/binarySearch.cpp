#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target){
    if(left > right){
        return -1;
    }

    int mid = left + (right - left) / 2; // 3 

    if(arr[mid] == target){
        return mid;
    }

    if(target < arr[mid]){
        return binarySearch(arr,left, mid-1,target);
    }
    else{
       return binarySearch(arr,mid+1,right,target);
    }

}
int main(){

    int arr[] = {10,20,40,60,65,70,75};
    int n = 7;

    int target = 20;

    int result = binarySearch(arr,0,n-1,target);

    cout << "Target Found in: " << result << endl;

    return 0;
}
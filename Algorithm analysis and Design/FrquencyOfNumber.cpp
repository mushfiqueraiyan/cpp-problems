#include <iostream>
#include <vector>
using namespace std;

int frCount(vector<int> arr, int target){
    int count = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target){
            count++;
        }
    }

    return count;
}

int main(){

    vector<int> arr = {1,2,2,2,3,4,5};

    int target = 2;

    int result =  frCount(arr,target);

    cout << result;
    
    return 0;
}
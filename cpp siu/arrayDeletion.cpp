#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr[n];

    int pos;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    cin >> pos;
    
    if(pos < 1 || pos > n){
        cout << "Invalid Position";
    }
    else {
        for(int i = pos - 1; i< n-1; i++){
            arr[i] = arr[i+1];
        }
        
        n--;
    }
    
    for(int i = 0; i< n; i++){
        cout << arr[i] << " ";
    }
}
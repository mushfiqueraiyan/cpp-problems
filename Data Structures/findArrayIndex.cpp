#include <iostream>
using namespace std;

int main(){
    int arr[100], key, n, pos = -1;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements number : ";

    for(int i = 0;i< n; i++){
        cin >> arr[i];
    }


    cout << "Enter the key of element: ";
    cin >> key;

    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        cout << "Element not found ";
    }
    else{
        cout << "Element in position " << pos + 1;
    }
    
    if(pos == 0){
      cout << "Element is first position";
    }
    else if(pos == n - 1){
        cout << "Element found in last position";
    }
    else {
        cout << "Element is in middle position";
    }




    return 0;
}
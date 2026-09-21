#include <iostream>
using namespace std;

int main() {

    int arr[100], n, key, i;
    int comparisons = 0; int found = 0;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " Elements: ";
    for(int i = 0; i < n ;i++){
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    cout << endl;

    for(int i = 0; i <n ;i++){
        comparisons++;

        if(arr[i]==key){
            cout << "Elements found in position " << i+1 << endl;
            found = 1;
            break;
        }
    }

    if(found == 0){
        cout << "Elements not found";
    }

    cout << "Number of comparison " << comparisons << endl;;


    


return 0;

}
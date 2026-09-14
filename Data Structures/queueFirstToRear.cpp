#include <iostream>
#include <vector>
using namespace std;

#define MAX 5

int main(){

    int n, first;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> queue(MAX);

    for(int i = 0 ; i < n; i++){
        cin >> queue[i];
    }

    first = queue[0];

    for(int i = 0; i < n-1; i++){
        queue[i] = queue[i+1];
    }

    queue[n-1] = first;

    for(int i = 0; i < n; i++){
        cout<< queue[i] << endl;
    }

    return 0;
}
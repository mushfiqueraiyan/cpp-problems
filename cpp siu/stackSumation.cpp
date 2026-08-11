#include <iostream>
using namespace std;

#define MAX 5


int main(){
    
    int stack[MAX];
    int top = -1;
    int n, i, sum = 0;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if(n > MAX){
        cout << "The stack is overflowed";
    }
    
    for (i = 0; i < n;i++){
        cout << "Enter element: " << i+1 << ": ";
        cin >> stack[++top];
    }
    
    for(int i = 0; i <= top; i++){
        sum = sum + stack[i];
    }
    
    cout << "Sum of elements: " << sum;
    
    
    
    return 0;
}
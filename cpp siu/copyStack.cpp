#include <iostream>
using namespace std;

#define MAX 5

int main(){

    int top1 = -1;
    int top2 = -1;
    int stack1[MAX], stack2[MAX];

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements for stack 1: " << endl;

    for(int i = 0; i < n ; i++){
        top1++;
        cin >> stack1[top1];
    }

    

    for (int i = 0; i < n ; i++){
        top2++;
        stack2[top2] = stack1[i];
    }

cout << "Stack 1 elements: " << endl;
    for(int i = top1; i >=0 ; i--){
        cout << stack1[i] <<endl;
    }


    cout << "Stack 2 elements: " << endl;

    for(int i = top2; i >=0 ; i--){
        cout << stack2[i] <<endl;
    }




    return 0;
}
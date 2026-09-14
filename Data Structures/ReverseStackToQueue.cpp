#include <iostream>
using namespace std;

#define MAX 100

int main(){

    int stack[MAX];
    int queue[MAX];
    int front = 0, rear;
    int top = -1;
    int n;

    cout << "Enter the number of the elements: ";
    cin >> n;
    cout << endl;

    cout << "Enter queue elements: " << endl;
    for(int i = 0; i< n; i++){
        cin >> queue[i];
    }

    rear = n -1;

    cout << "Original Queue elements: " << endl;
    for(int i = front; i <= rear; i++){
        cout << queue[i] << " ";
    }
    cout << endl;

    while(front <= rear){
        top++;
        stack[top] = queue[front];
        front++;
    }

    front = 0;
    rear = -1;

    while(top >= 0){
        rear++;
        queue[rear] = stack[top];
        top--;
    }


    cout << "Reversed Queue Elements: " << endl;

    for(int i = front; i <= rear; i++){
        cout << queue[i] << " ";
    }

    return 0;
}
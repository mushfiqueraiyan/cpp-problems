#include <iostream>
using namespace std;

#define MAX 100

int main (){

    int queue[MAX];
    int evenQueue[MAX];
    int oddQueue[MAX];

    int n;
    int front = 0, rear;
    int evenRear = -1;
    int oddRear = -1;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << endl;

    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++){
        cin >> queue[i];
    }

    rear = n - 1;

    for(int i = front; i<=rear; i++){
        if(queue[i] % 2 == 0){
            evenRear++;
            evenQueue[evenRear] = queue[i];

        }
        else{
            oddRear++;
            oddQueue[oddRear] = queue[i];

        }
    }


    cout << "Even queue: " << endl;

    for(int i = 0; i<= evenRear; i++){
        cout << evenQueue[i] << " ";
    }

    cout << endl; 

    cout << "Odd Queue: " << endl;

    for(int i = 0; i <= oddRear; i++){
        cout << oddQueue[i] << " ";
    }

    return 0;
}
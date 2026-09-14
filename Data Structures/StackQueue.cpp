#include <iostream>
using namespace std;

#define MAX 5

int front = -1;
int rear = -1;
int queue[MAX];

void enqueue(int value){
    if (rear == MAX -1){
        cout << "Queue cannot insert value: " << value << endl;
        
        return;
    }

    if(front == -1){
        front = 0;
    }

    rear++;
    queue[rear] = value;

    cout << "Inserted Element : " << value << endl;
}

void display(){
    int i ;

    if(front == -1 || front > rear){
        cout << "Queue Is Empty";
    }

    for(i = front; i <= rear; i++ ){
        cout << queue[i] << " ";
        }

        cout << endl;
}


int main(){

    int i , value;

    

    for(i = 0; i< MAX; i++){
        
        cout << "Enter Element: " << i+1 << " ";
        cin >> value;
        enqueue(value);
    }

    display();

    cout << "Enter another value: ";

    cin >> value;
    enqueue(value);

    return 0;
}
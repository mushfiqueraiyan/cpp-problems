#include <iostream>
#include <vector>
using namespace std;

#define MAX 5

int main(){
    vector<int> queue(MAX);

    int first = -1,rear = -1;


    if(rear == MAX - 1){
        cout << "The queue is overflow";
    }
    else {
        if(first == -1){
            first = 0;
        }

        rear++;
        queue[rear] = 10;
    }

    if(rear == MAX - 1){
        cout << "The queue is overflow";
    }
    else {
        

        rear++;
        queue[rear] = 20;
    }

     if(rear == MAX - 1){
        cout << "The queue is overflow";
    }
    else {
        

        rear++;
        queue[rear] = 30;
    }

    if(first == -1 || first > rear){
        cout << "The queue is underflow";
    }else{
        cout << "Detected front: " << queue[first] << endl;
        first++;
    }
  if(rear == MAX - 1){
        cout << "The queue is overflow";
    }
    else {
        

        rear++;
        queue[rear] = 40;
    }

    if(first == -1 || first > rear){
        cout << "The queue is underflow";
    }else{
        cout << "Detected front: " << queue[first] << endl;
        first++;
    }

      if(rear == MAX - 1){
        cout << "The queue is overflow";
    }
    else {
        

        rear++;
        queue[rear] = 50;
    }

    for(int i = first; i <= rear; i++){
        cout << queue[i] << endl;
    }


    return 0;
}
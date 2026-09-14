#include <iostream>
using namespace std;

#define MAX 5

int main(){

    int queue[MAX];
    int i,item,found = 0;
    int front = 0, rear,n

    cout << "How much elements do you want to insert: "
    cin >> n;

    rear = n - 1;

    cout << "Enter ELements: " << n << ": ";
    for(i = 0; i <= rear; i++){
        cin >> queue[i];
    }

    for(i = front; i< MAX; i++){
        cout << queue[i];
    }

    cout << "Enter elements to search: ";
    cin >> item;

    for(i = front; i<=rear; i++){
        if(queue[i] == item){
            cout << "Item " << item << " Found in position " << i+1;
            found = 1;
            break;
        }

    }

      if(found == 0){
            cout << "Item couldn't found in the list";
        }

    return 0;
}
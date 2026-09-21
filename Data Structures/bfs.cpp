#include <iostream>
using namespace std;

#define MAX 10

int graph[MAX][MAX];
int visited[MAX] = {0};

int queueArray[MAX];
int front = 0, rear = 0;

void enqueue(int val){
    queueArray[rear] = val;
    rear++;
}

int dequeue(){

    int value = queueArray[front];
    front++;

    return value;

}

int isEmpty(){
    return front == rear;
}

void bfs(int start, int vertices){
    enqueue(start);
    visited[start] = 1;

     cout << "BFS traversal: ";

    while(!isEmpty()){
        int current = dequeue();
        cout << current << " ";

        for(int i = 0; i< vertices; i++){
            if(graph[current][i] == 1 & visited[i] == 0){
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

     cout << endl;
}

int main(){

    int vertices, edges;
    int u,v;
    int start;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            graph[i][j] = 0;
        }
    }

    cout << "Enter the edges u v: ";
    for(int i =0; i < edges; i++){
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }


    cout << "Enter the starting vertex: ";
    cin >> start;

    cout << endl;

    bfs(start, vertices);

    return 0;
}
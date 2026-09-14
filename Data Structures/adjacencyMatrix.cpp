#include <iostream>
using namespace std;

int main(){

    int graph[10][10];
    int vertices , edges;
    int u, v;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << endl;

    cout << "Enter the number of edges: ";
    cin >> edges;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            graph[i][j] = 0;
        }
    }

    cout << endl;

    cout <<"Enter the edges u & v: ";

    for(int i = 0; i < edges; i++){
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << endl;

    cout << "Adjacency Matrix: " << endl;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }



    return 0;
}
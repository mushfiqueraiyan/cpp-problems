#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

int main(){

    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX] = {0};
    int vertices, edges;
    int u, v, w;
    int source;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << endl;

    cout << "Enter the number of edges: ";
    cin >> edges;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            if(i == j){
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = INF;
            }
        }
    }

    cout << endl;

    cout << "Enter the edges u v w: " << endl;

    for(int i = 0; i < edges; i++){
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    cout << endl;

    cout << "Enter the source vertex: ";
    cin >> source;

    for(int i = 0; i < vertices; i++){
        distance[i] = INF;
    }

    distance[source] = 0;

    for(int count = 0; count < vertices - 1; count++){

        int min = INF;
        int minIndex = -1;

        for(int i = 0; i < vertices; i++){
            if(visited[i] == 0 && distance[i] < min){
                min = distance[i];
                minIndex = i;
            }
        }

        if(minIndex == -1){
            break;
        }

        visited[minIndex] = 1;

        for(int i = 0; i < vertices; i++){
            if(visited[i] == 0 && graph[minIndex][i] != INF && distance[minIndex] + graph[minIndex][i] < distance[i]){
                distance[i] = distance[minIndex] + graph[minIndex][i];
            }
        }
    }

    cout << endl;

    cout << "Shortest distance from source " << source << ":" << endl;

    for(int i = 0; i < vertices; i++){
        if(distance[i] == INF){
            cout << "Vertex " << i << " -> unreachable" << endl;
        }
        else{
            cout << "Vertex " << i << " -> " << distance[i] << endl;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 1000000

void djikstra(int graph[MAX][MAX], int n, int source, int dist[], int visited[]){
    int i, j, min, u, v;
    for(i = 0; i < n; i++){
        min = INF;
        u = -1; 
        for(j = 0; j < n; j++){
            if(visited[j]==0 && dist[j]<min){
                min = dist[j];
                u = j;
            }
        } 
        if(u == -1) break; //No more reachable vertices
        visited[u] = 1;
        for(v = 0; v < n; v++){
            if(visited[v]==0 && graph[u][v]){
                if (dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Shortest distance from source %d to all vertices:\n", source);
    for(i = 0; i < n; i++){
        if(dist[i] == INF)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main(){
    int graph[MAX][MAX], n, i, j, source;
    int dist[MAX], visited[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++){
        visited[i] = 0; 
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    for(i = 0; i < n; i++){
        dist[i] = i!= source ? INF : 0;
    }
    djikstra(graph, n, source, dist, visited);
    return 0;
}

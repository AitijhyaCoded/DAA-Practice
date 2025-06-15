#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 1000000

void bellmanFord(int graph[MAX][MAX], int n, int source, int dist[]){
    int i, u, v;
    for (i = 1; i < n; i++) {
        for(u = 0; u < n; u++){
            for(v = 0; v < n; v++){
                    if (graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                        dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    for(u = 0; u < n; u++){
        for(v = 0; v < n; v++){
            if(graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]){
                printf("Graph contains negative weight cycle\n");
                return;
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
    int dist[MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    for(i = 0; i < n; i++){
        dist[i] = i!= source ? INF : 0;
    }
    bellmanFord(graph, n, source, dist);
    return 0;
}

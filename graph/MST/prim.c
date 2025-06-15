#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 1000000

int prim(int graph[MAX][MAX], int v, int visited[], int root){
    int total = 0;
    visited[root] = 1; 
    printf("\nMinimum Spanning Tree:\n");
    for(int edges = 0; edges < v - 1; edges++){
        int min = INF;
        int u = -1, w = -1;
        // u: The visited vertex of the selected edge.
        // w: The unvisited vertex that we’re going to connect to the MST using the minimum weight edge.
        for(int i = 0; i < v; i++){
            if(visited[i]){
                for(int j = 0; j < v; j++){
                    if(!visited[j] && graph[i][j] && graph[i][j] < min){
                        min = graph[i][j];
                        u = i;
                        w = j;
                    }
                }
            }
        }
        if(u != -1 && w != -1){
            printf("%d - %d : %d\n", u, w, graph[u][w]);
            total += graph[u][w];
            visited[w] = 1;
        }
    }
    return total;
}

int main(){
    int graph[MAX][MAX];
    int v, root;
    int visited[MAX] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter root: ");
    scanf("%d", &root);
    int cost = prim(graph, v, visited, root);
    printf("Total minimum cost: %d\n", cost);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int path[MAX]; 
int hamiltonian(int graph[MAX][MAX], int path[], int pos, int n, int visited[MAX]){
    if(pos == n){
        if(graph[path[pos-1]][path[0]] == 1){
            for(int i = 0; i < n; i++){
                printf("%d ", path[i]);
            }
            printf("%d\n", path[0]); // to complete the cycle
            return 1;
        }
        return 0; 
    }
    int found = 0;
    for(int v = 0; v < n; v++){
        if(graph[path[pos-1]][v] == 1 && visited[v] == 0){
            visited[v] = 1;
            path[pos] = v; 
            if (hamiltonian(graph, path, pos+1, n, visited)) {
                found = 1;
            }
            visited[v] = 0; //backtrack
            path[pos] = -1; 
        }
    }
    return found; 
}
int main(){
    int graph[MAX][MAX];
    int visited[MAX]; 
    int n; 
    printf("Enter n: ");
    scanf("%d", &n);  
    printf("Enter graph: ");
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        visited[i] = 0; 
    }
    path[0] = 0; 
    visited[0] = 1; 
    printf("Hamiltonian cycles from 0: \n");
    if(!hamiltonian(graph, path, 1, n, visited)) printf("No cycles found");
    return 0;
}
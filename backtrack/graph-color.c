#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int x[MAX];

void nextvalue(int graph[MAX][MAX], int k, int m, int n){
    while(1){
        x[k] = (x[k]+1) % (m+1);  //next highest color
        if(x[k] == 0){
            return; //all colors used
        }   
        int j;
        for(j = 0; j < n; j++){
            if(graph[k][j] != 0 && x[k]==x[j])
                break; //if adjacent vertex has same color
        } 
        if(j == n)
            return; //valid color    
    }
}

void mcoloring(int graph[MAX][MAX], int k, int m, int n){
    while(1){
        nextvalue(graph, k, m, n);
        if(x[k] == 0){
            return;
        }
        if(k == n-1){
            for(int i = 0; i < n; i++){
                printf("%d ", x[i]);
            }
            printf("\n");
        }
        else{
            mcoloring(graph, k+1, m, n);
        }
    }
}

int main(){
    int graph[MAX][MAX]; 
    int n, i, j, m;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter the graph:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    for(i = 0; i < n; i++){
        x[i] = 0; 
    }
    printf("Assigned colorings: \n");
    mcoloring(graph, 0, m, n);
    return 0;
}

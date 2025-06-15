#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void dfs(int arr[MAX][MAX], int root, int n, int visited[MAX]){
    visited[root]=1;
    printf("%d ",root);
    for(int i = 0; i < n; i++){
        if(arr[root][i]==1 && !visited[i]){
            dfs(arr, i, n, visited);
        }
    }
}
int main(){
    int arr[MAX][MAX]; 
    int n, root; 
    printf("Enter n: ");
    scanf("%d", &n);  
    int visited[MAX]={0};
    printf("Enter array: ");
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter root:");
    scanf("%d", &root);
    dfs(arr, root, n, visited);
    return 0;
}
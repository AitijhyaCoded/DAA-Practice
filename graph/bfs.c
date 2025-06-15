#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int i, n, choice, front = -1, rear = -1;
int isEmpty(){
    if(front==-1||front>rear){
        return 1;
    }
    return 0;
}
void enq(int val){
    if(rear==MAX-1){
        printf("Overflow");
    }
    else{
        if(front==-1 && rear==-1){
            front=0; rear=0;
        }
        else{
            rear++;
        }
        queue[rear]=val;
    }
}
int deq(){
    if(isEmpty()){
        printf("Underflow");
    }
    else{
        int val=queue[front];
        front++;
        return val;
    }
}
void bfs(int arr[MAX][MAX], int root, int n){
    int visited[MAX]={0};
    visited[root]=1;
    enq(root);
    while(!isEmpty()){
        int node=deq();
        printf("%d ",node);
        for(int i = 0; i < n; i++){
            if(arr[node][i]==1 && !visited[i]){
                enq(i);
                visited[i]=1;
            }
        }
    }
}
int main(){
    int arr[MAX][MAX]; 
    int n, root; 
    printf("Enter n: ");
    scanf("%d", &n);  
    printf("Enter array: ");
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter root:");
    scanf("%d", &root);
    bfs(arr, root, n);
    return 0;
}
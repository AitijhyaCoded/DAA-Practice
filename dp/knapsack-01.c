#include<stdio.h>
#define MAX 100
void knapsack(int wt[], int b[], int W, int n){
    int sol[MAX][MAX];
    int i, w;
    for(w=0; w<=W; w++){
        sol[0][w]=0;
    }
    for(i=0; i<=n; i++){
        sol[i][0]=0;
    }
    for(i=0; i<=n; i++) {
        for(w=0; w<=W; w++) {
            if(wt[i]<=w){
                if(b[i]+sol[i-1][w-wt[i]]>=sol[i-1][w]){
                    sol[i][w]=b[i]+sol[i-1][w-wt[i]];
                }
                else
                    sol[i][w]=sol[i-1][w];
            }
            else
                sol[i][w]=sol[i-1][w];
        }
    }
    // for(i=0; i<=n; i++){
    //     for(w=0; w<=W; w++){
    //         printf("%d ",sol[i][w]);
    //     }
    //     printf("\n");
    // }
    printf("Maximum benefit: %d\n", sol[n][W]); 
}
int main()	{
    int n, W;
    printf("Enter n:");
    scanf("%d",&n);
    // int val[MAX];
    int wt[MAX], b[MAX];
    // printf("Enter values:");
    // for(int i=0;i<n;i++){
    //     scanf("%d",&val[i]);
    // }
    printf("Enter weights:");
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    printf("Enter benefits:");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    printf("Enter W:");
    scanf("%d",&W);
    knapsack(wt, b, W, n);
    return 0;
}
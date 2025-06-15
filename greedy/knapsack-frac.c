#include<stdio.h>
#define MAX 100
// int max(int a, int b){
//     return (a > b)? a : b;
// }
int knapsack(int val[], int wt[], int W, int n){
    int ratio[MAX];
    int t1, t2, t3;
    for(int i=0;i<n;i++){
        ratio[i]=val[i]/wt[i];
    }
    //sort ratio in descending order
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(ratio[j+1]>ratio[j]){
                t1=ratio[j+1];
                ratio[j+1]=ratio[j];
                ratio[j]=t1;
                t2=val[j+1];
                val[j+1]=val[j];
                val[j]=t2;
                t3=wt[j+1];
                wt[j+1]=wt[j];
                wt[j]=t3;
            }
        }
    }
    int w=0;
    float total=0;
    for(int i=0;i<n;i++){
        if(w<W){
            if(w+wt[i]<=W){
                total+=val[i];
                w+=wt[i];
            }
            else{
                total+=(val[i]/(float)wt[i])*(W - w);
                w+=wt[i];
            }
        }
    }
    return total;
}
int main()	{
    int n, W;
    printf("Enter n:");
    scanf("%d",&n);
    int val[MAX], wt[MAX];
    printf("Enter values:");
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    printf("Enter weights:");
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    printf("Enter W:");
    scanf("%d",&W);
    printf("\nTotal value: %d",knapsack(val, wt, W, n));
    return 0;
}
    
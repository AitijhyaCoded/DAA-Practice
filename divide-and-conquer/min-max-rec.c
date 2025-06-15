#include<stdio.h>
int min(int a, int b){
    return (a < b)? a : b;
}
int max(int a, int b){
    return (a > b)? a : b;
}
int findMin(int arr[], int lb, int ub){
    if(lb!=ub){
        int mid=(lb+ub)/2;
        int leftMin=findMin(arr,lb,mid);
        int rightMin=findMin(arr,mid+1,ub);
        return min(leftMin, rightMin);
    }
    return arr[lb];
}
int findMax(int arr[], int lb, int ub){
    if(lb!=ub){
        int mid=(lb+ub)/2;
        int leftMax=findMax(arr,lb,mid);
        int rightMax=findMax(arr,mid+1,ub);
        return max(leftMax, rightMax);
    }
    return arr[ub];
}
int main(){
    int arr[100]; 
    int n; 
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int min=findMin(arr,0,n-1);
    int max=findMax(arr,0,n-1);
    printf("Minimum is %d and Maximum is %d",min,max);
    return 0;
}
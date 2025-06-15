#include<stdio.h>
//quickSort
int partition(int arr[], int beg, int end){
    int pivot = arr[end];
    int i = beg-1;
    for(int j = beg; j < end; j++){
        if(arr[j] < pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;
    return (i+1);
}

void quick_sort(int arr[], int beg, int end){
    if(beg < end){
        int piv = partition(arr, beg, end);
        quick_sort(arr, beg, piv - 1);
        quick_sort(arr, piv + 1, end);
    }
}

//mergeSort
void merge(int arr[], int beg, int mid, int end){
    int i= beg, j= mid+1, k=0;
    int temp[100];
    while((i<=mid)&&(j<=end)){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=end){
            temp[k]=arr[j];
            k++; j++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=arr[i];
            k++; i++;
        }
    }
    for(int l=0;l<k;l++){
        arr[beg+l]=temp[l];
    }
}

void merge_sort(int arr[], int beg, int end){
    if(beg<end){
        int mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

//chooseSort
int main(){
    int arr[100]; 
    int n, choice;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Choose sorting technique:\n1. Quick Sort\n2. Merge Sort\nEnter choice:");
    scanf("%d", &choice);
    switch (choice){
        case 1: quick_sort(arr, 0, n - 1); break;
        case 2: merge_sort(arr, 0, n - 1); break;
    } 
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

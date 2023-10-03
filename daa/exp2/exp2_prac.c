#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
void printArr(int *arr, int i, int n){
    for(; i<n; i++)
        printf("%d ", arr[i]);
}
void printArrWithMarker(int *arr, int n, int marked){
    for(int i=0; i<n; i++){
        if(marked == i)
            printf("[%d] ", arr[i]);
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}


// Best explanation for partition - https://leetcode.com/discuss/general-discussion/1083445/how-quick-sort-works-and-the-problems-that-can-be-solved-using-partition-logic

int partition(int *arr, int l, int r){
    int pivot = arr[r];
    int i=l-1;
    for(int j=l; j<r; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}
void quickSort(int *arr, int l, int r){
    if(l >= r)
        return;
    // printf("Quick sort %d - %d\n", l, r);
    int partitionIdx = partition(arr, l, r);

    // printf("(%d - %d) After partition at %d[%d], arr: ",l,r, partitionIdx, arr[partitionIdx]);
    // printArr(arr, l, r+1);
    // printf("   =>  qs(%d, %d) & qs(%d, %d)",l,partitionIdx-1,partitionIdx+1,r);
    // printf("\n");

    quickSort(arr, l, partitionIdx-1);
    quickSort(arr, partitionIdx+1, r);
}


int cmp(const void *a, const void *b){
    // return *((int *)b) - *((int *)a);
    return *((int *)a) - *((int *)b);
}
int main(){
    printf("\n");
    int a1[] = { 25, 5, 58, 2, 10, 9, 1, 7, 9 };
    int n = sizeof(a1) / sizeof(int);
    printf("Original: ");
    printArr(a1, 0, n);
    quickSort(a1, 0, n-1);
    // qsort(a1, n, sizeof(int), cmp);      // Inbuilt
    printf("\nSorted: ");
    printArr(a1, 0, n);

    printf("\n\nBye !\n");
    return 0;
}
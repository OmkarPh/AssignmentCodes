#include<stdio.h>


void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
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

// Time complexity: n^2
void selectionSort(int *arr, int n){
    printf("\n");
    for(int i=0; i<n; i++){
        int minIdx = i;    
        for(int j=i; j<n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(&arr[i], &arr[minIdx]);
        printf("Selected for %d | ", i);
        printArrWithMarker(arr, n, i);
    }
    printf("\n");
}

int main(){
    printf("\n");

    int n;

    n = 13;
    int arr[] = {2, 52, 1, 69, 9, 92, 85, 293, 23, 23, 55, 23, 13};

    // printf("Enter length of array: ");
    // scanf("%d", &n);
    
    // printf("Enter array: ");
    // for(int i=0; i<n; i++)
    //     scanf("%d", &arr[i]);

    printf("Original Arr: ");
    printArr(arr, n);

    selectionSort(arr, n);

    printf("Sorted arr: ");
    printArr(arr, n);


    printf("\n");
    return 0;
}
#include<stdio.h>
#include"lib_binarySearch.h"
#include"lib_selectionSort.h"

void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
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

    printf("Selection sort --------------------\n");
    printf("Original Arr: ");
    printArr(arr, n);

    selectionSort(arr, n);

    printf("Sorted arr: ");
    printArr(arr, n);

    printf("\n\n");

    printf("Binary search --------------------\n");
    int searchElements[] = {9, 5, 23, 55};
    for(int i=0; i<4; i++){
        int selement = searchElements[i];
        int foundIdx = binarySearch(arr, n, selement);
        if(foundIdx == -1)
            printf("%d not found !\n", selement);
        else
            printf("%d found at idx: %d\n", selement, foundIdx);
    }

    printf("\n");
    return 0;
}
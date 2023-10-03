#include<stdio.h>
// #include<chrono.h>

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
void insertionSort(int *arr, int n){
    printf("\n");

    for (int i = 1; i < n; i++) {  
        int temp = arr[i];  
        int j = i - 1;  
  
        while(j>=0 && temp <= arr[j])  /* Move the elements greater than temp to one position ahead from their current position*/  
        {    
            arr[j+1] = arr[j];     
            j = j-1;    
        }    
        arr[j+1] = temp;    

        printf("For %d | ", i);
        printArr(arr, n);
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

    
    // high_resolution_clock::now() under namespace std::chrono.

    insertionSort(arr, n);

    printf("Sorted arr: ");
    printArr(arr, n);


    printf("\n");
    return 0;
}
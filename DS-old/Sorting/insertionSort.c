#include<stdio.h>
#include<stdlib.h>
// By default = Adaptive and Stable
// Best useful for Linkedlist
void insertionSort(int arr[], int size){
    int x, j;
    for(int i=1; i<size; i++){
        x = arr[i];
        j = i-1;
        while(arr[j] > x && j > -1){
                arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}

int* getArray(int n){
    printf("Enter the elements in array: ");
    int* arr = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("Success :)\n");
    return arr;
}
int main(){
    printf("Enter no of elements you want in the array: ");
    int n;
    scanf("%d",&n);
    int* array = getArray(n);
    insertionSort(array, n);
    printf("Sorted Array: \t");
    for(int i=0; i<n; i++)
        printf("%d  ",array[i]);
    printf("\n");
    return 0;
}
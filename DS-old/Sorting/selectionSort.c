#include<stdio.h>
#include<stdlib.h>
// Not adaptive (Same time for pre-sorted array)  and     not Stable
void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void selectionSort(int arr[], int size){
    int minIndex, i,j;
    for(i=0; i<size; i++){
        minIndex = i;
        for(j=i+1; j<size; j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        swap(&arr[i],&arr[minIndex]);
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
    selectionSort(array, n);
    printf("Sorted Array: \t");
    for(int i=0; i<n; i++)
        printf("%d  ",array[i]);
    printf("\n");
    return 0;
}
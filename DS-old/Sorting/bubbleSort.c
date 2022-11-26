#include<stdio.h>
#include<stdlib.h>
// It is adaptive 
// Most suitable for array
void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
void bubbleSort(int arr[], int size){
    int flag;
    int passes=0;
    for(int i=0; i<size-1; i++){
        flag = 0;
        for(int j=0; j<size-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        passes++;
        // printf("\nPass: %d\n",passes);
        if(flag==0)
            return;
        
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
    bubbleSort(array, n);
    printf("Sorted Array: \t");
    for(int i=0; i<n; i++)
        printf("%d  ",array[i]);
    printf("\n");
    return 0;
}
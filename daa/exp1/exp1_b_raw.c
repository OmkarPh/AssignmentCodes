#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

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
void selectionSort(int *arr, int start, int size){
    // printf("\n");
    for(int i=start; i<size; i++){
        int minIdx = i;    
        for(int j=i; j<size; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(&arr[i], &arr[minIdx]);
        // printf("Selected for %d | ", i);
        // printArrWithMarker(arr, n, i);
    }
    // printf("\n");
}


// Time complexity: n^2
void insertionSort(int *arr, int start, int size){
    // printf("\n");

    for (int i = start+1; i < size; i++) {  
        int temp = arr[i];  

        int j = i - 1;  
  
        while(j>=0 && temp <= arr[j]) {    
            arr[j+1] = arr[j];     
            j = j-1;    
        }    
        arr[j+1] = temp;    

        // printf("For %d | ", i);
        // printArr(arr, n);
    }  

    // printf("\n");
}


int main(){
    printf("\n");

    char *randNumsFileName = "rand_numbers.txt";
    char *selectionSortedFileName = "selection_sorted.txt";
    char *insertionSortedFileName = "insertion_sorted.txt";

    FILE *randNumFilePtr = fopen(randNumsFileName, "w");
    FILE *sortedNumFilePtr;

    int n = 100000;
    int a[n];
    int num, startTime, endTime, rangeTill;

    printf("Generating rand arr ....... ");
    for (int i = 0; i < n; i++){
        num = rand();
        fprintf(randNumFilePtr, "%d\n", num);
        // printf("%d\n", num);
    }
    printf("Done !\n");
    fclose(randNumFilePtr);




    // Insertion
    randNumFilePtr = fopen(randNumsFileName, "r");
    printf("Reading random numbers text file into array ...... ");
    for(int i=0; i<n; i++){
        fscanf(randNumFilePtr, "%d", &a[i]);
    }
    fclose(randNumFilePtr);
    // printArr(a, n);
    printf("Done !\n");


    rangeTill = 100;
    printf("Insertion sort ---------------\n");
    // printf("Range\tTime\n");
    sortedNumFilePtr = fopen(insertionSortedFileName, "w");
    printf("Storing Insertion sorted times in (%s) .....", insertionSortedFileName);
    fclose(sortedNumFilePtr);
    while(rangeTill <= n){
        startTime = clock();
        insertionSort(a, 0, rangeTill);
        endTime = clock();
        fprintf(sortedNumFilePtr, "%d\t%d\n", rangeTill, endTime-startTime);
        // printf("%d\t%d\n", rangeTill, endTime-startTime);
        rangeTill += 100;
    }
    printf("Insertion sort done! \n");

    // printf("Insertion Sort started at");
    // startTime = clock();
    // printf(" [start time: %d]\n", startTime);
    // insertionSort(a, 0, n);
    // endTime = clock();
    // printf("Insertion sort completed at [end time: %d]\n", endTime);
    // ----
    // printf("Insertion sort time required: %d\n", endTime-startTime);
    // sortedNumFilePtr = fopen(insertionSortedFileName, "w");
    // printf("Storing Insertion sorted array in (%s) .....", insertionSortedFileName);
    // for (int i = 0; i < n; i++){
    //     fprintf(sortedNumFilePtr, "%d\n", a[i]);
    // }
    // printf("Done !\n\n");
    // fclose(sortedNumFilePtr);








    // Selection
    randNumFilePtr = fopen(randNumsFileName, "r");
    printf("Reading random numbers text file into array ...... ");
    for(int i=0; i<n; i++){
        fscanf(randNumFilePtr, "%d", &a[i]);
    }
    fclose(randNumFilePtr);
    // printArr(a, n);
    printf("Done !\n");
    

    rangeTill = 100;
    printf("Selection sort ---------------\n");
    printf("Range\tTime\n");
    while(rangeTill <= n){
        startTime = clock();
        selectionSort(a, 0, rangeTill);
        endTime = clock();
        printf("%d\t%d\n", rangeTill, endTime-startTime);
        rangeTill += 100;
    }
    printf("Selection sort done! \n");

    // printf("Selection Sort started at");
    // printf(" [start time: %d]\n", startTime);
    // selectionSort(a, 0, n);
    // printf("Selection sort completed at [end time: %d]\n", endTime);
    // printf("Selection sort time required: %d\n", endTime-startTime);

    sortedNumFilePtr = fopen(selectionSortedFileName, "w");
    printf("Storing selection sorted array in (%s) .....", selectionSortedFileName);
    for (int i = 0; i < n; i++){
        fprintf(sortedNumFilePtr, "%d\n", a[i]);
    }
    printf("Done !\n\n");
    fclose(sortedNumFilePtr);






    

    printf("Bye !\n\n");
    return 0;

    // int c, time;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < n * i; j++)
    //     {
    //         fscanf(randNumFilePtr, "%d", &a[j]);
    //     }
    //     time = clock();
    //     insertionSort(a, n * i);
    //     time = clock() - time;
    //     printf("\n%d", time);
    //     // fprintf(ptr,"%d %d \n",n*i,time);
    // }
    // fclose(randNumFilePtr);



    // printf("\n\nselectionsort\n");
    // // selsort(a,n);
    // for (int i = 1; i <= 1000; i++)
    // {
    //     for (int j = 0; j < n * i; j++)
    //     {
    //         fscanf(randNumFilePtr, "%d", &a[j]);
    //     }
    //     time = clock();
    //     selsort(a, n * i);
    //     time = clock() - time;
    //     printf("\n%d", time);
    //     // fprintf(ptr,"%d %d \n",n*i,time);
    // }

    // fclose(randNumFilePtr);
    /* printf("\nOutput:");
    for(int i=0;i<n;i++){
    printf("\n%d",a[i]);
    }*/
}
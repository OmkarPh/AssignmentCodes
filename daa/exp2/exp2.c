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


void merge(int *arr, int i, int mid, int j){
    if(i==j)
        return;

    int p1Size = mid-i+1;
    int p2Size = j-(mid+1)+1;

    int sub1[p1Size], sub2[p2Size];
    for(int tmp=0; tmp<p1Size; tmp++)
        sub1[tmp] = arr[i+tmp];
    for(int tmp=0; tmp<p2Size; tmp++)
        sub2[tmp] = arr[mid+1+tmp];

    int p1 = 0, p2 = 0;
    int originalTraveller = i;
    while(p1<p1Size && p2<p2Size){
        if(sub1[p1] <= sub2[p2]){
            arr[originalTraveller++] = sub1[p1++];
        } else {
            arr[originalTraveller++] = sub2[p2++];
        }
    }

    while(p1<p1Size)
        arr[originalTraveller++] = sub1[p1++];
    while(p2<p2Size)
        arr[originalTraveller++] = sub2[p2++];

    // printf("Merge sub1 (%d - %d) & sub2 (%d - %d) - (%d - %d)   ->   ", i, mid, mid+1, j, i, j);
    // printSubArr(arr, i, j);
}
void mergeSort(int *arr, int i, int j){
    // printf("Sort %d - %d\n", i, j);
    if(i>=j)
        return;
    int mid = i + (j-i)/2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);
    merge(arr, i, mid, j);
    // printf("\n");
}



int partition(int *arr, int l, int r){
    int pivot = r;
    while(l<r){
        if(pivot == l){
            if(arr[pivot] <= arr[r])
                r--;
            else {
                swap(&arr[pivot], &arr[r]);
                pivot = r;
                l++;
            }
        } else {
            if(arr[pivot] >= arr[l])
                l++;
            else {
                swap(&arr[l], &arr[pivot]);
                pivot = l;
                r--;
            }
        }
    }
    return pivot;
}
void quickSort(int *arr, int l, int r){
    if(l >= r)
        return;
    // printf("Quick sort %d - %d\n", l, r);
    int partitionIdx = partition(arr, l, r);

    // printf("After partition at %d[%d], arr: ", partitionIdx, arr[partitionIdx]);
    // printArr(arr, r+1);
    // printf("\n");

    quickSort(arr, l, partitionIdx-1);
    quickSort(arr, partitionIdx+1, r);
}



int main(){
    printf("\n");

    char *randNumsFileName = "rand_numbers.txt";
    char *sortedTimesFileName = "sorted_times.txt";
    char *mergeSortedNums = "merge_sorted_nums.txt";
    char *quickSortedNums = "quick_sorted_nums.txt";

    FILE *randNumFilePtr = fopen(randNumsFileName, "w");
    FILE *mergeSortedNumsFilePtr = fopen(mergeSortedNums, "w");
    FILE *quickSortedNumsFilePtr = fopen(quickSortedNums, "w");
    FILE *sortedTimesFilePtr;

    int n = 100000;
    int a1[n], a2[n];
    int num, startTime, endTime, rangeTill;
    double t1, t2;

    printf("Generating rand arr ....... ");
    for (int i = 0; i < n; i++){
        num = rand();
        fprintf(randNumFilePtr, "%d\n", num);
        // printf("%d\n", num);
    }
    printf("Done !\n");
    fclose(randNumFilePtr);




    rangeTill = 100;
    printf("Sorting --------------- \n");
    // printf("Range\tTime\n");
    sortedTimesFilePtr = fopen(sortedTimesFileName, "w");
    printf("Storing sorted times in (%s) ..... ", sortedTimesFileName);
    fprintf(sortedTimesFilePtr, "Block size \t   Merge sort time \t   Quick sort time \n");

    while(rangeTill <= n){
        randNumFilePtr = fopen(randNumsFileName, "r");
        for(int i=0; i<rangeTill; i++){
            fscanf(randNumFilePtr, "%d", &a1[i]);
            a2[i] = a1[i];
        }
        fclose(randNumFilePtr);


        startTime = clock();
        mergeSort(a1, 0, rangeTill-1);
        endTime = clock();
        t1 = 1.0 * (endTime - startTime);

        startTime = clock();
        quickSort(a2, 0, rangeTill-1);
        endTime = clock();
        t2 = 1.0 * (endTime - startTime);

        fprintf(sortedTimesFilePtr, "%7d \t %14lf \t %13lf \n", rangeTill, t1 / CLOCKS_PER_SEC, t2 / CLOCKS_PER_SEC);
        rangeTill += 100;
    }
    fclose(sortedTimesFilePtr);
    printf("Sorting done! \n\n");


    printf("Storing sorted nums ..... ");
    for (int j = 0; j < n; j++){
        fprintf(mergeSortedNumsFilePtr, "%d\n", a1[j]);
        fprintf(quickSortedNumsFilePtr, "%d\n", a2[j]);
    }
    fclose(mergeSortedNumsFilePtr);
    fclose(quickSortedNumsFilePtr);
    printf("done! \n\n");

    printf("Bye !\n\n");
    return 0;
}
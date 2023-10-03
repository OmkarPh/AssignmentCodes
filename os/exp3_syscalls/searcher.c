#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Implement the C program in which main program accepts an integer array.
// Main program uses the fork system call to create a new process called a child process.
// Parent process sorts an integer array and passes the sorted array to child process through
// the command line arguments of execve system call.
// The child process uses execve system call to load new program that uses this sorted array
// for performing the binary search to search the particular item in the array.



int binarySearch(int *arr, int n, int key){
    int l=0,r=n-1;
    int mid;
    while(l<=r){
        mid = l+(r-l)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] < key)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}

void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv) {
    printf("In searcher [%d]-------- \n", getpid());

    if(argc<=1) {
        printf("No args !! \n");
        exit(1);
    }

    int n = argc - 1;
    printf("Size of arr %d\n", n);
    int *arr = (int *)malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        arr[i] = atoi(argv[i+1]);
    }

    printf("Arr: ");
    printArr(arr, n);

    printf("\nBinary search --------------------\n");
    int searchElements[] = {3, 5, 7, 10};
    for(int i=0; i<4; i++){
        int selement = searchElements[i];
        int foundIdx = binarySearch(arr, n, selement);
        if(foundIdx == -1)
            printf("%d not found !\n", selement);
        else
            printf("%d found at idx: %d\n", selement, foundIdx);
    }

    printf("\n");
}
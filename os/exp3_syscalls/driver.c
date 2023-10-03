#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

char* intToString(int n){
    char *str = (char*)malloc(sizeof(char)*(int)log10(n));
    sprintf(str, "%d", n);
    return str;
}

void selectionSort(int *arr, int n){
    // printf("\n");
    for(int i=0; i<n; i++){
        int minIdx = i;    
        for(int j=i; j<n; j++){
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(&arr[i], &arr[minIdx]);
        // printf("Selected for %d | ", i);
        // printArrWithMarker(arr, n, i);
    }
    // printf("\n");
}

void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    printf("\n");
    printf("In parent (driver) [%d] -------- \n", getpid());

    int n;

    // n = 5;
    // int arr[] = {2, 9, 1, 5, 7};

    printf("Enter length of array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int)*n);
    printf("Enter array: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("\nIn parent, Original Array: ");
    printArr(arr, n);
    selectionSort(arr, n);
    printf("In parent, Sorted Array: ");
    printArr(arr, n);
    printf("\n");



    int inParent = fork();

    if(!inParent){
        printf("In child [%d] --------\n", getpid());

        int argsLength = n+1;
        char **args = (char**)malloc(sizeof(char*) * argsLength);
        args[0] = "./searcher";
        
        printf("Exec Args: ");
        printf("%s ", args[0]);
        for(int i=0; i<n; i++){
            args[i+1] = intToString(arr[i]);
            printf("%s ", args[i+1]);
        }
        printf("\n\n");

        execvp(args[0], args);
    }

    // printf("\n--- In parent, Bye !!!!!!\n");
    return 0;

    // Testcase
    // 9
    // 23 8 2 295 55 25 7 1 92

    // Main program uses the fork system call to create a new process called a child process.
    // Parent process sorts an integer array and passes the sorted array to child process through
    // the command line arguments of execve system call.

    // The child process uses execve system call to load new program that uses this sorted array
    // for performing the binary search to search the particular item in the array.
}

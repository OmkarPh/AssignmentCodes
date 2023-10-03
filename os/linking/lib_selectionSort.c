void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}


// void printArrWithMarker(int *arr, int n, int marked){
//     for(int i=0; i<n; i++){
//         if(marked == i)
//             printf("[%d] ", arr[i]);
//         else
//             printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// Time complexity: n^2
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

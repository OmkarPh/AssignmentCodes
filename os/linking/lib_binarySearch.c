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
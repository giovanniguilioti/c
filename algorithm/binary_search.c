int binary_search(int arr[], int l, int r, int key)
{
    if(l >= r)
        return -1;
    
    int mid = l + (r - l) /2;

    if(arr[mid] == key)
        return mid;
    if(arr[mid] < key)
        return binary_search(arr, mid + 1, r, key);
    if(arr[mid] > key)
        return binary_search(arr, l, mid -1, key);
}
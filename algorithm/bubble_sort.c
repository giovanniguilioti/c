int bubble_sort(int arr[], int size)
{
    for(int i = 0; i < size-1; ++i)
        for(int j = size; j > i; --j)
            if(arr[j] < arr[j-1])
                arr[j] ^= arr[j-1] ^= arr[j] ^= arr[j-1];
}

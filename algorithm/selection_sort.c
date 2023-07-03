int selection_sort(int arr[], int size)
{
    int i, j, min, aux;
    for(int i = 0; i < size - 1; ++i)
    {
        min = i;
        for(int j = i+1; j < size; ++j)
            if(arr[j] < arr[min])
                min = j;
    
        if(i != min)
            arr[i] ^= arr[min] ^= arr[i] ^= arr[min];
    }
}

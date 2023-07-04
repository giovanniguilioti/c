int minimum(int arr[], int n)
{
    int min = arr[1];

    for(int i = 1; i < n; ++i)
        if(min > arr[i])
            min = arr[i];

    return min;
}
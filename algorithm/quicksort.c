void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p -1;

    for(int j = p; j < r; ++j)
    {
        if(arr[j] <= x)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[r]);

    return i+1;
}

int quick_sort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }

}

int rand_partition(int arr[], int p, int r)
{
    int i = rand() % (r + 1 - p) + p;
    
    swap(&arr[r], &arr[i]);
    return partition(arr, p, r);
}

int rand_quick_sort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = rand_partition(arr, p, r);
        rand_quick_sort(arr, p, q-1);
        rand_quick_sort(arr, q+1, r);
    }
}

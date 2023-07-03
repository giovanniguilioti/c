int* counting_sort(int arr[], int n, int k)
{
    int* output = malloc(sizeof(int) * n);
    
    int count[n];
    for(int i = 0; i <= k; ++i)
        count[i] = 0;

    for(int i = 0; i < n+1; ++i)
        count[arr[i]]++;

    for(int i = 1; i <= k; ++i)
        count[i] += count[i-1];

    return output;
}
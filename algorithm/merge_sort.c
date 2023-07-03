void merge(int arr[], int p, int q, int r)
{
    int leftLen = q - p + 1;
    int rightLen = r - q;

    int leftArr[leftLen];
    int rightArr[rightLen];

    for(int i = 0; i < leftLen; ++i)
        leftArr[i] = arr[p+i];
    
    for(int i = 0; i < rightLen; ++i)
        rightArr[i] = arr[q+i+1];

    int i = 0;
    int j = 0;
    int k = p;

    while(i < leftLen && j < rightLen)
    {
        if(leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while(i < leftLen)
        arr[k++] = leftArr[i++];

    while(i < rightLen)
        arr[k++] = rightArr[j++];
}

void merge_sort(int arr[], int p, int r)
{
    if(p >= r)
        return;

    int q = p + (r - p) / 2;

    merge_sort(arr, p, q);
    merge_sort(arr, q+1, r);

    merge(arr, p, q, r);
}

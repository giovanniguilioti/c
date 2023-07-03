int insertion_sort(int arr[], int count)
{
    for(int i = 1; i < count; ++i)
    {
        int key = arr[i];

        int j = i-1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}
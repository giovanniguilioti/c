int linear_search(int arr[], int count, int key)
{
    for(int i = 0; i < count; ++i)
    {
        if(arr[i] == key)
            return i;
    }

    return 0;
}
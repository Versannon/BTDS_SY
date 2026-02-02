#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i -1;
        // Move elements of arr[0..i-1], that are greater than key,
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
    }    
}
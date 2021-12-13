#include <stdio.h>

// O(n^2)

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        i + 1 != size ? printf("%d=>", arr[i]) : printf("%d", arr[i]);
    }
}

int main()
{

    int arr[] = {5, 11, 12, 10, 23, 55, 43};
    int n = sizeof(arr) / sizeof(arr[0]); // sizeof byte olarak dondurur (1 byte 8 bit)
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
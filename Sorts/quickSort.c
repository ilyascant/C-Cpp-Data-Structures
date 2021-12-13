#include <stdio.h>

// arr[] = {5, 11, 12, 43, 10, 55, 23} -> {5, 11, 12, 23, 10, 55, 43}

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int arr[], int low, int high) // bolme
{
    int pivot = arr[high]; // pivot, son eleman = 23
    int i = low - 1;       // -1

    for (int j = low; j < high; j++) // j = 0, high = 6, i = -1
    {

        if (arr[j] < pivot)
        {
            i++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {5, 11, 12, 43, 23, 55, 10}; // 7 elemanli
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted Array is: \n");
    printArray(arr, n);
    return 0;
}
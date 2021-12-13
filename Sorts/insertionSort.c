#include <stdio.h>
#include <math.h>

// O(n^2)

void insertionSort(int arr[], int n)
{

    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
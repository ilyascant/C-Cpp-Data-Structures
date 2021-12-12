#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return -1;
};

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    printf("Bulmak istediginiz sayiyi giriniz\n");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    (result != -1) ? printf("Aradiginiz sayinin(%d) indexi -> %d\n", x, result) : printf("Aradigin sayi bu listede yok");
    return 0;
}
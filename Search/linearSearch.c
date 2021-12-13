#include <stdio.h>

int linearSearch(int arr[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    printf("Bulmak istediginiz sayiyi giriniz\n");
    scanf("%d", &x);
    int result = linearSearch(arr, n, x);
    (result != -1) ? printf("Aradiginiz sayinin(%d) indexi -> %d\n", x, result) : printf("Aradigin sayi bu listede yok");
    return 0;
}
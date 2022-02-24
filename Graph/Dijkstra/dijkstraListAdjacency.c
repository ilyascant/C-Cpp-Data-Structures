#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int i) {
    if (size == 1) {
        printf("This heap contains only one element");
    } else {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            heapify(arr, size, largest);
        }
    }
}

void insert(int arr[], int num, int* size) {
    if (*size == 0) {
        arr[*size] = num;
        (*size)++;
    } else {
        arr[*size] = num;
        (*size)++;
        for (int i = (*size) / 2 - 1; i >= 0; i = i / 2) {
            heapify(arr, *size, i);
            if (i == 0) break;
        }
    }
}

void deleteNode(int arr[], int num, int* size) {
    int i;
    for (i = 0; i < *size; i++) {
        if (num == arr[i])
            break;
    }

    swap(&arr[i], &arr[*size - 1]);
    *size -= 1;
    for (int i = (*size) / 2 - 1; i >= 0; i = i / 2) {
        heapify(arr, *size, i);
        if (i == 0) break;
    }
}

void printArray(int arr[], int* size) {
    for (int i = 0; i < *size; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void) {
    // TIME
    clock_t time = clock();

    int size = 0;
    int arr[256];
    insert(arr, 3, &size);
    insert(arr, 4, &size);
    insert(arr, 9, &size);
    insert(arr, 5, &size);
    insert(arr, 2, &size);
    insert(arr, 12, &size);
    insert(arr, 7, &size);
    insert(arr, 21, &size);

    printf("%-30s", "Max-Heap arr: ");
    printArray(arr, &size);

    deleteNode(arr, 4, &size);

    printf("%-30s", "After deleting an element: ");
    printArray(arr, &size);

    // TIME
    double timePassed = (double)(clock() - time) / CLOCKS_PER_SEC;
    printf("%f", timePassed);

    return 0;
}

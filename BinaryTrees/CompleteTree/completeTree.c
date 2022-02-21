#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define V 5

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* new_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert_level_order(int arr[], Node* root, int i, int n) {
    if (i < n) {
        Node* temp = new_node(arr[i]);
        root = temp;

        root->left = insert_level_order(arr, root->left, 2 * i + 1, n);
        root->right = insert_level_order(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    Node* root = NULL;
    int arr[V] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    root = insert_level_order(arr, root, 0, n);

    printArray(arr, n);
    return 0;
}

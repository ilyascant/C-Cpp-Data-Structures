#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) x > y ? x : y

typedef struct Node {
    int data;
    int height;
    struct Node *left, *right;

} Node;

Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int get_balance(Node* node) {
    if (node == NULL) return 0;
    return (height(node->left) - height(node->right));
}

Node* right_rotate(Node* node) {
    Node* tmp = node->left;
    Node* T2 = tmp->right;

    tmp->right = node;
    node->left = T2;

    tmp->height = MAX(height(tmp->left), height(tmp->right)) + 1;
    node->height = MAX(height(node->left), height(node->right)) + 1;

    return tmp;
}

Node* left_rotate(Node* node) {
    Node* tmp = node->right;
    Node* T2 = tmp->left;

    tmp->left = node;
    node->right = T2;

    tmp->height = MAX(height(tmp->left), height(tmp->right)) + 1;
    node->height = MAX(height(node->left), height(node->right)) + 1;

    return tmp;
}

Node* insert(Node* node, int data) {
    if (node == NULL) return create_node(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = MAX(height(node->left), height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && node->data < node->left->data) {
        return right_rotate(node);
    } else if (balance > 1 && node->data > node->left->data) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    } else if (balance < -1 && node->data > node->right->data) {
        return left_rotate(node);
    } else if (balance < -1 && node->data > node->right->data) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void inOrder(Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ->", node->data);
        inOrder(node->right);
    }
}

int main(void) {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printf(
        "inOrder traversal of the constructed AVL"
        " tree is \n");
    inOrder(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
    int height;
};

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;

    return temp;
}

struct Node *rightRotate(struct Node *node)
{

    struct Node *temp = node->left;
    struct Node *T2 = temp->right;

    temp->right = node;
    node->left = T2;

    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

struct Node *leftRotate(struct Node *node)
{
    struct Node *temp = node->right;
    struct Node *T2 = temp->left;

    temp->left = node;
    node->right = T2;

    node->height = max(height(node->left), height(node->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    return temp;
}

int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node *insert(struct Node *node, int data)
{

    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    else if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    else if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(struct Node *node)
{

    if (node != NULL)
    {

        inOrder(node->left);
        printf("%d-> ", node->data);
        inOrder(node->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("inOrder traversal of the constructed AVL"
           " tree is \n");
    inOrder(root);
    return 1;
};

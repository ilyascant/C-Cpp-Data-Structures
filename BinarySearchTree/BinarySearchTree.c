#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int data)
{

    if (node == NULL)
    {
        return newNode(data);
    };

    if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        node->left = insert(node->left, data);
    }
    return node;
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    if (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *node, int data)
{

    if (node == NULL)
        return node;

    if (data < node->data)
    {
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = deleteNode(node->right, data);
    }
    else
    {
        // 2 tarafi ya da tek tarafi bos ise
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        // Eger iki tarafi da dolu ise SAG NODE'un en SOL'undaki degeri alip yerine koyuyoruz
        // daha sonra o koydugumuz degeri deleteNode() ile kaldiriyoruz..
        struct Node *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
};

void inOrder(struct Node *node)
{ // LNR

    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d -> ", node->data);
        inOrder(node->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int i;
    int deger;

    do
    {
        printf("\nIkili Ekleme Agaci\n");
        printf("1- Ekle\n");
        printf("2- Goster \n");
        printf("3- Ara\n");
        printf("4- Sil\n");
        printf("5. Dugum Sayisi\n");
        printf("0. Cikis Yap (x)\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Eklemek istegin Degeri gir\n");
            scanf("%d", &deger);
            root = insert(root, deger);
            break;
        case 2:
            printf("INORDER ile gosteriliyor\n");
            inOrder(root);
            break;
        case 3:
            printf("Arama ozelligi implement edilmedi.\n");
            break;
        case 4:
            printf("Silinmesini istediginiz NODE'un degerini giriniz\n");
            scanf("%d", &deger);
            root = deleteNode(root, deger);
            break;
        case 5:
            printf("Dugum sayisi ozelligi implement edilmedi.\n");
            break;
        case 0:
            i = 0;
            break;
        default:
            printf("Yanlis ya da eksik tuslama.\n");
            break;
        }
    } while (i != 0);
}
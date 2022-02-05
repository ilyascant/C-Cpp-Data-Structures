#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* start = NULL;
struct node* q = NULL;

void reverse()
{
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* current = start;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void sonaEkle(int veri)
{
    struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
    eklenecek->data = veri;
    eklenecek->next = NULL;

    if (start == NULL)
    {
        start = eklenecek;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = eklenecek;
    };
};

void yazdir()
{
    q = start;

    while (q->next != NULL)
    {
        printf("%d=>", q->data);
        q = q->next;
    }
    printf("%d", q->data);
}

int main()
{
    int secim, yon;

    while (1 == 1)
    {
        int toReverse;
        printf("\nBir Tane Sayi Giriniz... \n");
        scanf_s("%d", &secim, sizeof(secim));
        sonaEkle(secim);

        yazdir();

        printf("\n!!! If you want to reverse the LinkedList type 0. If Dont type any number !!!\n");
        scanf_s("%d", &toReverse);

        if (toReverse == 0)
            break;
    }
    reverse();
    yazdir();
    printf("\nDONE");
}
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct node* start = NULL;
struct node* temp = NULL;
struct node* q = NULL;

void basaEkle(int veri);
void aradanSil(int sira);
void yazdir();


int main() {


    int secim, durum, sira;

    while (1 == 1) {
        printf("\nEklemek icin 1'i Silmek icin 2'yi \n");
        scanf("%d", &durum);

        switch (durum)
        {
        case 1:
            printf("\nBir Tane Sayi Giriniz... \n");
            scanf("%d", &secim);
            basaEkle(secim);
            break;
        case 2:
            printf("\nHangi sirayi silmek istiyorsunuz \n");
            scanf("%d", &sira);
            aradanSil(sira);
            break;

        default: NULL;
            break;
        }
        yazdir();
    }

}



void basaEkle(int veri) {

    struct node* eklenecek = (struct node*)malloc(sizeof(struct node));

    eklenecek->data = veri;
    eklenecek->next = NULL;


    if (start == NULL) {

        start = eklenecek;

    }
    else {

        eklenecek->next = start;
        start = eklenecek;
    }


};

void aradanSil(int sira) {

    int i = 1;
    q = start;
    temp = q;

    while (i < sira) {
        i += 1;
        q = q->next;
        (i < sira) ? temp = q : NULL;
    }
    temp->next = q->next;
    free(q);



}

void yazdir() {
    q = start;

    while (q->next != NULL) {
        printf("%d=>", q->data);
        q = q->next;
    };
    printf("%d", q->data);
}


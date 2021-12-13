#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct node* start = NULL;
struct node* temp = NULL;
struct node* q = NULL;

void arayaEkle(int veri, int sira) {

    struct node* eklenecek = (struct node*)malloc(sizeof(struct node));

    eklenecek->data = veri;
    eklenecek->next = NULL;


    int i;

    i = 1;

    if (start == NULL) {

        start = eklenecek;

    }
    else {

        q = start;
        temp = q;


        while (i < sira) {
            i += 1;
            q = q->next;
            (i < sira) ? temp = q : NULL;

        }; eklenecek->next = q; temp->next = eklenecek;


    }


};


void yazdir() {

    q = start;

    while (q->next != NULL) {
        printf("%d=>", q->data);
        q = q->next;
    }
    printf("%d", q->data);
}

int main() {

    int secim, sira;

    while (1 == 1) {

        printf("\nBir Tane Sayi Giriniz... \n");
        scanf("%d", &secim);
        printf("\nEklenecek Sira Nosunu Giriniz \n");
        scanf("%d", &sira);

        arayaEkle(secim, sira);
        yazdir();
    }

}
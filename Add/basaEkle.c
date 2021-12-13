#include <stdlib.h>
#include <stdio.h>



struct node {
    int data;
    struct node* next;
};

struct node* start = NULL;
struct node* q = NULL;

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

void yazdir() {

    q = start;

    while (q->next != NULL) {
        printf("%d=>", q->data);
        q = q->next;
    }
    printf("%d", q->data);
}

int main() {

    int secim;

    while (1 == 1) {

        printf("\nBir Tane Sayi Giriniz... \n");
        scanf("%d", &secim);

        basaEkle(secim);
        yazdir();
    }

}

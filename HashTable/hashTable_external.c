#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define TABLE_SIZE 10

typedef struct person {
    char name[MAX_SIZE];
    int age;
    struct person* next;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char* name) {
    int length = strnlen(name, MAX_SIZE);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

bool hash_table_insert(person* p) {
    if (p == NULL) return NULL;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person* hash_table_lookup(char* name) {
    int index = hash(name);
    person* tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, MAX_SIZE) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

person* hash_table_delete(char* name) {
    int index = hash(name);
    person* tmp = hash_table[index];
    person* prev = NULL;
    while (tmp != NULL && strncmp(tmp->name, name, MAX_SIZE) != 0) {
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL) {
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    return tmp;
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t%s\n", i, "---");

        } else {
            printf("\t%i\t", i);
            person* tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s -> ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
}

int main(void) {
    init_hash_table();

    person beyza = {.name = "Beyza", .age = 17};
    person betul = {.name = "Betul", .age = 26};
    person ilyas = {.name = "Ilyas", .age = 22};
    person salih = {.name = "Salih", .age = 52};
    person hanife = {.name = "Hanife", .age = 44};
    person mustafa = {.name = "Mustafa", .age = 20};
    person enes = {.name = "Enes", .age = 21};
    person esma = {.name = "Esma", .age = 31};
    person armagan = {.name = "Armagan", .age = 19};
    person gulbahar = {.name = "Gulbahar", .age = 21};
    person bahadir = {.name = "Bahadir", .age = 20};

    hash_table_insert(&beyza);
    hash_table_insert(&betul);
    hash_table_insert(&ilyas);
    hash_table_insert(&salih);
    hash_table_insert(&hanife);
    hash_table_insert(&mustafa);
    hash_table_insert(&enes);
    hash_table_insert(&esma);
    hash_table_insert(&armagan);
    hash_table_insert(&gulbahar);
    hash_table_insert(&bahadir);

    hash_table_delete("Ilyas");

    print_table();

    person* tmp = hash_table_lookup("Beyza");
    tmp == NULL ? printf("\n\tNOT FOUND") : printf("\n\t%s is FOUND", tmp->name);

    tmp = hash_table_lookup("Ahmet");
    tmp == NULL ? printf("\n\tNOT FOUND") : printf("\n\t%s is FOUND", tmp->name);

    return 0;
}
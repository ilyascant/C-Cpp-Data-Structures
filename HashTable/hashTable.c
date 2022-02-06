#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFUL)

typedef struct person {
    char name[MAX_SIZE];
    int age;
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
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true;
        }
    }
    printf("\tCOULDN'T INSERT %s INTO TABLE\n", p->name);
    return false;
}

person* hash_table_lookup(char* name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL) {
            return false;
        }
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            return hash_table[try];
        }
    }
    return NULL;
}

person* hash_table_delete(char* name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t%-10s\t%s\n", i, "---", "--");
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t%-10s\t%s\n", i, "<DELETED>", "--");
        } else {
            printf("\t%i\t%-10s\t%i\n", i, hash_table[i]->name, hash_table[i]->age);
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
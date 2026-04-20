#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    if (!al) return NULL;

    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
    if (!al->data) {
        free(al);
        return NULL;
    }

    al->size = 0;
    al->capacity = size;

    return al;
}

void destroyArrayList(arrayList* al) {
    if (!al) return;
    free(al->data);
    free(al);
}

int isEmptyArrayList(arrayList* al) {
    return (al->size == 0);
}

int isFullArrayList(arrayList* al) {
    return (al->size == al->capacity);
}

int sizeArrayList(arrayList* al) {
    return al->size;
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (!al) return 0;
    if (isFullArrayList(al)) return 0;
    if (pos < 0 || pos > al->size) return 0;

    for (int i = al->size - 1; i >= pos; i--) {
        al->data[i + 1] = al->data[i];
    }

    al->data[pos] = item;
    al->size++;

    return 1;
}

elementArrayList deleteArrayList(arrayList* al, int pos) {
    elementArrayList dummy = { 0,0,0 };

    if (!al || isEmptyArrayList(al)) return dummy;
    if (pos < 0 || pos >= al->size) return dummy;

    elementArrayList item = al->data[pos];

    for (int i = pos; i < al->size - 1; i++) {
        al->data[i] = al->data[i + 1];
    }

    al->size--;

    return item;
}

int initArrayList(arrayList* al) {
    if (!al) return 0;

    al->size = 0;
    return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    elementArrayList dummy = { 0,0,0 };

    if (!al || pos < 0 || pos >= al->size)
        return dummy;

    return al->data[pos];
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (!al || pos < 0 || pos >= al->size) return 0;

    al->data[pos] = item;
    return 1;
}

void printArrayList(arrayList* al) {
    if (!al) return;

    printf("Array List ป๓ลย\n");
    printf("Capacity: %d, Size: %d\n", al->capacity, al->size);

    for (int i = 0; i < al->size; i++) {
        printf("(%d %d %d) ",
            al->data[i].row,
            al->data[i].col,
            al->data[i].value);
    }
    printf("\n");
}
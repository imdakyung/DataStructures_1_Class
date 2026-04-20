#include "arrayList.h"

arrayList* createArrayList(int capacity) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    if (!al) return NULL;
    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * capacity);
    if (!al->data) { free(al); return NULL; }
    al->size = 0;
    al->capacity = capacity;
    return al;
}

void destroyArrayList(arrayList* al) {
    if (al) {
        free(al->data);
        free(al);
    }
}

int isEmptyArrayList(arrayList* al) { return al->size == 0; }
int isFullArrayList(arrayList* al) { return al->size == al->capacity; }
int sizeArrayList(arrayList* al) { return al->size; }

void expandArrayList(arrayList* al) {
    int newCap = al->capacity * 2;
    elementArrayList* newData = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * newCap);
    if (newData) {
        al->data = newData;
        al->capacity = newCap;
    }
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    // 양의 정수 제약: 0보다 커야 함
    if (item <= 0) {
        printf("오류: 양의 정수만 입력 가능합니다.\n");
        return 0;
    }
    if (pos < 0 || pos > al->size) return 0;

    if (isFullArrayList(al)) expandArrayList(al);

    for (int i = al->size; i > pos; i--)
        al->data[i] = al->data[i - 1];

    al->data[pos] = item;
    al->size++;
    return 1;
}

elementArrayList deleteArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) return -1; // 오류 시 -1 반환

    elementArrayList item = al->data[pos];
    for (int i = pos; i < al->size - 1; i++)
        al->data[i] = al->data[i + 1];

    al->size--;
    return item;
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (item <= 0 || pos < 0 || pos >= al->size) return 0;
    al->data[pos] = item;
    return 1;
}

void clearArrayList(arrayList* al) {
    al->size = 0; // 물리적 삭제 대신 사이즈 초기화로 성능 최적화
    printf("리스트의 모든 값이 삭제되었습니다.\n");
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) return -1;
    return al->data[pos];
}

void printArrayList(arrayList* al) {
    if (isEmptyArrayList(al)) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    printf("현재 리스트 (Size: %d): ", al->size);
    for (int i = 0; i < al->size; i++) {
        printf("[%d]:%d ", i, al->data[i]);
    }
    printf("\n");
}
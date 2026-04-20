#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementArrayList;

typedef struct arrayListType {
    elementArrayList* data;
    int size;
    int capacity;
} arrayList;

// 생성 및 소멸
arrayList* createArrayList(int capacity);
void destroyArrayList(arrayList* al);

// 상태 확인
int isEmptyArrayList(arrayList* al);
int isFullArrayList(arrayList* al);
int sizeArrayList(arrayList* al);

// 주요 기능
int insertArrayList(arrayList* al, int pos, elementArrayList item);
elementArrayList deleteArrayList(arrayList* al, int pos);
int replaceItemArrayList(arrayList* al, int pos, elementArrayList item);
void clearArrayList(arrayList* al); // 추가된 기능

// 정보 출력 및 획득
elementArrayList getItemArrayList(arrayList* al, int pos);
void printArrayList(arrayList* al);

#endif
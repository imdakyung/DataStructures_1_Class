#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>

// 다항식의 항을 표현하는 구조체
typedef struct ElementType {
	int coef; // 계수
	int expo; // 지수
} elementType;

typedef elementType elementArrayList;

// 순차 리스트 구조체
typedef struct arrayListType {
	elementArrayList* data; // 데이터 배열 포인터
	int size;               // 현재 저장된 원소의 개수
	int capacity;           // 배열의 최대 용량
} arrayList;

// 함수 원형 선언
extern arrayList* createArrayList(int size);
extern void destroyArrayList(arrayList* al);
extern int isEmptyArrayList(arrayList* al);
extern int isFullArrayList(arrayList* al);
extern int sizeArrayList(arrayList* al);
extern int insertArrayList(arrayList* al, int pos, elementArrayList item);
extern elementArrayList deleteArrayList(arrayList* al, int pos);
extern int initArrayList(arrayList* al);
extern elementArrayList getItemArrayList(arrayList* al, int pos);
extern int replaceItemArrayList(arrayList* al, int pos, elementArrayList item);
extern void printArrayList(arrayList* al);

#endif
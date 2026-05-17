#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int x;
	int y;
	struct pointType* next;
} PointType;

typedef struct linkedList {
	struct pointType* head;
	int size;
} LinkedList;

extern LinkedList* createLinkedList(); //리스트 생성
extern int destroyLinkedList(LinkedList* li); //전체메모리 해제
extern int isEmptyLinkedList(LinkedList* li); //리스트가 비어있는지 확인하는 함수
extern int sizeLinkedList(LinkedList* li); //노드 개수 반환 : size 값
extern LinkedList* insertFirstLinkedList(LinkedList* li, PointType item); //맨 앞 삽입
extern int printLinkedList(LinkedList* li); //전체 출력
extern LinkedList* insertLastLinkedList(LinkedList* li, PointType item); //맨 뒤 삽입
extern LinkedList* deleteAtLinkedList(LinkedList* li, int at);  //특정 위치 삭제
extern LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, PointType item); //특정 노드 뒤에 새로운 노드를 삽입하는 함수
extern PointType deleteFirstLinkedList(LinkedList* li); //맨 앞 삭제
extern PointType deleteLastLinkedList(LinkedList* li); //맨 뒤 삭제

extern LinkedList* insertAtLinkedList(LinkedList* li, int at, PointType item);//특정위치 삽입

/*
* 깃허브에 등록된 연결 리스트 소스 코드와 공지사항의 ADT를 바탕으로, 사용자가 메뉴를 통해 정수 목록을 자유롭게 추가, 삭제, 검색할 수 있는 프로그램을 작성하시오.메뉴는 다음과 같다.

1. 맨 앞에 추가 : 정수를 입력받아 리스트의 가장 앞에 삽입 0

2. 맨 뒤에 추가 : 정수를 입력받아 리스트의 가장 뒤에 삽입 0

3. 특정 위치에 추가 : 위치(index)와 정수를 입력받아 해당 위치에 삽입 0

4. 특정 위치 삭제 : 위치(index)를 입력받아 해당 노드를 삭제하고 값 출력 0 

5. 전체 목록 출력 : 현재 리스트에 저장된 모든 정수를 순서대로 출력 0 

6. 리스트 크기 확인 : 현재 저장된 노드의 총 개수를 출력 0

0. 종료 : 모든 메모리를 해제(destroy)하고 프로그램을 종료 0 
*/
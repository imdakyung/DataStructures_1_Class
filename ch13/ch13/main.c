#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct linkedList* myList1 = createLinkedList();
    int choice, val, index;
    PointType item;

    printf("연결 리스트 대화형 프로그램을 시작합니다.\n");

    while (1) {
        printf("1. 맨 앞에 추가\n");
        printf("2. 맨 뒤에 추가\n");
        printf("3. 특정 위치에 추가\n");
        printf("4. 특정 위치 삭제\n");
        printf("5. 전체 목록 출력\n");
        printf("6. 리스트 크기 확인\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");

        if (scanf("%d", &choice) != 1) {
            printf("숫자를 입력해주세요.\n"); //글자 입력시
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        switch (choice) {
        case 1:
            printf("추가할 정수를 입력하세요: ");
            scanf("%d", &val);
            item.x = val;
            item.y = 0;
            item.next = NULL;
            insertFirstLinkedList(myList1, item);
            printf("맨 앞에 %d(이)가 추가되었습니다.\n", val);
            break;

        case 2:
            printf("추가할 정수를 입력하세요: ");
            scanf("%d", &val);
            item.x = val;
            item.y = 0;
            item.next = NULL;
            insertLastLinkedList(myList1, item);
            printf("맨 뒤에 %d(이)가 추가되었습니다.\n", val);
            break;

        case 3:
            printf("삽입할 위치와 정수를 띄어쓰기로 입력하세요 (예: 1 10): ");
            scanf("%d %d", &index, &val);
            item.x = val;
            item.y = 0;
            item.next = NULL;
            insertAtLinkedList(myList1, index, item);
            printf("인덱스 %d에 %d가 추가되었습니다.\n", index, val);
            break;

        case 4:
            printf("삭제할 위치를 입력하세요: ");
            scanf("%d", &index);
            deleteAtLinkedList(myList1, index);
            printLinkedList(myList1);
            break;

        case 5:
            printLinkedList(myList1);
            break;

        case 6:
            printf("현재 저장된 노드의 총 개수: %d\n", sizeLinkedList(myList1));
            break;

        case 0:
            destroyLinkedList(myList1);
            printf("메모리를 해제하고 프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 입력입니다. 0~6 사이의 번호를 선택해주세요.\n");
        }
    }

    return 0;


}
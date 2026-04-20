#define _CRT_SECURE_NO_WARNINGS
#include "arrayList.h"

void showMenu() {
    printf("\n--- 양의 정수 리스트 관리 ---\n");
    printf("1. 추가 (Insert)\n");
    printf("2. 삭제 (Delete)\n");
    printf("3. 변경 (Replace)\n");
    printf("4. 출력 (Print)\n");
    printf("5. 전체 삭제 (Clear)\n");
    printf("0. 종료\n");
    printf("선택: ");
}

int main() {
    arrayList* myL = createArrayList(5);
    int choice, pos, val;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
        case 1:
            printf("위치와 양의 정수 입력: ");
            scanf("%d %d", &pos, &val);
            if (insertArrayList(myL, pos, val)) printf("추가 성공!\n");
            else printf("추가 실패 (위치 오류 또는 양수 아님)\n");
            break;
        case 2:
            printf("삭제할 위치 입력: ");
            scanf("%d", &pos);
            val = deleteArrayList(myL, pos);
            if (val != -1) printf("삭제된 값: %d\n", val);
            else printf("삭제 실패 (잘못된 위치)\n");
            break;
        case 3:
            printf("변경할 위치와 새 양의 정수 입력: ");
            scanf("%d %d", &pos, &val);
            if (replaceItemArrayList(myL, pos, val)) printf("변경 성공!\n");
            else printf("변경 실패\n");
            break;
        case 4:
            printArrayList(myL);
            break;
        case 5:
            clearArrayList(myL);
            break;
        default:
            printf("잘못된 선택입니다.\n");
        }
    }

    destroyArrayList(myL);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynomial.h"

// 문자열을 분석하여 다항식 리스트에 저장
void parsePolynomial(arrayList* al, const char* str) {
    int coef, expo;
    const char* ptr = str;
    int read_count = 0;

    while (*ptr != '\0') {
        // "%dX^%d" 형식으로 읽어들이고, 몇 바이트를 읽었는지 %n을 통해 파악
        if (sscanf(ptr, "%dX^%d%n", &coef, &expo, &read_count) >= 2) {
            elementArrayList item = { coef, expo };
            insertArrayList(al, al->size, item); // 맨 뒤에 추가
            ptr += read_count; // 읽은 바이트만큼 포인터 이동

            if (*ptr == '+') {
                ptr++; // '+' 기호는 다음 항을 위해 스킵
            }
        }
        else {
            break; // 파싱 형식이 맞지 않으면 루프 종료
        }
    }
}

// 다항식의 덧셈 함수 (흔히 실수하는 오류 방지)
arrayList* addPolynomial(arrayList* A, arrayList* B) {
    arrayList* C = createArrayList(A->capacity + B->capacity);
    int a_idx = 0, b_idx = 0;

    // A와 B 모두 항이 남아있을 때
    while (a_idx < A->size && b_idx < B->size) {
        elementArrayList a_item = getItemArrayList(A, a_idx);
        elementArrayList b_item = getItemArrayList(B, b_idx);

        if (a_item.expo > b_item.expo) {
            insertArrayList(C, C->size, a_item);
            a_idx++;
        }
        else if (a_item.expo < b_item.expo) {
            insertArrayList(C, C->size, b_item);
            b_idx++;
        }
        else {
            int sum_coef = a_item.coef + b_item.coef;
            // 계수의 합이 0이 되면 리스트에 넣지 않고 무시해야 함
            if (sum_coef != 0) {
                elementArrayList new_item = { sum_coef, a_item.expo };
                insertArrayList(C, C->size, new_item);
            }
            a_idx++;
            b_idx++;
        }
    }

    // A 또는 B에 남은 항들을 C에 일괄 복사 (둘 중 하나만 실행됨)
    for (; a_idx < A->size; a_idx++) {
        insertArrayList(C, C->size, getItemArrayList(A, a_idx));
    }
    for (; b_idx < B->size; b_idx++) {
        insertArrayList(C, C->size, getItemArrayList(B, b_idx));
    }

    return C;
}

// 다항식의 곱셈 함수
arrayList* multPolynomial(arrayList* A, arrayList* B) {
    // 넉넉한 용량으로 결과 리스트 생성
    arrayList* C = createArrayList(A->capacity * B->capacity);

    for (int i = 0; i < A->size; i++) {
        elementArrayList a_item = getItemArrayList(A, i);

        for (int j = 0; j < B->size; j++) {
            elementArrayList b_item = getItemArrayList(B, j);

            // 두 항의 계수는 곱하고 지수는 더함
            int new_coef = a_item.coef * b_item.coef;
            int new_expo = a_item.expo + b_item.expo;

            if (new_coef == 0) continue; // 계수가 0이면 저장할 필요 없음

            int found = 0;
            // C 리스트를 탐색하여 지수가 같은 항이 있으면 계수를 더함
            for (int k = 0; k < C->size; k++) {
                elementArrayList c_item = getItemArrayList(C, k);

                if (c_item.expo == new_expo) {
                    c_item.coef += new_coef;
                    replaceItemArrayList(C, k, c_item);
                    found = 1;
                    break;
                }
                else if (c_item.expo < new_expo) {
                    // 내림차순 정렬 유지를 위해 해당 위치에 새 항 삽입
                    elementArrayList new_item = { new_coef, new_expo };
                    insertArrayList(C, k, new_item);
                    found = 1;
                    break;
                }
            }

            // 동일한 지수나 더 작은 지수가 없었다면 가장 끝에 삽입
            if (!found) {
                elementArrayList new_item = { new_coef, new_expo };
                insertArrayList(C, C->size, new_item);
            }
        }
    }

    // 연산 과정에서 계수가 0이 된 항들을 찾아서 깔끔하게 제거
    for (int i = 0; i < C->size; i++) {
        if (getItemArrayList(C, i).coef == 0) {
            deleteArrayList(C, i);
            i--; // 인덱스가 한 칸 당겨지므로 i 값을 감소시킴
        }
    }

    return C;
}

// 다항식을 수식 형태로 출력하는 함수
void printPolynomial(arrayList* al) {
    if (al->size == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < al->size; i++) {
        elementArrayList item = getItemArrayList(al, i);

        // 첫 번째 항이 아니고 계수가 양수일 때만 '+' 출력 (음수는 자체 부호가 출력됨)
        if (i > 0 && item.coef > 0) {
            printf("+");
        }
        printf("%dX^%d", item.coef, item.expo);
    }
    printf("\n");
}
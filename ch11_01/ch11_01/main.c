#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "polynomial.h"

int main() {
    char input1[256];
    char input2[256];

    // 첫 번째 다항식 입력
    printf("첫 번째 다항식을 입력하세요 (예: 3X^2+2X^1+1X^0): ");
    scanf("%255s", input1);

    // 두 번째 다항식 입력
    printf("두 번째 다항식을 입력하세요 (예: 2X^1+1X^0): ");
    scanf("%255s", input2);

    // 다항식을 저장할 충분한 크기의 순차 리스트 2개 생성
    arrayList* poly1 = createArrayList(100);
    arrayList* poly2 = createArrayList(100);

    // 입력받은 문자열을 파싱하여 리스트에 각각 저장
    parsePolynomial(poly1, input1);
    parsePolynomial(poly2, input2);

    printf("\n============== [ 결과 ] ==============\n");
    printf("다항식 A(X) = ");
    printPolynomial(poly1);
    printf("다항식 B(X) = ");
    printPolynomial(poly2);
    printf("--------------------------------------\n");

    // 1. 다항식의 덧셈 연산 및 출력 (수정된 덧셈 로직)
    arrayList* polyAdd = addPolynomial(poly1, poly2);
    printf("A(X) + B(X) = ");
    printPolynomial(polyAdd);

    // 2. 다항식의 곱셈 연산 및 출력
    arrayList* polyMult = multPolynomial(poly1, poly2);
    printf("A(X) * B(X) = ");
    printPolynomial(polyMult);
    printf("======================================\n");

    // 동적 할당된 메모리 자원 해제
    destroyArrayList(poly1);
    destroyArrayList(poly2);
    destroyArrayList(polyAdd);
    destroyArrayList(polyMult);

    return 0;
}
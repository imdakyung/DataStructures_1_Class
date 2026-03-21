#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_math.h"

int main() {
    int x, y;

    printf("두 정수를 입력하세요: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    printf("GCD: %d, LCM: %d\n", gcd(x, y), lcm(x, y));

    return 0;
}
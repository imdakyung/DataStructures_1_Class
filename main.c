#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int x = 1;
    int a = ~x + 1;//x를 2의 보수로 바꾼 것
    int y = -1; //x의 2의 보수인 -1이다
    if (a == y)//만약 두개가 정확히 일치하다면 시스템은 2의 보수로 -1을 저장한 것이다 아니라면 -1은 1의 보수만 취한 것이다
        printf("2의 보수입니다.\n");
    else
        printf("1의 보수입니다.\n");
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);

    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (N + 1);
    }

    printf("정방향 출력: ");
    for (int* p = arr; p < arr + N; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    printf("역방향 출력: ");
    for (int* p = arr + N - 1; p >= arr; p--) {
        printf("%d ", *p);
    }
    printf("\n");

    int sum = 0;
    int max = *arr;
    int min = *arr;

    for (int* p = arr; p < arr + N; p++) {
        sum += *p;

        if (*p > max) max = *p;
        if (*p < min) min = *p;
    }

    printf("총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    free(arr);

    return 0;
}
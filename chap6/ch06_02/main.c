#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    // 홀수 체크
    if (N % 2 == 0) {
        printf("홀수만 입력 가능합니다.\n");
        return 1;
    }

    // 2차원 동적 배열 생성
    int** arr = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * N);
    }

    // 배열 0으로 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }

    //  마방진 생성
    int num = 1;
    int i = 0;
    int j = N / 2;

    while (num <= N * N) {
        arr[i][j] = num;

        int next_i = (i - 1 + N) % N;
        int next_j = (j + 1) % N;

        if (arr[next_i][next_j] != 0) {
            i = (i + 1) % N;
        }
        else {
            i = next_i;
            j = next_j;
        }

        num++;
    }

    // 1. 배열 출력
    printf("마방진:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    //2. 합 출력 (검증)
    printf("\n합 검증:\n");

    // 가로
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += arr[i][j];
        }
        printf("가로 %d: %d\n", i + 1, sum);
    }

    // 세로
    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i][j];
        }
        printf("세로 %d: %d\n", j + 1, sum);
    }

    // 대각선 1
    int sum1 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += arr[i][i];
    }
    printf("대각선 1: %d\n", sum1);

    // 대각선 2
    int sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum2 += arr[i][N - 1 - i];
    }
    printf("대각선 2: %d\n", sum2);

    // 메모리 해제
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
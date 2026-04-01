#include <stdio.h>

#define N 3   // 반드시 홀수!

int main() {
    int magic[N][N] = { 0 };
    int i, j;
    int num = 1;

    int row = 0;
    int col = N / 2;

    while (num <= N * N) {
        magic[row][col] = num;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (magic[next_row][next_col] != 0) {
            row = (row + 1) % N;
        }
        else {
            row = next_row;
            col = next_col;
        }

        num++;
    }

    // 마방진 출력
    printf("마방진:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", magic[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // 가로 합
    printf("가로 합:\n");
    for (i = 0; i < N; i++) {
        int sum = 0;
        for (j = 0; j < N; j++) {
            sum += magic[i][j];
        }
        printf("%d\n", sum);
    }

    // 세로 합
    printf("세로 합:\n");
    for (j = 0; j < N; j++) {
        int sum = 0;
        for (i = 0; i < N; i++) {
            sum += magic[i][j];
        }
        printf("%d\n", sum);
    }

    // 대각선 합
    int sum1 = 0, sum2 = 0;

    for (i = 0; i < N; i++) {
        sum1 += magic[i][i];
        sum2 += magic[i][N - 1 - i];
    }

    printf("대각선 합:\n");
    printf("%d\n", sum1);
    printf("%d\n", sum2);

    return 0;
}
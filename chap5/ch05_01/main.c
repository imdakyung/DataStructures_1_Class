#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int arr[N];
    int i;
    int sum = 0;
    int max, min;

    srand(time(NULL));

    // 배열 채우기 (0 ~ N 이하 랜덤값)
    for (i = 0; i < N; i++) {
        arr[i] = rand() % (N + 1);
    }

    // 처음부터 출력
    printf("정방향 출력:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // 뒤에서부터 출력
    printf("역방향 출력:\n");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // 초기값 설정
    max = min = arr[0];

    // 합, 최대, 최소 계산
    for (i = 0; i < N; i++) {
        sum += arr[i];

        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    return 0;
}
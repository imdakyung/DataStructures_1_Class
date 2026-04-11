#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int id;
    int score;
} Student;

int main() {
    int N;

    printf("학생 수 입력: ");
    scanf("%d", &N);

    Student* arr = (Student*)malloc(sizeof(Student) * N);
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 0;
    }

    FILE* fp = fopen("C:\\Users\\user\\Desktop\\name_list.txt", "r");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        free(arr);
        return 0;
    }

    srand((unsigned int)time(NULL));

    char buffer[50];
    int i = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL && i < N) {
        buffer[strcspn(buffer, "\n")] = '\0';

        strcpy((arr + i)->name, buffer);
        (arr + i)->id = i + 1;
        (arr + i)->score = rand() % 100 + 1;

        i++;
    }

    fclose(fp);

    int sum = 0;
    int maxIdx = 0, minIdx = 0;

    for (i = 0; i < N; i++) {
        sum += (arr + i)->score;

        if ((arr + i)->score > (arr + maxIdx)->score)
            maxIdx = i;

        if ((arr + i)->score < (arr + minIdx)->score)
            minIdx = i;
    }

    printf("\n===== 결과 (포인터 연산) =====\n");
    printf("최고점 학생: %s %d %d\n", (arr + maxIdx)->name, (arr + maxIdx)->id, (arr + maxIdx)->score);
    printf("최저점 학생: %s %d %d\n", (arr + minIdx)->name, (arr + minIdx)->id, (arr + minIdx)->score);
    printf("평균 점수: %.2f\n", (double)sum / N);

    free(arr);
    return 0;
}
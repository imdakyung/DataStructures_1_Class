#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define NON_ZERO 20

typedef struct {
    int r, c, v;
} Element;

typedef struct {
    Element* data;
    int count;
    int capacity;
} ArrayList;


typedef struct {
    int rows, cols;
    ArrayList* L;
} SparseMatrix;


ArrayList* createList(int capacity) {
    ArrayList* L = (ArrayList*)malloc(sizeof(ArrayList));
    if (!L) return NULL;

    L->data = (Element*)malloc(sizeof(Element) * capacity);
    if (!L->data) {
        free(L);
        return NULL;
    }

    L->count = 0;
    L->capacity = capacity;
    return L;
}


int transpose(SparseMatrix* A, SparseMatrix* B) {
    int moveCount = 0;

    B->rows = A->cols;
    B->cols = A->rows;
    B->L->count = A->L->count;

    int bIndex = 0;

    for (int c = 0; c < A->cols; c++) {
        for (int i = 0; i < A->L->count; i++) {
            if (A->L->data[i].c == c) {

                B->L->data[bIndex].r = A->L->data[i].c;
                B->L->data[bIndex].c = A->L->data[i].r;
                B->L->data[bIndex].v = A->L->data[i].v;

                bIndex++;
                moveCount++;  
            }
        }
    }

    return moveCount;
}

void printMatrix(SparseMatrix* A) {
    printf("\n--- 희소행렬 ---\n");
    for (int i = 0; i < A->L->count; i++) {
        printf("(%d, %d, %d)\n",
            A->L->data[i].r,
            A->L->data[i].c,
            A->L->data[i].v);
    }
}

int main() {

    SparseMatrix A, B;

    A.rows = MAX_ROWS;
    A.cols = MAX_COLS;
    A.L = createList(NON_ZERO);

    B.rows = MAX_COLS;
    B.cols = MAX_ROWS;
    B.L = createList(NON_ZERO);


    A.L->count = NON_ZERO;


    for (int i = 0; i < NON_ZERO; i++) {
        A.L->data[i].r = i / 2;
        A.L->data[i].c = (i * 3) % 10;
        A.L->data[i].v = i + 1;
    }


    printf("--- 희소행렬 전치 실행 ---\n");

    int moves = transpose(&A, &B);

    printf("행렬 크기: %d x %d\n", A.rows, A.cols);
    printf("0이 아닌 원소 수: %d\n", A.L->count);
    printf("데이터 이동 횟수: %d\n", moves);

    printMatrix(&B);


    free(A.L->data);
    free(A.L);

    free(B.L->data);
    free(B.L);

    return 0;
}
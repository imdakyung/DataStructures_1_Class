#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
    return createArrayList(row * col);
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
    if (!sm) return 0;

    int size = sizeArrayList(sm);

    return insertArrayList(
        sm,
        size,
        (elementArrayList) {
        row, col, value
    }
    );
}

int printSparseMatrix(sparseMatrix* sm) {
    if (!sm) return 0;

    printf("Sparse Matrix 입니다\n");
    printArrayList(sm);

    return 1;
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
    if (!sm1 || !sm2) return NULL;

    sparseMatrix* result =
        createArrayList(sizeArrayList(sm1) + sizeArrayList(sm2));

    // 1. sm1 전체 복사
    for (int i = 0; i < sizeArrayList(sm1); i++) {
        insertArrayList(
            result,
            sizeArrayList(result),
            getItemArrayList(sm1, i)
        );
    }

    // 2. sm2 병합
    for (int i = 0; i < sizeArrayList(sm2); i++) {
        elementArrayList b = getItemArrayList(sm2, i);

        int found = 0;

        for (int j = 0; j < sizeArrayList(result); j++) {
            elementArrayList a = getItemArrayList(result, j);

            if (a.row == b.row && a.col == b.col) {
                a.value += b.value;
                replaceItemArrayList(result, j, a);
                found = 1;
                break;
            }
        }

        if (!found) {
            insertArrayList(result, sizeArrayList(result), b);
        }
    }

    return result;
}
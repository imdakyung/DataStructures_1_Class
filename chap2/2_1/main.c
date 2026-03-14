#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float num;
    unsigned int bits;
    int i;

    scanf("%f", &num);

    bits = *((unsigned int*)&num);

    printf("%u/", (bits >> 31) & 1);

    for (i = 30; i >= 23; i--) {
        printf("%u", (bits >> i) & 1);
        if (i == 27) printf(" ");
    }
    printf("/");

    for (i = 22; i >= 0; i--) {
        printf("%u", (bits >> i) & 1);
        if (i == 19 || i == 15 || i == 11 || i == 7 || i == 3)
            printf(" ");
    }

    return 0;
}

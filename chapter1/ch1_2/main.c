#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float input;
    printf("ÀÔ·Â°ª: ");
    scanf("%f", &input);

    int result = (int)(input * 256);

    for (int i = 15; i >= 0; i--) {
        int bit = (result >> i) & 1;
        printf("%d", bit);

        if (i == 8) {
            printf(".");
        }
    }
    printf("\n");
    return 0;
}
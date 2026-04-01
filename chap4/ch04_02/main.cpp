#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    clock_t start, end;

    for (int n = 5; n <= 50; n++) {
        start = clock();

        int result = gcd(fib(n), fib(n - 1));

        end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n=%d, time=%f\n", n, time_spent);
    }

    return 0;
}
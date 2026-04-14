#include <stdio.h>

// 재귀 방법
int fibo_recursive(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

// 순환(반복) 방법
int fibo_iterative(int n) {
    int f1 = 1;
    int f2 = 1;

    if (n == 1) {
        return f1;
    }
    else if (n == 2) {
        return f2;
    }
    else {
        int fn;
        for (int i = 3; i <= n; i++) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
}

int main() {
    int n = 80;

    printf("재귀 결과 f(%d) : %d\n", n, fibo_recursive(n));
    printf("순환 결과 f(%d) : %d\n", n, fibo_iterative(n));

    return 0;
}
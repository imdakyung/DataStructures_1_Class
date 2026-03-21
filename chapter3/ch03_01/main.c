#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_fraction.h"

int main() {
    char f1[20], op, f2[20];

    if (scanf("%s %c %s", f1, &op, f2) != 3) {
        printf("Error: invalid input\n");
        return 1;
    }

    Fraction a = from_string(f1);
    Fraction b = from_string(f2);
    Fraction result;

    switch (op) {
    case '+': result = add(a, b); break;
    case '-': result = sub(a, b); break;
    case '*': result = mul(a, b); break;
    case '/': result = divi(a, b); break;
    default:
        printf("Error: invalid operator\n");
        return 1;
    }

    print_fraction(result);
    printf("\n");

    return 0;
}
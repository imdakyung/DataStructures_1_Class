#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_fraction.h"
#include "my_math.h"

Fraction make_fraction(int num, int den) {
    if (den == 0) {
        printf("Error: denominator cannot be zero\n");
        exit(1);
    }
    Fraction f = { num, den };
    return reduce(f);
}

Fraction reduce(Fraction f) {
    if (f.num == 0) {
        f.den = 1;
        return f;
    }

    int g = gcd(abs(f.num), abs(f.den));
    f.num /= g;
    f.den /= g;

    if (f.den < 0) {
        f.num *= -1;
        f.den *= -1;
    }

    return f;
}

Fraction add(Fraction a, Fraction b) {
    return make_fraction(a.num * b.den + b.num * a.den, a.den * b.den);
}

Fraction sub(Fraction a, Fraction b) {
    return make_fraction(a.num * b.den - b.num * a.den, a.den * b.den);
}

Fraction mul(Fraction a, Fraction b) {
    return make_fraction(a.num * b.num, a.den * b.den);
}

Fraction divi(Fraction a, Fraction b) {
    if (b.num == 0) {
        printf("Error: division by zero\n");
        exit(1);
    }
    return make_fraction(a.num * b.den, a.den * b.num);
}

Fraction from_string(const char* str) {
    int a, b;


    if (strchr(str, '/')) {
        if (sscanf(str, "%d/%d", &a, &b) != 2) {
            printf("Error: invalid fraction format\n");
            exit(1);
        }
        return make_fraction(a, b);
    }

    else if (strchr(str, '.')) {
        int int_part, frac_part;
        int scale = 1;

        if (sscanf(str, "%d.%d", &int_part, &frac_part) != 2) {
            printf("Error: invalid decimal format\n");
            exit(1);
        }

        int temp = frac_part;
        while (temp > 0) {
            scale *= 10;
            temp /= 10;
        }

        int num = int_part * scale + frac_part;
        return make_fraction(num, scale);
    }

    else {
        int n;
        if (sscanf(str, "%d", &n) != 1) {
            printf("Error: invalid integer format\n");
            exit(1);
        }
        return make_fraction(n, 1);
    }
}

void print_fraction(Fraction f) {
    if (f.den == 1)
        printf("%d", f.num);
    else
        printf("%d/%d", f.num, f.den);
}
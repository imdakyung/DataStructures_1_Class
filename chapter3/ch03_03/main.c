#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    long long num;
    long long den;
} Fraction;

static long long ll_abs(long long x)
{
    return x < 0 ? -x : x;
}

static long long gcd(long long a, long long b)
{
    a = ll_abs(a);
    b = ll_abs(b);
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

static void reduce(Fraction* f)
{

    if (f->den == 0) {
        fprintf(stderr, "Error: denominator is zero.\n");
        exit(1);
    }
    long long g = gcd(f->num, f->den);
    f->num /= g;
    f->den /= g;

    if (f->den < 0) {
        f->num = -f->num;
        f->den = -f->den;
    }
}

static Fraction parse_fraction(const char* s)
{
    Fraction f;

    if (s == NULL || s[0] == '\0') {
        fprintf(stderr, "Error: empty argument.\n");
        exit(1);
    }

    const char* slash = strchr(s, '/');
    if (slash != NULL) {
        char buf[64];
        size_t len = (size_t)(slash - s);

        if (len == 0 || *(slash + 1) == '\0') {
            fprintf(stderr, "Error: invalid fraction format '%s'.\n", s);
            exit(1);
        }

        strncpy(buf, s, len);
        buf[len] = '\0';
        f.num = atoll(buf);
        f.den = atoll(slash + 1);

        if (f.den == 0) {
            fprintf(stderr, "Error: denominator cannot be zero in '%s'.\n", s);
            exit(1);
        }
        reduce(&f);
        return f;
    }

    if (strchr(s, '.') != NULL) {
        double val = atof(s);
        const char* dot = strchr(s, '.');
        int decimal_places = (int)strlen(dot + 1);

        long long denom = 1;
        for (int i = 0; i < decimal_places; i++)
            denom *= 10;

        f.num = (long long)round(val * denom);
        f.den = denom;
        reduce(&f);
        return f;
    }

    f.num = atoll(s);
    f.den = 1;
    return f;
}


static Fraction frac_add(Fraction a, Fraction b)
{
    Fraction r;
    r.num = a.num * b.den + b.num * a.den;
    r.den = a.den * b.den;
    reduce(&r);
    return r;
}

static Fraction frac_mul(Fraction a, Fraction b)
{
    Fraction r;
    r.num = a.num * b.num;
    r.den = a.den * b.den;
    reduce(&r);
    return r;
}

static Fraction frac_double(Fraction a)
{
    Fraction two = { 2, 1 };
    return frac_mul(two, a);
}

static void print_fraction(Fraction f)
{
    if (f.den == 1)
        printf("%lld", f.num);
    else
        printf("%lld/%lld", f.num, f.den);
}

int main(int c, char** v)
{
    if (c != 3) {
        fprintf(stderr, "Usage: %s <width> <height>\n", v[0]);
        fprintf(stderr, "  width, height: fraction(A/B), integer, or decimal\n");
        return 1;
    }

    Fraction width = parse_fraction(v[1]);
    Fraction height = parse_fraction(v[2]);

    if (width.num <= 0 || height.num <= 0) {
        fprintf(stderr, "Error: width and height must be positive.\n");
        return 1;
    }

    Fraction perimeter = frac_double(frac_add(width, height));

    Fraction area = frac_mul(width, height);

    printf("Perimeter: ");
    print_fraction(perimeter);
    printf(", Area: ");
    print_fraction(area);
    printf("\n");

    return 0;
}
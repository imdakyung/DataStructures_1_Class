#pragma once
#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef struct {
    int num;
    int den;
} Fraction;

Fraction make_fraction(int num, int den);
Fraction reduce(Fraction f);

Fraction add(Fraction a, Fraction b);
Fraction sub(Fraction a, Fraction b);
Fraction mul(Fraction a, Fraction b);
Fraction divi(Fraction a, Fraction b);

Fraction from_string(const char* str);
void print_fraction(Fraction f);

#endif
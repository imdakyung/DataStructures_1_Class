#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "arrayList.h"

// 문자열로 된 다항식을 파싱하여 순차 리스트에 저장하는 함수
void parsePolynomial(arrayList* al, const char* str);

// 두 다항식을 더하는 함수 (수업시간 코드의 보완판)
arrayList* addPolynomial(arrayList* A, arrayList* B);

// 두 다항식을 곱하는 함수
arrayList* multPolynomial(arrayList* A, arrayList* B);

// 다항식을 보기 좋게(예: 3X^2+2X^1+1X^0) 출력하는 함수
void printPolynomial(arrayList* al);

#endif
본 프로젝트는 피보나치 수열을 계산하는 두 가지 방식:

재귀(Recursive), 반복(Iterative)을 구현하고, 입력 크기(n)에 따른 실행 시간 성능 차이를 분석하는 것을 목표로 한다.

재귀 방식 (Recursive)
int fibo_recursive(int n) {
    if (n <= 2) return 1;
    return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

정의에 충실한 방식
동일한 계산을 반복 수행
시간 복잡도: O(2^n)

반복 방식 (Iterative)
int fibo_iterative(int n) {
    int f1 = 1, f2 = 1;

    if (n <= 2) return 1;

    int fn;
    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}

이전 값을 활용하여 계산
시간 복잡도: O(n)

실행 시간 측정 결과
n 값	|실행 시간 (초)

20	    |2.683

40	    |3.755

60	    |7.47

80	    |683.56분 이상

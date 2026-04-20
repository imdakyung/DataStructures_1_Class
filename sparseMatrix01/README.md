arrayList.c에서의 고침
(1) insertArrayList 버그
문제
for (int i = al->size; i >= pos; i--)

i+1 접근 시 overflow 가능

해결
for (int i = al->size - 1; i >= pos; i--)
(2) deleteArrayList 범위 체크 없음

잘못된 index 들어오면 크래시
 dummy return 추가

(3) initArrayList 의미 오류

기존:

for (...) deleteArrayList(...)

개선:

al->size = 0;

(4) NULL 안정성 없음

모든 함수에 if (!al) 추가


sparseMatrix.c에서의 고친 것
❌ (1) 반복문 범위 오류 (치명적)
for (int i = 0; i <= sizeArrayList(sm1); i++)

👉 반드시:

for (int i = 0; i < sizeArrayList(sm1); i++)
이유
<= 때문에 마지막에서 out-of-bounds 접근
heap corruption 가능
❌ (2) return 누락
int addElementSparseMatrix(...)
int printSparseMatrix(...)

👉 return 없음 → UB (Undefined Behavior)

❌ (3) 덧셈 로직 구조 한계

현재 구조:

sm1 기준 loop
sm2에서만 찾고 합침

문제:

sm2에만 있는 값은 제대로 처리 안 될 수 있음
확장성 낮음
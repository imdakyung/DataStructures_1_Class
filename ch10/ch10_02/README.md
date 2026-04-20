희소행렬 순차리스트 기반 전치 프로그램

이 프로그램은 10×10 크기의 행렬을 희소행렬(Sparse Matrix) 형태로 표현하고,  
0이 아닌 원소 20개를 순차리스트 구조로 저장한 뒤 전치 행렬(Transpose Matrix)을 생성하는 프로그램이다.

전치 과정에서 데이터 이동 횟수를 계산하여 출력한다.



본 프로그램은 다음과 같은 다단계 포인터 구조로 설계되었다.

SparseMatrix  
→ ArrayList*  
→ Element*


typedef struct {
    int r, c, v;
} Element;

- r: 행 (row)  
- c: 열 (column)  
- v: 값 (value)


typedef struct {
    Element* data;
    int count;
    int capacity;
} ArrayList;

- 동적 배열 기반 순차 리스트  
- 희소행렬의 0이 아닌 원소 저장


typedef struct {
    int rows, cols;
    ArrayList* L;
} SparseMatrix;

- 10×10 행렬 구조 유지  
- ArrayList 포인터로 데이터 관리


- 10×10 행렬 생성
- 0이 아닌 원소 20개 초기화


int transpose(SparseMatrix* A, SparseMatrix* B);

- (r, c, v) → (c, r, v) 변환  
- 열 기준 순회로 정렬된 전치 수행  
- 데이터 이동 횟수 계산


- 전치 과정에서 복사된 원소 개수 카운트

void printMatrix(SparseMatrix* A);

- (row, col, value) 형태로 출력
실행 결과 예시

--- 희소행렬 전치 실행 ---
행렬 크기: 10 x 10  
0이 아닌 원소 수: 20  
데이터 이동 횟수: 20  

--- 희소행렬 ---
(출력 데이터)
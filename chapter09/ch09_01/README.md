
- main.c : 프로그램 실행 및 테스트 코드
- arrayList.c : 순차 리스트 구현 (realloc 포함)
- arrayList.h : 구조체 및 함수 선언

 기본 기능
- 리스트 생성 (createArrayList)
- 리스트 삭제 (destroyArrayList)
- 공백/포화 상태 확인
- 크기 반환

 리스트 연산
- 삽입 (insertArrayList)
- 삭제 (deleteArrayList)
- 조회 (getItemArrayList)
- 값 변경 (replaceItemArrayList)
- 출력 (printArrayList)

 핵심 구현 (realloc 기능)

리스트가 가득 찼을 경우 자동으로 크기를 2배로 확장한다.

 동작 방식
1. 현재 capacity 확인
2. full 상태이면 realloc 실행
3. 새로운 메모리 영역으로 확장
4. 기존 데이터 유지
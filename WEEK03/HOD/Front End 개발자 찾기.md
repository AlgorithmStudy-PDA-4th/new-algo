SkillCodes 테이블에서 관리되는 CODE 컬럼을 이용해서

DEVELOPERS 테이블에서 FrontEnd 스택을 가진 사람을 찾자

1. 서브쿼리를 사용해서 SkillCODES 에 존재하는 프론트 스택 별로 한번씩
   CODE 값을 찾아서 DEVELOPERS 테이블에서 조회한다.

이 문제에서 제시한 이진수를 어떻게 생각해야할까?

1. 뭔가 정수 값을 이진수로 변환하고 AND 연산하는게 가능할 것 같다.

```java
SELECT *
FROM table1 t1
JOIN table2 t2
ON (BIN(t1.integer_column1) & BIN(t2.integer_column2)) > 0;

```

시도해보자

```java
SELECT DISTINCT(d.ID),d.EMAIL,d.FIRST_NAME,d.LAST_NAME
FROM SKILLCODES sc
JOIN DEVELOPERS d
ON (BIN (sc.code) & BIN(d.skill_code) ) > 0
ORDER BY d.ID ASC;
```

중복도 제거하고 이진수로 AND 현산한걸 했는데 안나온다

생각해보니까 당연하네?
이건 Front만을 골라서 한건 아니니까 ㅋㅋ

### 그럼 프론트를 골라보자

```java
SELECT DISTINCT(d.ID),d.EMAIL,d.FIRST_NAME,d.LAST_NAME
FROM SKILLCODES sc
JOIN DEVELOPERS d
ON (BIN (sc.code) & BIN(d.skill_code) ) > 0
WHERE sc.code IN (
    SELECT CODE
    FROM SKILLCODES sc
    WHERE sc.CATEGORY Like "Front End"
)
ORDER BY d.ID ASC;
```

두둥 진짜 이번엔 성공할 줄 알았는데 안된다.

아래처럼 수정하니까 됐다

```java
SELECT DISTINCT(d.ID),d.EMAIL,d.FIRST_NAME,d.LAST_NAME
FROM SKILLCODES sc
JOIN DEVELOPERS d
ON (sc.code & d.skill_code ) > 0
WHERE sc.code IN (
    SELECT CODE
    FROM SKILLCODES sc
    WHERE sc.CATEGORY Like "Front End"
)
ORDER BY d.ID ASC;
```

`BIN` 함수를 사용하면 이진수를 문자열로 만들기 때문에 결과가 틀려진다고한다.

이 풀이를 해보고 생각해보니 서브쿼리를 사용하지 않아도 되지 않을까 생각했다.

### 최종

```java
SELECT DISTINCT(d.ID),d.EMAIL,d.FIRST_NAME,d.LAST_NAME
FROM SKILLCODES sc
JOIN DEVELOPERS d
ON ((sc.code) & (d.skill_code)) > 0
WHERE sc.CATEGORY = "Front End"
ORDER BY d.ID ASC;
```

`DISTINCT` 는 중간에 한번씩 실행하면서 테스트하다가 중복이 나오길래 추가했다.
```SQL
SELECT DISTINCT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS
WHERE SKILL_CODE &
      (SELECT SUM(CODE)
      FROM SKILLCODES
      WHERE CATEGORY = 'Front End')
ORDER BY ID ASC
```

& 연산자를 사용해서 비트가 일치함을 확인한다.
join 연산을 사용하지 않아도 문제가 풀림..

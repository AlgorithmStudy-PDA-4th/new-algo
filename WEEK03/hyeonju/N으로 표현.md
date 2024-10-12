```python
from itertools import product

def solution(N, number):
    dp = [set() for _ in range(9)]

    if N == number:
        return 1
    else:
        dp[1].add(N)

    for i in range(2,9):
        dp[i].add(int(str(N)*i))
        for j in range(1,i):
            for x,y in product(dp[j],dp[i-j]):
                dp[i].update({x+y,x-y,x*y})
                if y != 0:
                    dp[i].add(x//y)
        if number in dp[i]:
            return i
    return -1
```

`N은 1 이상 9 이하입니다.` 라는 제한사항에 따라 dp 배열을 초기화한다.(배열의 요소가 set인 형태)
`dp[1].add(N)` 은 N을 1번 사용하면 N이 나온다. 라는 뜻.

`for i in range(2,9)` 에서 i는 N이 사용된 횟수이다. 이미 1번 사용은 끝이 났기 때문에 2부터 시작한다.
우선 사용횟수만큼의 연속된 수가 저장된다.
예를 들어, N이 5인데 2번 사용됐다면 dp[2]에는 55가 일단 저장되는 것이다.
그 다음에는 반복문을 돌면서 중복순열로 사칙연산을 수행한다.
만약 사칙연산을 수행한 결과에 number가 존재하면 그 즉시 사용횟수(i)를 리턴한다.
모든 반복문이 끝났음에도 number가 나오지 않았다면(사용횟수가 8회를 넘었다면) -1을 리턴한다.

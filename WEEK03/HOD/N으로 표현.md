```java
import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = 0;
        ArrayList<Set<Integer>> dp = new ArrayList<>(10);
        
        for(int i = 0 ; i < 9; i++) {
            dp.add(new HashSet<>());
        }
        
        //최솟값이 8보다 크면 -1 반환
        for(int i = 1; i < 9; i++) {
            StringBuilder sb = new StringBuilder();
            
            for (int j = 0; j < i; j++) {
                sb.append(String.valueOf(N));
            }
            
            String curN = sb.toString();
            
            dp.get(i).add(Integer.parseInt(curN));
            
            // 현재 개수
            for(int j = 1; j < i; j++) {
                // dp 배열에 있는 값은 다 꺼내야지?
                for(int a : dp.get(j)) {
                    for(int b : dp.get(i-j)) {
                        dp.get(i).add(a + b);
                        dp.get(i).add(a - b);
                        dp.get(i).add(a * b);
                        if( b != 0){
                         dp.get(i).add(a / b);
                        }
                        
                    }
                }
            }
            
            if(dp.get(i).contains(number)) {
                return i;
            }
            
            
        }
        return -1;
    }
}
```

**ArrayList에 기록하는 숫자를 Set으로 관리하니까 성능 개선 가능.**
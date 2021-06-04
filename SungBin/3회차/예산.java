import java.util.*;

class Solution {
    // 10 : 12 3분
    /*
    * 풀이 방식 : 오름차순 정렬 후 가장 작은 값부터 예산을 빼면서 카운트 한다.
    */
  
    public int solution(int[] d, int budget) {
        Arrays.sort(d);
        int ans = 0;
        
        for(int i = 0; i < d.length; i++){
            if(budget < d[i]) break;
            budget -= d[i];
            ans++;
        }
        
        return ans;
    }
}

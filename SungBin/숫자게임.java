import java.util.*;

class Solution {
    
    // 30min 95.2점 45min 100점
    
    public int solution(int[] A, int[] B) {
        Arrays.sort(A);
        Arrays.sort(B);

        int aIndex = 0;
        int bIndex = 0;
        int cnt = 0;
            
        while(bIndex < B.length - 1){
            
            while(A[aIndex] >= B[bIndex] && bIndex < B.length - 1){
                bIndex++;
            }
            
            if(A[aIndex] < B[bIndex] && bIndex < B.length - 1){
                aIndex++;
                bIndex++;
                cnt++;
            }
        }
        
        if(A[aIndex] < B[bIndex]) cnt++;
        
        return cnt;
    }
}

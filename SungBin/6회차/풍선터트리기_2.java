import java.util.*;

class Solution {
    //6 : 27 30
    
    public int solution(int[] a) {
        int answer = (a.length > 1) ? 2 : 1;
        int[] leftMin = new int[a.length];
        int index = 2;
        int[] rightMin = new int[a.length];
        
        leftMin[0] = a[0];
        for(int i = 1; i < a.length; i++){
            leftMin[i] = Math.min(a[i], leftMin[i-1]);
        }
        
        rightMin[a.length - 1] = a[a.length - 1];
        for(int i = a.length - 2; i >= 0; i--){
            rightMin[i] = Math.min(a[i], rightMin[i+1]);
        }
        
        for(int i = 1; i < a.length - 1; i++){
            int num = a[i];
            
            if((num == leftMin[i] || num == rightMin[i])) {
                answer++;
            }
        }
        
        return answer;
    }
}

import java.util.*;

class Solution {
    // 13 : 06  12min
    
    static boolean[] isPrime;
    static int cnt;
    
    public int solution(int[] nums) {
        isPrime = new boolean[3000];
        
        for(int i = 2; i < isPrime.length; i++){
            if(isPrime[i] == true) continue;
            
            isPrime[i] = false;
            for(int j = i + i; j < isPrime.length; j += i){
                isPrime[j] = true;
            }
        }
        
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length; i++){
            for(int j = i + 1; j < nums.length; j++){
                for(int k = j + 1; k < nums.length; k++){
                    if(!isPrime[nums[i] + nums[j] + nums[k]]) cnt++;
                }
            }
        }
        
        return cnt;
        
    }
}

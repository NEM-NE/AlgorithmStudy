import java.util.*;

class Solution {
    // 15 : 20 9min
    public int solution(int[] nums) {
        int size = nums.length / 2 - 1;
        int cnt = 1;
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length-1; i++){
            if(size == 0) break;
            if(nums[i] != nums[i+1]){
                size--;
                cnt++;
            }
        }
        
        return cnt;
    }
}

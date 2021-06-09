import java.util.*;

class Solution {
    //  04 : 49
    
    public long solution(int w, int h) {
        long ans = 0;
        for(int i = 0; i < w; i++){
            ans += ((long)h * i)/(long)w;
        }

        return ans * 2;
    }
}

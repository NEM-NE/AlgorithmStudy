import java.util.*;

public class Solution {
    // 15 : 05 18min 60점
    
    static int battery;
    
    public int solution(int n) {
        battery = 0;

        while(n != 0){
            if(n%2 == 0){
                n /= 2;
            }else {
                n--;
                battery++;
            }
        }
        
        return battery;
    }
}

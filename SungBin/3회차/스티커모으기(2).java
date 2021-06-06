class Solution {
    // 10:15 50분 98.2 점 64분 100점
    /*
    dp문제
    [0~sticker.length-1]
    [1~sticker.length-1] 인 경우로 나눠서 최댓값을 구함.
    */
    
    static int cal(int[] ary, int start, int end){
        if(start >= ary.length) return 0;
        if(end < 0) return 0;
        
        int[] dp = new int[ary.length];
        
        dp[start] = ary[start];
        if(end - start >= 2) dp[start+1] = ary[start + 1];
        if(end - start >= 3) dp[start+2] = ary[start + 2] + ary[start];
        
        for(int i = start + 3; i <= end; i++){
            dp[i] = Math.max(dp[i-2], dp[i-3]) + ary[i];
        }
        
        int max = 0;
        for(int i = start; i <= end; i++){
            if(max < dp[i]) max = dp[i];
        }
        
        return max;
    }
    
    public int solution(int sticker[]) {
        
        int ans = Math.max(cal(sticker, 0, sticker.length-2), cal(sticker, 1, sticker.length-1));
        if(sticker.length == 1) ans = sticker[0];
        
        return ans;
    }
}

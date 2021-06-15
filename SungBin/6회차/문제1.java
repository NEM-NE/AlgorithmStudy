class Solution {
  /*
    피보나치 수를 구하라
    단 fibo(n)값을 1234567로 나눈 나머지 값을 출력해라
  */
  
  
    static long[] dp;
    
    public long solution(int n) {
        long answer = 0;
        
        dp = new long[n+1];
        
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= 1234567;
        }
        
        answer = dp[n];
        
        return answer;
    }
}

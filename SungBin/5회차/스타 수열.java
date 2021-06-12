class Solution {
    //1:14
    
    static int cnt;
    static int[] bag;
    
    static int cntStarSeq(int[] ary, int a, int b, int index){
        for(int i = index; i < ary.length; i++){
            for(int j = i+1; j < ary.length; j++){
                if(ary[i] == ary[j]) continue;      // 한 집합에 동일한 값들이 있을 수 없다.
                if(bag[0] == ary[i] || bag[0] == ary[j] // 교집합이 존재해야한다.
                   || bag[1] == ary[i] || bag[1] == ary[j]){
                    
                    System.out.println(ary[i] + " " + ary[j]);
                    return cntStarSeq(ary, ary[i], ary[j], j) + 2;  // 재귀
                }
                
                
            }
        }
        
        return 0;
    }
    
    public int solution(int[] a) {
        bag = new int[2];
        cnt = 0;
        
        for(int i = 0; i < a.length; i++){
            for(int j = i+1; j < a.length; j++){
                if(a[i] == a[j]) continue;
                
                bag[0] = a[i];
                bag[1] = a[j];
                System.out.println(a[i] + " " + a[j] + "::::");
                cnt = Math.max(cnt, cntStarSeq(a, a[i], a[j], j) + 2);
                
                System.out.println("======");
            }
        }
        
        return cnt;
    }
}


class Solution {
    //1:14
    static int[] dp;
    
    public int solution(int[] a) {
        dp = new int[a.length];
        
        for(int i = 0; i < a.length; i++){
            if(a.length > 2) dp[i] = 2;
            else dp[i] = 0;
            
            int num = a[i];
            for(int j = 0; j < i; j++){
                if(num == a[j] && j+1 != i){
                    dp[i] = Math.max(dp[j] + 2, dp[i]);
                }
            }
        }
        
        int max = 0;
        for(int i = 0; i < dp.length; i++){
            if(max < dp[i]) max = dp[i];
        }
        
        return max;
    }
}

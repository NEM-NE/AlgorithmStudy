class Solution {
    // 10 : 17 
    
    public int solution(int n, int[] stations, int w) {
        int cnt = 0;
        int index = 0;
        int pos = 1;

        while(pos <= n){
            
            if(index < stations.length && pos >= stations[index] - w){
                pos = stations[index] + w + 1;
                index++;
            }else {
                pos += 2 * w + 1;
                cnt++;
            }
        }
        
        
        return cnt;
    }
}

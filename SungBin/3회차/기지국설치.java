class Solution {
    // 10 : 05 
    /*
    이미 설치된 기지국 제외하고 아닌 구역들을 구한다.
    그리고 이분 탐색을 통해 값을 구한다.
    해당 범위를 구하는 것이 어려움
    */
    
    static boolean[] apt;
    
    static int countTower(int min, int max, int w){
        if(min == max) return 1;
        else if(min > max) return 0;
        
        int mid = (min + max) / 2;
        int cnt = countTower(min, mid - w - 1, w) + countTower(mid + w + 1, max, w) + 1;
        
        return cnt;
    }
    
    public int solution(int n, int[] stations, int w) {
        int cnt = 0;
        apt = new boolean[n+1];
        
        for(int i = 0; i < stations.length; i++){
            int num = stations[i] - w;
            for(int j = num; j < num + 2 * w; j++){
                apt[j] = true;
            }
        }
        int start = 1;
        int end = n;
        if(apt[1]) {
            start = 2 + w;
            cnt++;
        }
        
        if(apt[n]) {
            end = n - w - 1;
            cnt++;
        }
        
        int min = start;
        for(int i = start; i <= end; i++){
            if(apt[i] && min == i){
                cnt += countTower(min, i-1, w);
                min = 2 * w + 1;
            }
        }
        
        return cnt;
    }
}

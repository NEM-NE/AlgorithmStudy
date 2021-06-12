class Solution {
    //11:18  9분
    
    static int[] ans;
    
    static boolean check(int[][] arr, int size, int xStart, int yStart){
        int temp = arr[yStart][xStart];
        
        for(int i = yStart; i < yStart + size; i++){
            for(int j = xStart; j < xStart + size; j++){
                if(arr[i][j] != temp) return false;
            }
        }
        
        return true;
    }
    
    static void partition(int[][] arr, int size, int xStart, int yStart){
        if(check(arr, size, xStart, yStart)){   // 해당 영역 값이 다 같을 경우
            ans[arr[yStart][xStart]]++;
            return; 
        }
        
        int newSize = size/2;
        
        partition(arr, newSize, xStart, yStart);
        partition(arr, newSize, xStart + newSize, yStart);
        
        partition(arr, newSize, xStart, yStart + newSize);
        partition(arr, newSize, xStart + newSize, yStart + newSize);
    }
    
    public int[] solution(int[][] arr) {
        ans = new int[2];
        
        partition(arr, arr.length, 0, 0);
        
        return ans;
    }
}

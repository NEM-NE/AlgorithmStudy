import java.util.*;

class Solution {
  /*
    그냥 노가다 구현으로 푼 문제
    삼각형을 반복적으로 그리는 걸 구현함
  */
    
    static int[][] list;
    
    static void partition(int size, int num, int xIdx, int yIdx){
        int n = num;
        
        for(int i = yIdx; i < yIdx+size; i++){
            list[i][xIdx] = n++;
        }
        
        for(int i = xIdx+1; i < xIdx + size; i++){
            list[size + yIdx - 1][i] = n++;
        }
        
        int x = xIdx + size - 2; 
        for(int i = yIdx + size - 2; i > yIdx; i--){
            list[i][x--] = n++;
        }
        
        if(size > 3) partition(size - 3, n, xIdx+1, yIdx+2);
        else return;
    }
    
    public int[] solution(int n) {
        list = new int[n+1][n+1];
        
        partition(n, 1, 1, 1);
        
        ArrayList<Integer>temp = new ArrayList<Integer>();
        for(int i = 1; i < list.length; i++){
            for(int j = 1; j < n+1; j++){
                if(list[i][j] != 0) {
                    temp.add(list[i][j]);  
                }
            }
        }

        
        int size = (n * (n+1)) / 2;
        int[] ans = new int[size];
        for(int i = 0; i < ans.length; i++){
            ans[i] = temp.get(i);
        }
        
        return ans;
    }
}

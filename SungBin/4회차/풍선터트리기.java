import java.util.*;

class Solution {
    //6 : 27 30
    
    static ArrayList<Integer> list;
    
    static int getValue(int start, int end){
        int min = Integer.MAX_VALUE;
        
        for(int i = end; i >= start; i--){
            min = Math.min(min, list.get(i));
        }
        
        return min;
    }
    
    static boolean check(int num, int index){
        int left = 0;
        int right = 0;
        
        if(list.size() > 3){
            left = getValue(0, index - 1);
            right = getValue(index + 1, list.size() - 1);
        }else{
            left = list.get(0);
            right = list.get(2);
        }
        
        if(num > left && num > right) return false;
        else return true;
    }
    
    public int solution(int[] a) {
        int answer = 0;
        
        list = new ArrayList<Integer>();
        
        for(int j = 0; j < a.length; j++){
            list.add(a[j]);
        }
        
        for(int i = 0; i < a.length; i++){
            
            if(check(a[i], i)) {
                answer++;
                System.out.println(a[i]);
            }
        }
        
        return answer;
    }
}

class Solution
{
    // 10 : 11 sol : 12 min 60점 0점
    public int solution(String s)
    { 
        int answer = -1;
        String str = s;
        
        boolean flag = true;
        while(flag){
            flag = false;
            
            for(int i = 0; i < str.length()-1; i++){
                if(str.charAt(i) == str.charAt(i+1)){
                    str = str.substring(0, i) + str.substring(i+2, str.length());
                    flag = true;
                    break;
                }
            }
            
            
        }
        
        
        if(str.length() == 0) answer = 1;
        else answer = 0;
        
        return answer;
    }
}

import java.util.*;

class Solution
{
    // 10 : 11 sol : 12 min 30점 5점
    public int solution(String s)
    { 
        LinkedList<Character> list = new LinkedList<Character>();
        
        for(int i = 0; i < s.length(); i++){
            list.add(s.charAt(i));
        }

        boolean flag = true;
        while(flag){
            flag = false;
            
            for(int i = 0; i < list.size()-1; i++){
                if(list.get(i) == list.get(i+1)){
                    list.remove(i+1);
                    list.remove(i);
                    flag = true;
                    break;
                }
            }    
        }
        
        if(list.size() == 0) return 1;
        else return 0;

    }
}

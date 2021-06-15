import java.util.*;

/*

문자열 s가 주어짐 Ex)  "[]{}()"

왼쪽으로 문자열 중 맨앞에 있는 문자를 뒤로 보냄 단, 문자열 길이수 만큼 반복
여기서 괄호가 성립하는 횟수를 출력하시오.

*/

class Solution {
    static Stack<Character> stack;
    
    static boolean cal(String s){
        if(s.length() % 2 != 0) return false;
        
        stack = new Stack<Character>();
        
        for(int i = 0; i < s.length(); i++){
            char cur = s.charAt(i);
            
            if(cur =='{' || cur == '[' || cur == '('){
                stack.push(cur);
            }else {
                if(stack.isEmpty()) return false;
                char pre = stack.peek();
                
                if((pre == '{' && cur =='}') || (pre == '(' && cur ==')') || (pre == '[' && cur ==']')) {
                    stack.pop();
                }else return false;
                
            }
        }
    
        
        return true;
    }
    
    public int solution(String s) {
        int answer = 0;
        
        if(cal(s)) answer++;
        for(int i = 0; i < s.length()-1; i++){
            s = s.substring(1, s.length()) + s.charAt(0);
            if(cal(s)) answer++;
        }
        
        return answer;
    }
}

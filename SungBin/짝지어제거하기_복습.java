import java.util.*;

class Solution
{
    static Stack<Character> stack;
    
    // 16 : 10 sol : 12 min
    public int solution(String s)
    { 
        stack = new Stack<Character>();
        stack.push(s.charAt(0));
        
        for(int i = 1; i < s.length(); i++){
            char b = s.charAt(i);
            
            if(!stack.empty() && stack.peek() == b){
                if(stack.size() == 1) stack.clear();
                else stack.pop();
                
            }else stack.push(b);
        }
            
        
        return (stack.isEmpty()) ? 1 : 0;
    }
}

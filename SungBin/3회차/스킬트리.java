class Solution {
    // 11 : 29 43min
    /*
      스킬트리 중 일부만 해도 된다는 걸 모르고 풀어서 오래걸린 문제
      Stirng 내부 메서드를 많이 사용했음.
      
      먼저 스킬트리 하나씩 뽑아 검사
      검사 방식은 스킬 트리 내용 중 스킬에 포함되는 문자를 찾음
      이후 인덱스를 비교하여 검사함.
    */
  
  
    static boolean check(String skill, String str){
        int index = 0;
        for(int i = 0; i < skill.length(); i++){
            if(str.contains(skill.charAt(i) + "")){
                int num = str.indexOf(skill.charAt(i));
                
                if(index == num) index++;
                else return false;
            }
        }
        
        return true;
    }
    
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        
        for(int i = 0; i < skill_trees.length; i++){
            if(check(skill_trees[i], skill)) {
                answer++;
            }
        }
        
        return answer;
    }
}

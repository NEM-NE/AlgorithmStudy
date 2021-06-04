class Solution {
    // 10 : 18 49분 90점 58분 100점
    /*
      객체 지향적 풀이로 푼 문제(사실 그냥 풀걸 후회됨)
      처음에 예제를 보고 문자열들이 이어지는 지 확인 후 중복 단어 찾기 인줄 알았는데 사실 순서 상관없이 최소 값을 찾으라고 함... ㅎㅎㅎ
      
      그래서 문제 내용대로 중복단어 찾기 & 문자열 배열 내용들이 이어지는지 확인 함.
    */
    static int isConnected(String[] words){
        
        for(int i = 1; i < words.length; i++){
            if(words[i].charAt(0) != words[i-1].charAt(words[i-1].length() - 1)){
                return i;
            }
        }
        
        return -1;
    }
    
    static int findDupli(int n, String[] words){
        
        for(int i = 0; i < words.length; i++){
            for(int j = 0; j < i; j++){
                if(words[i].equals(words[j])){
                    return i;
                }
            }
        }   
        
        return -1;
    }
    
    static int[] findFailer(int n, String[] words){
        int[] ans = {0, 0};
        int connectNum = (isConnected(words) == -1) ? Integer.MAX_VALUE : isConnected(words);  
        int dupliNum = (findDupli(n, words) == -1) ? Integer.MAX_VALUE : findDupli(n, words);
        
        int num = Math.min(connectNum, dupliNum);
        
        if(num != Integer.MAX_VALUE){  // 중복된 단어가 있을시 해당 인덱스에 따른 [번호, 차례]구하기
            ans[0] = ((num + 1) % n == 0) ? n : (num + 1) % n;  
            ans[1] = (num + 1 - ans[0]) / n + 1;
        }
        
        // 없으면 [0, 0] 리턴
                      
        return ans;
    }
    
    public int[] solution(int n, String[] words) {
        int[] answer = findFailer(n, words);

        return answer;
    }
}

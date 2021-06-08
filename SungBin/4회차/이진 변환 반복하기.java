class Solution {
    //10 : 36 44분
    
    static int cnt;
    static int zeroNum;
    
    static String convertBinary(int num){
        String ans = "";

        while(num > 0){
            ans = num%2 + ans;
            num /= 2;
        }
        
        return ans;
    }
    
    static int deleteZero(String str){
        int size = 0;
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '0'){
                size++;
            }
        }

        zeroNum += size;
        return str.length() - size;
    }
    
    public int[] solution(String s) {
        int[] answer = {};
        String str = s;
        cnt = 0;
        zeroNum = 0;
        
        while(!str.equals("1")){
            cnt++;
            int num = deleteZero(str);
            str = convertBinary(num);
        }
        
        return new int[] {cnt, zeroNum};
    }
}

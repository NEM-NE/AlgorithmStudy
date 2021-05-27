class Solution
{
    static int size;
    static int[] ary;
    static boolean findValue(int a, int b, int min, int max){
        boolean isA = false;
        boolean isB = false;
        
            for(int i = min; i <= max; i++){
                if(ary[i] == a) isA = true;
                if(ary[i] == b) isB = true;
            }
        
        return (isA && isB) ? true : false;
    }
    
    public int solution(int n, int a, int b)
    {
        size = 0;
        int num = n;
        
        while(num != 1){
            num /= 2;
            size++;
        }
        
        ary = new int[n];
        for(int i = 0; i < ary.length; i++){
            ary[i] = i+1;
        }
        
        int max = ary.length - 1;
        int min = 0;
        
        while((min + 1) < max){
            int mid = (max + min) / 2;
            
            boolean left = findValue(a, b, min, mid);
            boolean right = findValue(a, b, mid+1, max);
            
            if(left && !right) {
                size--;
                max = mid;
            }else if(!left && right) {
                size--;
                min = mid + 1;
            }else break;
        }
        
        return size;
    }
}

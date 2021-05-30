class Solution {
    // 15 : 33 못품..
    static boolean[][][] visited;
    static int x, y, cnt;
    
    public int solution(String dirs) {
        visited = new boolean[11][11][4];  // UDRL
        x = 5;
        y = 5;
        cnt = 0;
        
        for(int i = 0; i < dirs.length(); i++){
            char a = dirs.charAt(i);
            
            if(a == 'U'){
                if(y >= 10) continue; 
                y++;
                
                if(!visited[y][x][0]){
                    visited[y][x][0] = true;
                    cnt++;
                }
            }else if(a == 'D'){
                if(y <= 0) continue; 
                y--;
                
                if(!visited[y][x][1]){
                    visited[y][x][1] = true;
                    cnt++;
                }
            }else if(a == 'R'){
                if(x >= 10) continue; 
                x++;
                
                if(!visited[y][x][2]){
                    visited[y][x][2] = true;
                    cnt++;
                }
            }else if(a == 'L'){
                if(x <= 0) continue; 
                x--;
                
                if(!visited[y][x][3]){
                    visited[y][x][3] = true;
                    cnt++;
                }
            }
            
        }
        
        return cnt;
    }
}

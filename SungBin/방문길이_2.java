class Solution {
    // 15 : 33
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
                if(y > 9) continue; 
                y++;
                
                if(!visited[y-1][x][0]){
                    visited[y-1][x][0] = true;
                    visited[y][x][1] = true;
                    cnt++;
                }
            }else if(a == 'D'){
                if(y < 1) continue; 
                y--;
                
                if(!visited[y+1][x][1]){
                    visited[y][x][0] = true;
                    visited[y+1][x][1] = true;
                    cnt++;
                }
            }else if(a == 'R'){
                if(x > 9) continue; 
                x++;
                
                if(!visited[y][x-1][2]){
                    visited[y][x-1][2] = true;
                    visited[y][x][3] = true;
                    cnt++;
                }
            }else if(a == 'L'){
                if(x < 1) continue; 
                x--;
                
                if(!visited[y][x+1][3]){
                    visited[y][x][2] = true;
                    visited[y][x+1][3] = true;
                    cnt++;
                }
            }
            
        }
        
        return cnt;
    }
}

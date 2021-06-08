import java.util.*;

/*
재귀 + bfs로 풀려고 한 문제...
bfs 인접행렬 방식에서 심각한 메모리 초과가 나와서 틀린 문제
재귀는 맞는 거 같은데 대각선 처리를 어떻게 해야할지 모르겠음.
*/

class Solution {
    //  04 : 49
    static class Point{
        int x, y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    static int cnt;
    
    static int cal(int w, int h){
        // init
        boolean[][] visited = new boolean[h+1][w+1];
        int[][] maps = new int[h+1][w+1];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};
        int count = 0;
        
        // bfs
        Queue<Point> que = new LinkedList<Point>();
        que.offer(new Point(1, 1));
        visited[1][1] = true;
        
        while(!que.isEmpty()){
            int size = que.size();
            
            for(int j = 0; j < size; j++){
                Point point = que.poll();
                
                for(int i = 0; i < 4; i++){
                    int xx = point.x + dx[i];
                    int yy = point.y + dy[i];

                    if(xx <= 0 || xx > w || yy <= 0 || yy > h) continue;
                    if(!visited[yy][xx]){
                        visited[yy][xx] = true;
                        que.offer(new Point(xx, yy));
                    }
                }   
            }
            
            count++;
            
        }
        return count;
        
    }
    
    static int partition(int w, int h){
        cnt++;
        
        if(w%2 != 0 || h%2 != 0){
            return cnt * cal(w, h);
        }
        
        return partition(w/2, h/2);
    }
    
    public long solution(int w, int h) {
        cnt = 1;
        
        int ans = (w != h) ? partition(w, h) : w;

        return (w * h) - ans;
    }
}

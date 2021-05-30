import java.util.*;

class Solution {
    // 13 : 20 50점 20 min
    static int cnt;
    static int[][] maps;
    static boolean[][] visited;
    static int[] dist;
    
    static void bfs(int x, int y){
        Queue<Integer> que = new LinkedList<Integer>();
        que.offer(x);
        visited[x][y] = true;
        visited[y][x] = true;
        
        while(!que.isEmpty()){
            int num = que.poll();
            
            for(int i = 1; i < maps[num].length; i++){
                if(maps[num][i] != 0 && !visited[num][i]){
                    que.offer(i);
                    visited[num][i] = true;
                    visited[i][num] = true;
                    dist[i] = Math.min(dist[i], dist[num] + maps[num][i]);
                }
                
            }
        }
    }
    
    
    public int solution(int N, int[][] road, int K) {
        maps = new int[N+1][N+1];
        visited = new boolean[N+1][N+1];
        dist = new int[N+1];
        cnt = 0;
        
        for(int i = 2; i < dist.length; i++){
            dist[i] = Integer.MAX_VALUE;
        }
        
        for(int i = 0; i < road.length; i++){
            int a = road[i][0];
            int b = road[i][1];
            int time = road[i][2];
            
            // 중복 길 중 최단 시간만 남기기.
            if(maps[a][b] != 0 && maps[b][a] != 0){
                maps[a][b] = Math.min(maps[a][b], time);
                maps[b][a] = Math.min(maps[b][a], time);
            }else{
                maps[a][b] = time;
                maps[b][a] = time;
            }
        }
        
        bfs(1, 1);
        
        for(int i = 1; i < dist.length; i++){
            if(K >= dist[i]) {
                System.out.println(i + " : " + dist[i]);
                cnt++;
            }
        }
        
        return cnt;
    }
    
}

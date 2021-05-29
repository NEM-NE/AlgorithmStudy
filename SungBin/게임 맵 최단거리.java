import java.util.*;

class Solution {
    // 15 : 32 32min
    static class Node{
        int x, y;
        
        public Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    static int[][] visited;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};
    static int cnt;
    
    static void bfs(int x, int y, int[][] maps){
        Queue<Node> que = new LinkedList<Node>();
        que.offer(new Node(x, y));
        visited[y][x] = 1;
        
        while(!que.isEmpty()){
                Node node = que.poll();
                for(int i = 0; i < 4; i++){
                    int xx = node.x + dx[i];
                    int yy = node.y + dy[i];
                
                    if(xx < 0 || xx >= visited[0].length || yy < 0 || yy >= visited.length) continue;
                    if(visited[yy][xx] == 0 && maps[yy][xx] == 1){
                        que.offer(new Node(xx, yy));
                        visited[yy][xx] = visited[node.y][node.x] + 1;
                    }
                }       
            
            
        }
    }
    
    public int solution(int[][] maps) {
        visited = new int[maps.length][maps[0].length];
        bfs(0, 0, maps);
        
        return (visited[maps.length-1][maps[0].length-1] != 0) ? visited[maps.length-1][maps[0].length-1] : -1;
    }
}

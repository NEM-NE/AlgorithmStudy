#include<vector>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

int solution(vector<vector<int> > maps)
{
    int m=maps[0].size();
    int n=maps.size()/m;

    int dis[100][100];

    memset(dis,0,sizeof(dis));
    queue<pair<int,int>> q;
    
    q.push(make_pair(0,0));
  
    dis[0][0]=1;
    
    while(!q.empty())
    {
        pair<int,int> curp=q.front();
        q.pop();
        int y=curp.first;
        int x=curp.second;
        
 
        
        for(int i=0;i<4;i++)
        {
            int yy=y+dy[i];
            int xx=x+dx[i];
            if(yy>=0&&xx>=0&&yy<n&&xx<m)
            {
                if(maps[yy][xx]==1&&dis[yy][xx]==0)
                {
                q.push(make_pair(yy,xx));
                dis[yy][xx]=dis[y][x]+1;
                }
            }
                
            
        }
        
        
    }
    if(dis[n-1][m-1]==0)
        return -1;
    else 
        return dis[n-1][m-1];
    

    
}

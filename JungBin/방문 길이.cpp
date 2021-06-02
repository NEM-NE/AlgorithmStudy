#include <string>
#include<utility>
#include<cstring>
using namespace std;

int map[11][11][5];//map[0][0]==(-5,-5)
//U->1,R->2,D->3,L->4;
  int x=5;
  int y=5;
int solution(string dirs) {
    int answer = 0;

    memset(map,0,sizeof(map));
    for(int i=0;i<dirs.size();i++)
    {
        if(dirs[i]=='U')
        {
        if(y+1>10)
     continue;
            
        if(map[y][x][1]!=0)
        {
          y++;
          continue;
        }
            map[y][x][1]=1;
            y++;
            answer++;
            map[y][x][3]=1;
        }
        else if(dirs[i]=='D')
        {       
            if(y-1<0)
                continue;
            if(map[y][x][3]!=0)
            {y--;
                continue;
            }
            map[y][x][3]=1;
    
            y--;
             answer++;
            map[y][x][1]=1;
        }
        else if(dirs[i]=='R')
        {            if(x+1>10)
                continue;
        if(map[y][x][2]!=0)
        {x++;
                continue;
        }
            map[y][x][2]=1;

            x++;
             answer++;
            map[y][x][4]=1;
        }
        else if(dirs[i]=='L')
        {            if(x-1<0)
                continue;
        if(map[y][x][4]!=0)
        {x--;
                continue;
        }
            map[y][x][4]=1;

            x--;
             answer++;
            map[y][x][2]=1;
        }
    }
    return answer;
}

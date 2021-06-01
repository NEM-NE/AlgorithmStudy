//첫 번째 시도 보자 마자 kruskal's algorithm 으로 mst를 찾아야 겠다는 생각이듦
//그런데 kruskal's algo를 쓰면 mst 만 얻고 distance 는 또 다시 1 노드부터 탐색해야함-> 비효율적
// 그래서 prim's algorithm을 구현함
#include <iostream>
#include <vector>
#include<queue>
#include<utility>
#include<cstring>
#include<limits>
#include<utility>
#include<unordered_map>

using namespace std;
int infi=numeric_limits<int>::max();
int dis[51];
int pre[51];

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

unordered_map<int,vector<pair<int,int>>> neighbors;



int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    memset(dis,infi,sizeof(dis));
    dis[1]=0;
    for(int i=0;i<road.size();i++)
    {
     pair<int,int> edge0=make_pair(road[i][0],road[i][2]);
     pair<int,int> edge1=make_pair(road[i][1],road[i][2]);
                                        //unordered_map 에서 []operator를 사용 할 때 조심스러움          
        if(!neighbors.count(road[i][0]))//unordered_map 에서 만약에 road[i][0]이 애초에 존재하지 않으면 새로 만들어 줘야 하는 줄 알고 해놨는데 굳이 그럴 필요 없음
        {
            vector<pair<int,int>> v;
            neighbors[road[i][0]]=v;
            }
        if(!neighbors.count(road[i][1]))
        {
            vector<pair<int,int>> v;
            neighbors[road[i][1]]=v;
            }
        neighbors[road[i][0]].push_back(edge1);
        neighbors[road[i][1]].push_back(edge0);
    }
    
    for(int i=1;i<=N;i++)
    {
    int& a=dis[i];
    pq.push(make_pair(i,a));
    }
    
    for(int i=0;i<N;i++)
    {
        int vertex=pq.top().first;
        pq.pop();
        for(auto neighbor : neighbors[vertex])
        {
            if(neighbor.second<dis[neighbor.first])
            {
                dis[neighbor.first]=neighbor.second;
                pre[neighbor.first]=vertex;
            }
        }
    }
    
 for(int i=1;i<=N;i++)
 {
     if(dis[i]<=K)
         answer++;
 }
    return answer;
}
// 다 구현 하고 보니 굳이 MST에 포함 되어 있지 않은 edge도 가능함;;
//아 그럼 weight가 존재하는 BFS로 

#include <iostream>
#include <vector>
#include<queue>
#include<utility>
#include<cstring>
#include<limits>
#include<utility>
#include<unordered_map>
#include<limits>
using namespace std;

int dis[51];

unordered_map<int,vector<pair<int,int>>> neighbors;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    memset(dis,500001,sizeof(dis));
    dis[1]=0;
    for(int i=0;i<road.size()-1;i++)
    {
  
     pair<int,int> edge0=make_pair(road[i][0],road[i][2]);
     pair<int,int> edge1=make_pair(road[i][1],road[i][2]);
        neighbors[road[i][0]].push_back(edge1);
        neighbors[road[i][1]].push_back(edge0);
    }
    
queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
    
        for(auto neighbor : neighbors[cur])
        {
            if(dis[cur]+neighbor.second<dis[neighbor.first])
            {
                q.push(neighbor.first);
                dis[neighbor.first]=dis[cur]+neighbor.second;
                }
        }
    }
    for(int i=1;i<=N;i++)
    {
   if(dis[i]<=K)
            answer++;
    }
    return answer;
}

#include <iostream>
#include <vector>
#include<queue>
#include<utility>
#include<cstring>
#include<limits>
#include<utility>
#include<unordered_map>
#include<limits>
using namespace std;

int dis[51];

unordered_map<int,vector<pair<int,int>>> neighbors;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    memset(dis,500000,sizeof(dis));
    dis[1]=0;
    for(int i=0;i<road.size();i++)
    {
  
     pair<int,int> edge0=make_pair(road[i][0],road[i][2]);
     pair<int,int> edge1=make_pair(road[i][1],road[i][2]);
        neighbors[road[i][0]].push_back(edge1);
        neighbors[road[i][1]].push_back(edge0);
    }
    
queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
    
        for(auto neighbor : neighbors[cur])
        {
            if(dis[cur]+neighbor.second<dis[neighbor.first])
            {
                q.push(neighbor.first);
                dis[neighbor.first]=dis[cur]+neighbor.second;
                }
        }
    }
    for(int i=1;i<=N;i++)
    {
   if(dis[i]<=K)
            answer++;
    }
    return answer;
}

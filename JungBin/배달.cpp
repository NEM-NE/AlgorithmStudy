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
        if(!neighbors.count(road[i][0]))
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

unordered_map<int,vector<pair<int,int>>> neighbors;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    memset(dis,infi,sizeof(dis));
    dis[1]=0;
    for(int i=0;i<road.size()-1;i++)
    {
     pair<int,int> edge0=make_pair(road[i][0],road[i][2]);
     pair<int,int> edge1=make_pair(road[i][1],road[i][2]);
        if(!neighbors.count(road[i][0]))
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
    
queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(dis[cur]<=K)
            answer++;
        
        for(auto neighbor : neighbors[cur])
        {
            if(dis[cur]+neighbor.second<dis[neighbor.first])
            {
                q.push(neighbor.first);
                dis[neighbor.first]=dis[cur]+neighbor.second;
                }
        }
    }
    
    return answer;
}

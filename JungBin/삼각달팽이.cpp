#include <string>
#include <vector>
#include<cstring>
#include<iostream>
using namespace std;
int arr[1001][1001];

void fillin(int y,int x,int N, int start)
{
    for(int i=y;i<y+N;i++)
    {
        arr[i][x]=start;
        start++;
    }
    for(int i=x+1;i<x+N;i++)
    {
        arr[y+N-1][i]=start;
        start++;
    }
    for(int i=1;i<=N-2;i++)
    {
        arr[y+N-1-i][x+N-1-i]=start;
        start++;
    }
    if(N==1||N==2||N==3)
        return;
    else
        fillin(y+2,x+1,N-3,start);
    
}

vector<int> solution(int n) {
    vector<int> answer;
   fillin(1,1,n,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            answer.push_back(arr[i][j]);
    }

    return answer;
}

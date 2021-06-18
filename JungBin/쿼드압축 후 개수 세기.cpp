#include<iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> v;
vector<int> answer;
void check(int y,int x, int n)
{
    int standard=v[y][x];
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(standard!=v[y+i][x+j])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag)
    {
        n/=2;
        check(y,x,n);
        check(y+n,x,n);
        check(y,x+n,n);
        check(y+n,x+n,n);
    }
    else{
        answer[standard]++;
        return;
    }
}
vector<int> solution(vector<vector<int>> arr) {
    v=arr;
answer.push_back(0);
    answer.push_back(0);
    check(0,0,v.size());

    return answer;
}

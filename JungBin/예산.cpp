#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
int findmaxdepartment(vector<int> topick,int budget)
{
    if(budget<=0)
        return 0;
    
    if(topick.empty())
        return 0;
    
    int Max=-1;
    
    for(int i=0;i<topick.size();i++)
    {
        if(topick[i]<=budget)
        {
        vector<int> newv=topick;
        newv.erase(newv.begin()+i);
     Max=max(Max,findmaxdepartment(newv,budget-topick[i])+1);  
        }
    }
    return Max;
}

int solution(vector<int> d, int budget) {
return findmaxdepartment(d,budget);
}


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
int solution(vector<int> d, int budget) {
sort(d.begin(),d.end(),cmp);
int cnt=0;
    while(budget>0)
{
    budget-=d.back();
        d.pop_back();
    cnt++;
}
    
    if(budget==0)
    return cnt;
    else
        return cnt-1;
}

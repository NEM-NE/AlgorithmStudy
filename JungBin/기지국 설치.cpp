#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

int minstations(int n,int w)
{
    int a=2*w+1;
  return n%a==0 ? n/a : (n/a)+1; 
}


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
int arr[n+1];
   memset(arr,0,sizeof(arr));
    for(int i=0;i<stations.size();i++)
    {
    for(int j=stations[i]-w;j<=stations[i]+w;j++)
    {if(j<=n)
        arr[j]=1;
    }
    }
    
    bool connected=0;
    if(arr[1]==1)
   connected=1;
    
    int length=0;
    for(int i=1;i<=n;i++)
    {
        if(connected==1)
        {
            if(arr[i]==1)
                continue;
            else{
                length=1;
                connected=0;
            }
        }
        else
        {
            if(arr[i]==0)
                length++;
            else
            {
                answer+=minstations(length,w);
                connected=1;
                length=0;
            }
        }
    }
   answer+=minstations(length,w);
    return answer;
}

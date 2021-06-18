#include <iostream>
#include <vector>
using namespace std;
int dp[100000][2];
int dp2[100000][2];
int solution(vector<int> sticker)
{
    int n=sticker.size();
    int answer =0;

    if(n==1)
    answer=sticker[0];
    else if(n==2)
answer=max(sticker[0],sticker[1]);
    else{
          //case 1  
        dp[2][0]=0;
        dp[2][1]=sticker[2];
        //case2
        dp2[1][0]=0;
        dp2[1][1]=sticker[1];
         dp2[2][0]=max(dp2[1][0],dp2[1][1]);
           dp2[2][1]=dp2[1][0]+sticker[2];
        for(int i=3;i<=n-2;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+sticker[i];
            dp2[i][0]=max(dp2[i-1][0],dp2[i-1][1]);
            dp2[i][1]=dp2[i-1][0]+sticker[i];
        }
        dp2[n-1][0]=max(dp2[n-2][0],dp2[n-2][1]);
        dp2[n-1][1]=dp2[n-2][0]+sticker[n-1];
        
        int case1=max(dp[n-2][0],dp[n-2][1]);
        int case2=max(dp2[n-1][0],dp2[n-1][1]);
        answer=max(case1+sticker[0],case2);
    }
    

    return answer;
}

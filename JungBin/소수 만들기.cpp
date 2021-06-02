#include <vector>
#include <iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;
unordered_set<int> primeset;
void make_prime_set(int n)
{
int arr[n+1];
memset(arr,0,sizeof(arr));
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==0)
        {
            primeset.insert(i);
            for(int j=2;j*i<=n;j++)
                    arr[i*j]=1;
        }
    }
    return;
}

int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.begin(),nums.end());
    int maxsum=nums[nums.size()-1]+nums[nums.size()-2]+nums[nums.size()-3];
    make_prime_set(maxsum);
    int n=nums.size();
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int h=j+1;h<n;h++)
            {
                if(primeset.count(nums[i]+nums[j]+nums[h]))
                    answer++;
}
        }
    }
    
    return answer;
}

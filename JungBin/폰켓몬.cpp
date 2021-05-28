#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(),nums.end());
    
    int index=0;
    int before=nums[0];
    answer++;
    
    while(answer!=nums.size()/2)
    {
     index++;
        
    if(index>=nums.size())
            break;
        
     if(before==nums[index])
         continue;
    
        before=nums[index];
        answer++;
    }
    
    
    return answer;
}

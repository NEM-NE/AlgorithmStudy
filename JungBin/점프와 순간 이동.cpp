#include <iostream>

using namespace std;

int leastbattery(int n)
{
    if(n==0)
        return 0;
    if(n%2==0)
        return leastbattery(n/2);
    else if(n%2==1)
        return leastbattery((n-1)/2)+1;
}
int solution(int n)
{
    int ans = 0;
    ans=leastbattery(n);
    return ans;
}

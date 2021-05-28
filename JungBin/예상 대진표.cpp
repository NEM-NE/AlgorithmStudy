#include <iostream>

using namespace std;
int findpower(int n)
{
int cnt=0;
    while(n!=1)
    {
        n/=2;
        cnt++;
    }
    return cnt;
}
int solution(int n, int a, int b)
{
if(n==2)
    return 1;
    
 if(a<=n/2&&b>n/2)
     return findpower(n);
else if(b<=n/2&&a>n/2)
    return findpower(n);
else
{
    if(a>n/2&&b>n/2)
        return solution(n/2,a-n/2,b-n/2);
    else
        return solution(n/2,a,b);
}
    
    
}

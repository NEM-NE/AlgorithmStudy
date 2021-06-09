#include<iostream>
using namespace std;

long long gcd(int a, int b)
{
    if(min(a,b)==0)
        return max(a,b);
    return gcd(max(a,b)%min(a,b),min(a,b));
}

long long solution(int w,int h) {
    long long w1=w;
    long long h1=h;
 unsigned long long answer = w1*h1;
    long long Gcd=gcd(w,h);
    long long ww=w/Gcd;
    long long hh=h/Gcd;

answer-=Gcd*((ww-1)+(hh-1)+1);

    return answer;
}

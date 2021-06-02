#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    
if(s.size()%2==1)
    return 0;
    
     stack<char> mystack;
    mystack.push(s[0]); 
    
for(int i=1;i<s.size();i++)
{
    if(!mystack.empty()&&mystack.top()==s[i])
        mystack.pop();
    else
    mystack.push(s[i]);
}
    
if(mystack.empty())
    answer=1;
else
    answer=0;
    
    return answer;
}

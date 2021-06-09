#include <string>
#include <vector>
#include<iostream>
using namespace std;

string tobinary(int a)
{
    string binary;
    while(a!=0)
    {
    binary+= a%2 ? '1' : '0';
        a/=2;
    }
    return binary;
}
void binary_transition(string s,vector<int>& answer)
{
    if(s=="1")
        return;
    
    answer[0]++;

    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='0')
        {
            answer[1]++;
            s.erase(s.begin()+i);
        }
    }
    binary_transition(tobinary(s.size()),answer);
    
}
vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    binary_transition(s,answer);
    //cout<<tobinary(15)<<endl;
    return answer;
}

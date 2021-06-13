#include <string>
#include<unordered_set>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//일단 다중집합을 만든다.
//자카드 유사도를 조사한다.
int size1=0;
unordered_set<string> set1;
vector<string> vector2;
unordered_map<string,int> map1;
unordered_map<string,int> map2;
unordered_set<string> myset;
bool is_alphabet(char s)
{
    int a=int(s);
    if(a>=65&&a<=90)
        return true;
    else if(a>=97&&a<=122)
        return true;
    else
        return false;
}
float find_jacad()
{
    int cnt=0;
    for(int i=0;i<vector2.size();i++)
    {
        if(!myset.count(vector2[i])&&!set1.empty()&&set1.count(vector2[i]))
        {
            myset.insert(vector2[i]);

            cnt+=min(map1[vector2[i]],map2[vector2[i]]);
        }
    }
   float answer=float(cnt)/(size1+vector2.size()-cnt);
    return answer;
}
int solution(string str1, string str2) {
    int answer = 0;
    for(int i=0;i<str1.size()-1;i++)
    {
        string s="he";
         s[0]=str1[i];
         s[1]=str1[i+1];
        if(is_alphabet(s[0])&&is_alphabet(s[1]))
        {
           if(s[0]>=65&&s[0]<=90)
               s[0]+=32;
         if(s[1]>=65&&s[1]<=90)
               s[1]+=32;

            size1++;
        set1.insert(s);
            if(map1.count(s)==0)
                map1[s]=1;
            else
                map1[s]++;
        }
    }

        for(int i=0;i<str2.size()-1;i++)
    {
        string s="he";
         s[0]=str2[i];
         s[1]=str2[i+1];
        if(is_alphabet(s[0])&&is_alphabet(s[1]))
        {
         if(s[0]>=65&&s[0]<=90)
               s[0]+=32;
         if(s[1]>=65&&s[1]<=90)
               s[1]+=32;

            vector2.push_back(s);
                        if(map2.count(s)==0)
                map2[s]=1;
            else
                map2[s]++;
        }
    }
cout<<set1.size()<<endl;
    cout<<vector2.size()<<endl;
if(size1+vector2.size()==0)
    return 65536;

    answer=find_jacad()*65536;

    return answer;
}

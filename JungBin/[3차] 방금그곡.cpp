#include <string>
#include <vector>
#include<utility>
#include<iostream>
using namespace std;

//일단은 musicinfos를 좀 가공하기 쉽게 만들어야한다
//우선 전체 음악악보를 만들고 그에 해당하는 제목을 같이 저장하는 데이터 구조를 만들어야한다
//어떤 구조가 가장 효율적일까? --->pair<string,string>을 벡터에다 저장해서 하나씩 탐색하는게 좋을것 같다.
//각 악보를 탐색하며 m이 포함 돼있는지 아닌지 판단한다.
//없으면 none출력, 하나면 제목 출력, 두개 이상이면 길이 순으로, 길이가 같으면 먼저 나온 순으로 출력한다.
   vector<pair<string,string>> mv;
pair<string,string> process_music(string s){
    int runningtime=0;
    string name, sheet;
    runningtime-=(((s[0]-'0')*10)+s[1]-'0')-(((s[6]-'0')*10)+s[7]-'0');
    runningtime*=60;
    runningtime-=(((s[3]-'0')*10)+s[4]-'0')-(((s[9]-'0')*10)+s[10]-'0');
    s.erase(s.begin(),s.begin()+12);
    char a=s[0];
    while(a!=',')
    {
        name.push_back(a);
        s.erase(s.begin());
        a=s[0];   
    }
      s.erase(s.begin());
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='#')
        {
            s[i-1]=s[i-1]+' ';
            s.erase(s.begin()+i);
        }
    }
    for(int i=0;i<runningtime;i++)
    {
        sheet.push_back(s[i%s.size()]);
    }
    pair<string,string> p=make_pair(name,sheet);
    return   p;
      
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    for(int i=0;i<musicinfos.size();i++)
    mv.push_back(process_music(musicinfos[i]));
        for(int i=0;i<m.size();i++)
    {
        if(m[i]=='#')
        {
            m[i-1]=m[i-1]+' ';
            m.erase(m.begin()+i);
        }
    }
    int answerindex=-1;
    for(int i=0;i<mv.size();i++)
    {
        string name=mv[i].first;
        string sheet=mv[i].second;
    if(sheet.find(m)!=string::npos)
    {
        if(answerindex!=-1)//처음 찾은게 아님
        {
            if(mv[answerindex].second.size()<sheet.size())
                answerindex=i;     
        }
        else
            answerindex=i;
    }
    }
    if(answerindex==-1)
        return answer="(None)";
    else
        return answer=mv[answerindex].first;
}

#include <string>
#include <vector>
#include<cstring>
#include <iostream>
#include<unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> myset;
int arr[n+1];
    memset(arr,0,sizeof(arr));
    char pre=words[0][words[0].size()-1];
    int cur=0;
    arr[cur]++; 
    myset.insert(words[0]);

    bool flag=0;
    for(int i=1;i<words.size();i++)
    {
      cur=i%n; arr[cur]++;
        if(words[i][0]!=pre)
        {
            flag=1;
            break;
        }
        if(myset.count(words[i]))
        { 
            flag=1;
            break;
        }
        pre=words[i][words[i].size()-1];
        myset.insert(words[i]);
}
    if(flag==1){
        answer.push_back(cur+1);
        answer.push_back(arr[cur]);
    }
    else
    {
            answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

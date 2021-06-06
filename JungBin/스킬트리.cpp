#include <string>
#include <vector>
#include<unordered_set>
using namespace std;
bool ispos(vector<char> skill_v,unordered_set<char> skill_set, string skill_tree)
{
    for(int i=0;i<skill_tree.size();i++)
    {
        char cur=skill_tree[i];
        if(skill_set.count(cur))
        {
            if(skill_v.back()==cur)
                skill_v.pop_back();
            else
                return false;
        }
         
    }
           return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> skill_v;
    unordered_set<char> skill_set;
    for(int i=skill.size()-1;i>=0;i--)
    {
        skill_v.push_back(skill[i]);
        skill_set.insert(skill[i]);
    }
    
for(int i=0;i<skill_trees.size();i++)
{
    string skill_tree=skill_trees[i];
    if(ispos(skill_v,skill_set,skill_tree))
        answer++;
}
    return answer;
}

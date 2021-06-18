#include <string>
#include <vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;
//교집합의 원소가 1개이상
//교집합의 원소가 2개가 되면 어떻게 될까?
//교집합의 원소가 2개 라는건 집합이 같거나 순서만 다르다는 의미 ex) 1,2,2,1 아니면 1,2,1,2
//교집합의 원소가 2개인 경우는 교집합의 원소가 1개인 경우에 포합되어 있기 때문에 굳이 따로 볼 필요가 없다
//교집합의 원소가 2개인 스타수열 보다 1개인 스타 수열이 짧을 수가 없다.
//그렇다면 교집합의 원소가 1개인 스타수열만 찾는 다는 의미인데 이럴때 그 교집합의 원소를 고정 시켜놓고 스타 수열을 구하는 방법이 있다.
//무작위로 수열을 만들어 놓고 is_star_sequence 를 하는 것보단 당연히 합리적이다
//수열을 탑색해서 각 원소가 몇번 등장하는 지 저장 한다.
//unordered_map,vector<pair<int,int>> 가능
//-----------------원소가 몇번 등장하는지 저장하는 방법 --------------------------------------------------
//가장 많이 등장하는 원소를 파악 해야 하므로 vector<pair<int,int>> 를 사용해서 sort를 쓰는게 좋을것 같다
//vector<pair<int,int>> 보다 maximumheap 가 좀더 효율 적일 수도? 
//priorityheap 과 vector<pair<int,int>> 를 둘다 사용해보고 비교해보자.
//vector나 priorityheap을 사용하면 a를 탑색할 때 매우 복잡해진다. 어떤 원소를 탐색하면 그 원소가 vetor에 들어 있는지 없는지
//탐색을 해야 하기 때문에 매우 복잡하다.
//unordered_map을 사용하면 매우 간편해 진다. 
//결론->unordred_map을 이용해서 데이터를 받고, priorityheap을 이용해서 집어는다.
//-------------------------------------------------------------------------------------------------
// 가장 많이 등장하는 원소 부터 만들 수 있는 제일 긴 스타 수열을 만든다.
//longest star sequence
//일단 n의 뒤원소와 함께 짝을 맞춘다
// 만약 뒤원소가 n이여서 사용했다면 앞원소를 사용한다
//앞원소가 n이라면 사용 불가능
// 만약 지금까지 탐색한 원소로 만든 제일 긴 스타 수열의 길이 나누기 2보다 덜 혹은 같은 횟수로 등장하는 원소부터는 탐색 안한다.
class cmp{
    public:
    bool operator()(pair<int,int> p1,pair<int,int>p2){
        return p1.second <p2.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
unordered_map<int,int> mymap;

int longest_star_s(int n,vector<int>& a)
{

    int cnt=0;
    int pre=-1;
    for(int i=0;i<a.size();i++)
    {
    if(a[i]==n&&pre+1==i&&i<a.size()-1)
    {
        if(a[i+1]!=n){
        cnt++;
        pre=i+1;
        }
        else if(a[i+1]==n)
            pre=i;
    }

    if(a[i]==n&&pre+1<i)
    {
        cnt++;
        pre=i;
    }
   

    }

    return cnt*2;
}
int solution(vector<int> a) {
    int answer = -1;
    for(int i=0;i<a.size();i++)
    {
        if(!mymap.count(a[i]))
           mymap[a[i]]=1;
        else
           mymap[a[i]]++;
    }
    
    for(auto elem : mymap)
        pq.push(elem);
    
    int Max=longest_star_s(pq.top().first,a);
    pq.pop();
  
    while(!pq.empty()&&Max<pq.top().second*2)
    {
    Max=max(Max,longest_star_s(pq.top().first,a));
    pq.pop();
    }
    answer=Max;
      
    return answer;
}

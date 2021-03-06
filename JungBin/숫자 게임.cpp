#include <string>
#include <vector>
#include<cstring>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
if(A.empty())
return 0;
    
    for(int i=0;i<B.size();i++)
    {
    vector<int> C=B;
    C.erase(C.begin()+i);
    if(A.back()<B[i])
    {
    A.pop_back();
    answer=max(answer,solution(A,C)+1);
    }
    else
    {
    A.pop_back();
    answer=max(answer,solution(A,C));
    }
    }
    return answer;
}

#include <string>
#include <vector>
#include<cstring>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
sort(A.begin(),A.end());
sort(B.begin(),B.end());
    int MAX=0;
    for(int i=0;i<A.size();i++)
    {
        int cnt=0;
      for(int i=0;i<A.size();i++)
      {
          if(A[i]<B[i])
              cnt++;
      }
        MAX=max(MAX,cnt);
        A.push_back(A.front());
        A.erase(A.begin());
    }
    return MAX;
}

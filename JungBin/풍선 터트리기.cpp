#include <string>
#include <vector>
#include <queue>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    answer+=2;
    int leftmin=a[0];
    int rightmin=*min_element(a.begin()+2,a.end());

    for(int i=1;i<a.size()-1;i++)
    {
        if(leftmin>a[i]||rightmin>a[i])
        answer++;
        
        leftmin=min(a[i],leftmin);
    
        
        if(rightmin==a[i+1])
            rightmin=*min_element(a.begin()+i+2,a.end());
    }
    

    return answer;
}

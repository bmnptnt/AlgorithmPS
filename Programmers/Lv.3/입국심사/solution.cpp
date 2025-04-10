#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    ll left, right, mid;
    ll done=0;
    sort(times.begin(),times.end());
    
    left=1;
    right = (ll)n*(ll)times.back();
    
    while(left<=right)
    {
        done=0;
        mid=(left+right)/2;
        for(int time : times)
        {
            done+=mid/(ll)time;
        }
        
        if(done>=n)
        {
            right=mid-1;
            answer=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    
    return answer;
}

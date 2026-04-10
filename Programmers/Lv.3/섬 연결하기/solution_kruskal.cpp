#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[105] = {0};

int find(int x)
{
    if(parent[x]==x)return x;
    else return parent[x] = find(parent[x]);
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b)
         {
             return a[2]<b[2];
         });
    
    int a, b;
    
    for(vector tmp : costs)
    {
        a = find(tmp[0]);
        b = find(tmp[1]);
        if(a!=b)
        {
            answer+=tmp[2];
            parent[b] = a;
        }
    }
    
    
    return answer;
}

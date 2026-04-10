#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>


using namespace std;
int visit[20005] = {0}; 
int cost[20005] = {0};
using tu = array<int,2>; // cost, node

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> connect(n+1);
    for(int i=1;i<n+1;i++)
    {
        cost[i] = 987654321;
    }
    for(vector tmp : edge)
    {
        connect[tmp[0]].push_back(tmp[1]);
        connect[tmp[1]].push_back(tmp[0]);
    }
    
    queue<int> bfs;
    visit[1] = 1;
    cost[1] = 0;
    bfs.push(1);
    int out;
    
    vector<int> cntMax;
    
    while(bfs.size())
    {
        out = bfs.front();
        bfs.pop();
        for(int in : connect[out])
        {
            if(!visit[in] && cost[out]+1<cost[in])
            {
                cost[in] = cost[out] + 1;
                visit[in] = 1;
                bfs.push(in);
                cntMax.push_back(cost[in]);
            }
        }
    }
    
    sort(cntMax.begin(), cntMax.end(), greater<int>());
    answer = 1;
    for(int i=1;i<cntMax.size();i++)
    {
        if(cntMax[i]==cntMax[0]) ++answer;
    }
    
    return answer;
}

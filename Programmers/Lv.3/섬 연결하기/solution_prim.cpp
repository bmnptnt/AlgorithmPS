#include <string>
#include <vector>
#include <queue>
#include <array>

using namespace std;
using tu = array<int,2>; // {cost, node}

int visit[105] = {0};
int connect[105][105] = {0};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(vector tmp : costs)
    {
        connect[tmp[0]][tmp[1]] = tmp[2];
        connect[tmp[1]][tmp[0]] = tmp[2];
    }
    
    priority_queue<tu, vector<tu>, greater<tu>> heap;
    
    tu in, out;
    in[0] = 0;
    in[1] = costs[0][0];
    visit[costs[0][0]] = 0;
    heap.push(in);
    while(heap.size())
    {
        out = heap.top();
        heap.pop();
        if(visit[out[1]]) continue;
        answer += out[0];
        visit[out[1]] = 1;
        
        for(int i=0;i<n;i++)
        {
            if(!visit[i]&&connect[out[1]][i])
            {
                in[0] = connect[out[1]][i];
                in[1] = i;
                heap.push(in);
            }
        }
        
    }
    
    return answer;
}

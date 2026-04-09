#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int connect[105][105] = {0};
int visit[105] = {0};

int solution(int n, vector<vector<int>> wires) {
    int answer = 105;
    
    for(vector tmp : wires)
    {
        connect[tmp[0]][tmp[1]] = 1;
        connect[tmp[1]][tmp[0]] = 1;
    }
    
    vector<int> stk;
    int in, out;
    
    for(vector tmp : wires)
    {
        int root = tmp[0];
        int nCnt = 1;

        connect[tmp[0]][tmp[1]] = 0;
        connect[tmp[1]][tmp[0]] = 0;
        
        memset(visit, 0, sizeof(visit));
        
        visit[root] = 1;
        stk.push_back(root);
        
        while(stk.size())
        {
            out = stk.back();
            stk.pop_back();
            
            for(int i=1;i<=n;i++)
            {
                if(!visit[i]&&connect[out][i])
                {
                    visit[i] = 1;
                    nCnt++;
                    stk.push_back(i);
                }
            }
            
        }
        
        answer = min(answer, abs(nCnt-(n-nCnt)));
        connect[tmp[0]][tmp[1]] = 1;
        connect[tmp[1]][tmp[0]] = 1;
    }
    
    return answer;
}

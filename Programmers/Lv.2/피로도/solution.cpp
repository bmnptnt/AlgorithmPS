#include <vector>
#include <cstring>


using namespace std;
struct NODE
{
    int cnt = 0;
    int hp = 0;
    int visit[10] = {0};  
};

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int nDungeons = dungeons.size();
    vector<NODE> stk;

    NODE in, out;
    in.hp = k;
    in.cnt = 0;
    stk.push_back(in);
    while(stk.size())
    {
        out = stk.back();
        stk.pop_back();
        if(out.cnt > answer)answer = out.cnt;
        if(answer == nDungeons) return answer;
        if(out.hp<=0) continue;
            
        for(int j=0;j<nDungeons; j++)
        {
            if(out.visit[j]==0 && out.hp>=dungeons[j][0])
            {
                in.hp = out.hp - dungeons[j][1];
                in.cnt = out.cnt + 1;
                memcpy(in.visit, out.visit, sizeof(out.visit));
                in.visit[j] = 1;
                stk.push_back(in);
            }
        }
    }    
    
    return answer;
}

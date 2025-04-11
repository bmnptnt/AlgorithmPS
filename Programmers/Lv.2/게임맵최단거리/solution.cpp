#include<vector>
#include<array>
#include<queue>
using namespace std;
struct path{
  int y;
  int x;
  int dist;
};
int visited[101][101]={0};
int solution(vector<vector<int> > maps)
{
    int answer = 20000;
    int n=maps.size(), m=maps[0].size();
    queue<path> stack;
    path tmp, curr;
    
    tmp.y=0;
    tmp.x=0;
    tmp.dist=1;
    visited[0][0]=1;
    
    stack.push(tmp);
    
    while(stack.size())
    {
        curr=stack.front();
        stack.pop();
        
        if(curr.y==n-1&&curr.x==m-1&&
           curr.dist<answer) 
        {
            answer=curr.dist;
            continue;
        }
        
        for(int dy=-1; dy<2; dy++)
        {
            for(int dx=-1; dx<2; dx++)
            {
                if(dx*dy!=0)continue;
                if(curr.y+dy<0||curr.y+dy>=n)continue;
                if(curr.x+dx<0||curr.x+dx>=m)continue;
                
                if(maps[curr.y+dy][curr.x+dx]&&
                   !visited[curr.y+dy][curr.x+dx])
                {
                    tmp.y=curr.y+dy;
                    tmp.x=curr.x+dx;
                    tmp.dist=curr.dist+1;
                    visited[curr.y+dy][curr.x+dx]=1;
                    stack.push(tmp);
                }
                
            }
        }
    }

    if(answer==20000)answer=-1;
    
    return answer;
}

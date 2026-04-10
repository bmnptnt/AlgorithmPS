#include <string>
#include <vector>
#include <queue>

using namespace std;
struct NODE
{
    int nTask;
    int nStart;
    int nTime;
};
struct cmp
{
    bool operator()(const NODE& a, const NODE& b)
    {
        if(a.nTime!=b.nTime) return a.nTime > b.nTime;
        else if (a.nStart != b.nStart) return a.nStart > b.nStart;
        else return a.nTask > b.nTask;
    }
};
struct cmp2
{
    bool operator()(const NODE& a, const NODE& b)
    {
        return a.nStart > b.nStart;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<NODE, vector<NODE>, cmp> pq;
    priority_queue<NODE, vector<NODE>, cmp2> pq2;
    NODE tmp;
    for(int i=0;i<jobs.size();i++)
    {
        tmp.nTask = i;
        tmp.nStart = jobs[i][0];
        tmp.nTime = jobs[i][1];
        
        pq2.push(tmp);
    }
    
    int currTime = 0;
    
    while(pq.size()||pq2.size())
    {
        while(pq2.size() && pq2.top().nStart<=currTime)
        {
            tmp = pq2.top();
            pq2.pop();
            pq.push(tmp);
        }
        if(pq.size())
        {
            tmp = pq.top();
            pq.pop();
        
            currTime += tmp.nTime;
            answer+= (currTime - tmp.nStart);
        }
        else currTime = pq2.top().nStart;
    }    
    
    
    return answer/jobs.size();
}

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
int parent[202]={0};

int Find(int x)
{
    if(x==parent[x])return x;
    else return parent[x]=Find(parent[x]);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int A,B;
    unordered_set<int> cnt;
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(computers[i][j])
            {
                A=Find(i);
                B=Find(j);
                
                parent[B]=A;   
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        Find(i);
        cnt.insert(parent[i]);
    }
    answer=cnt.size();
    
    return answer;
}

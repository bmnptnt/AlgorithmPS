#include <iostream>
#include <string>
#include <vector>

using namespace std;
int town[105][105]={0};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    town[1][1]=1;
    for(vector<int> puddle : puddles)
    {
        town[puddle[1]][puddle[0]]=-1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(town[i][j]==-1)
            {
                town[i][j]=0;
            }
            else
            {
                town[i][j]=(town[i][j]+town[i-1][j]+town[i][j-1])%1000000007;
                
            }
        }
    }
    answer=town[n][m];
    
    return answer;
}

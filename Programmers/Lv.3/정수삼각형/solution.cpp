#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    for(int i=1;i<triangle.size();i++)
    {
        answer=-1;
        for(int j=0;j<triangle[i].size();j++)
        {
            if(j==0)
            {
                triangle[i][j]+=triangle[i-1][j];
            }
            else if(j==triangle[i].size()-1)
            {
                triangle[i][j]+=triangle[i-1][j-1];
            }
            else
            {
                triangle[i][j]+=max(triangle[i-1][j-1],triangle[i-1][j]);
            }
            if(triangle[i][j]>answer)answer=triangle[i][j];
        }
    }
    
    return answer;
}

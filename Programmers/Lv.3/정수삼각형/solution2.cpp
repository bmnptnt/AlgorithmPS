#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    for(int i=triangle.size()-1;i>=1;i--)
    {
        for(int j=0;j<triangle[i].size()-1;j++)
        {
            if(triangle[i][j]>triangle[i][j+1])
            {
                triangle[i-1][j]+=triangle[i][j];
            }
            else
            {
                triangle[i-1][j]+=triangle[i][j+1];
            }
        }
    }
    answer=triangle[0][0];
    return answer;
}

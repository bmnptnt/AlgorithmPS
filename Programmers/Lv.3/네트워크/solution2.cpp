#include <string>
#include <vector>

using namespace std;

int visited[202]={0};

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int curr;
    vector<int> stack;
    
    for(int i=0;i<n;i++)
    {   
        if(!visited[i])
        {
            stack.push_back(i);
            visited[i]=1;
            answer++;
        }
        
        while(stack.size())
        {
            curr=stack.back();
            stack.pop_back();
            for(int j=0;j<n;j++)
            {
                if(computers[curr][j]&&!visited[j])
                {
                    stack.push_back(j);
                    visited[j]=1;
                }
            }
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <unordered_set>

using namespace std;
struct SV{
    string st="";
    array<int,7> visited={0};
};
int prime[10000000]={0};
int solution(string numbers) {
    prime[0]=prime[1]=1;
    for(int i=2;i<=sqrt(10000000);i++)
    {
        if(prime[i])continue;
        for(int j=i*i;j<=10000000;j+=i)
        {
            prime[j]=1;
        }
    }
    
    int answer = 0;
    vector<SV> stack;
    unordered_set<int> foundPrime;
    
    for(int i=0;i<numbers.size();i++)
    {
        SV tmp, curr;
        tmp.st.push_back(numbers[i]);
        tmp.visited[i]=1;
        stack.push_back(tmp);

        while(stack.size())
        {
            curr=stack.back();
            stack.pop_back();

            if(!prime[stoi(curr.st)]) foundPrime.insert(stoi(curr.st));
            
            for(int j=0;j<numbers.size();j++)
            {   
                if(!curr.visited[j])
                {
                    tmp.st=curr.st;
                    tmp.st.push_back(numbers[j]);
                    
                    tmp.visited=curr.visited;
                    tmp.visited[j]=1;
                    
                    stack.push_back(tmp);
                }
            }
        }
    }
  
    answer=foundPrime.size();
    return answer;
}

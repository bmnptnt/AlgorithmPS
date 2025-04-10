#include <string>
#include <vector>
#include <array> 

using namespace std;
using tu=array<int,2>;


int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<tu> nums;
    vector<tu> myQ;
    tu curr;
    for(int number : numbers)
    {
        nums.push_back({-1*number,number});
    }
    myQ.push_back({-1,0});
    while(myQ.size())
    {
        curr=myQ.back();
        myQ.pop_back();

        if(curr[0]>=(int)numbers.size()-1)
        {
            if(curr[1]==target)answer++;
            continue;
        }
        
        for(int i=0;i<2;i++)
        {
            myQ.push_back({curr[0]+1,curr[1]+nums[curr[0]+1][i]});
        }
    }
    
    return answer;
}

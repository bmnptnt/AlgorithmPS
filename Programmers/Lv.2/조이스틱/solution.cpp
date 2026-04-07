#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    for(char c : name)
    {
        if(c<='N')answer+=(c-'A');
        else answer+=('Z'-c+1);
    }

    int next, cost = len - 1;
    for(int i=0;i<len;i++)
    {
        next = i+1;
        while(next<len && name[next] == 'A')
        {
            ++next;
        }
        cost = min(cost, i + len - next + min (i, len-next));
    }
    answer += cost;
    return answer;
}

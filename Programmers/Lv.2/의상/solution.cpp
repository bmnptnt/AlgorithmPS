#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> numCloth;
    
    for(vector<string> cloth : clothes)
    {
        if(numCloth[cloth[1]])numCloth[cloth[1]]++;
        else numCloth[cloth[1]]=2;
    }
    
    for(auto num : numCloth)
    {
        answer*=num.second;
    }
    
    return answer-1;
}

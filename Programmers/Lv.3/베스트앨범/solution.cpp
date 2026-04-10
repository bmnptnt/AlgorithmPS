#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
struct NODE
{
    string sGenre;
    int nMaxGenre;
    int nPlay;
    int nSong;
};
struct cmp
{
  bool operator()(const NODE &a, const NODE &b)
  {
      if(a.nMaxGenre != b.nMaxGenre) return a.nMaxGenre < b.nMaxGenre;
      else if (a.nPlay != b.nPlay) return a.nPlay < b.nPlay;
      else return a.nSong > b.nSong;
  }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int nSongs = genres.size();
    unordered_map<string, int> nGenrePlay;
    
    for(int i=0;i<nSongs;i++)
    {
        if(nGenrePlay.count(genres[i]))
        {
            nGenrePlay[genres[i]] += plays[i];
        }
        else
        {
            nGenrePlay[genres[i]] = plays[i];
        }
    }
    
    priority_queue<NODE, vector<NODE>, cmp> heap;
    
    NODE inp;
    
    for(int i=0;i<nSongs;i++)
    {
        inp.sGenre = genres[i];
        inp.nMaxGenre =  nGenrePlay[genres[i]];
        inp.nPlay = plays[i];
        inp.nSong = i;
        
        heap.push(inp);
    }
    
    unordered_map<string, int> nGenreCnt;
    NODE out;
    while(heap.size())
    {
        out = heap.top();
        heap.pop();
        
        if(nGenreCnt.count(out.sGenre)==0)
        {
            answer.push_back(out.nSong);
            nGenreCnt[out.sGenre] = 1;
        }
        else if (nGenreCnt[out.sGenre]<2)
        {
            answer.push_back(out.nSong);
            nGenreCnt[out.sGenre]++;
        }
        
    }
    
    return answer;
}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <vector>
#include <bitset>

using namespace std;
vector<int> relation[2010];


typedef struct State {
	int node;
	int level;
	bitset<2000> visit;

}State;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//clock_t start_t = clock();

	int N, M, a, b;
	int level = 1;

	bool findRelation = false;
	vector<State> stack;
	State curr;


	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		bitset<2000> init;
		init.set(i);
		level = 1;
		stack.push_back({ i,level, init });

		while (stack.size())
		{
			curr = stack.back();
			stack.pop_back();
			if (curr.level >= 5)
			{
				findRelation = true;
				break;
			}
			for (int rel : relation[curr.node])
			{
				if (!curr.visit[rel] && curr.level < 5)
				{
					bitset<2000> next_visit = curr.visit;
					next_visit.set(rel);
					stack.push_back({ rel,curr.level + 1,next_visit });
				}
			}
			if (findRelation) break;
		}
		if (findRelation) break;
	}
	cout << findRelation << "\n";

	//cout << "Elasped time : " << (double)(clock() - start_t) / CLOCKS_PER_SEC << "\n";
	return 0;
}

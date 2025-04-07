#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <queue>
#include <array>
#include <vector>
using namespace std;
using tu = array<int, 2>;

vector<vector<tu>> edges;
queue<tu> myQueue;
vector<int> visited;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	//clock_t start_t = clock();

	int V, src, dst, e;
	tu maxDist = { -1,-1 };

	cin >> V;
	edges.resize(V + 1);
	visited.resize(V + 1);

	for (int i = 0; i < V; i++)
	{
		cin >> src;
		visited[src] = 0;
		while (1)
		{
			cin >> dst;
			if (dst == -1)break;

			cin >> e;
			edges[src].push_back({ dst,e });
		}
	}

	tu curr;

	myQueue.push({ 1,0 });
	visited[1] = 1;
	while (myQueue.size())
	{
		curr = myQueue.front();
		myQueue.pop();
		if (curr[1] > maxDist[1])
		{
			maxDist[0] = curr[0];
			maxDist[1] = curr[1];
		}

		for (tu edge : edges[curr[0]])
		{
			if (visited[edge[0]] != 1)
			{
				myQueue.push({ edge[0],curr[1] + edge[1] });
				visited[edge[0]] = 1;
			}
		}
	}

	maxDist[1] = 0;
	myQueue.push({ maxDist[0],maxDist[1] });
	visited[maxDist[0]] = 2;
	while (myQueue.size())
	{
		curr = myQueue.front();
		myQueue.pop();
		if (curr[1] > maxDist[1])
		{
			maxDist[0] = curr[0];
			maxDist[1] = curr[1];
		}

		for (tu edge : edges[curr[0]])
		{
			if (visited[edge[0]] != 2)
			{
				myQueue.push({ edge[0],curr[1] + edge[1] });
				visited[edge[0]] = 2;
			}
		}
	}

	cout << maxDist[1] << "\n";
	//cout << "Elasped time : " << (double)(clock() - start_t) / CLOCKS_PER_SEC << "\n";
	return 0;
}
#include <iostream>
#include <time.h>
#include <queue>
#include <array>
#include <vector>
#include <cmath>
#define INF 987654321

using namespace std;
using tu = array<int, 2>;

tu house[50];
int dist[50][50] = { 0 };

int findDist(int i, int j, int k, int N)
{
	int ans = 0;
	for (int n = 0; n < N; n++)
	{
		ans = max(ans, min(min(dist[n][i], dist[n][j]), dist[n][k]));
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<tu> near;
	vector<tu> farCity;
	//freopen("input.txt", "r", stdin);
	//clock_t start_t = clock();

	int N, K, ans = INF;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> house[i][0] >> house[i][1];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			dist[i][j] = dist[j][i] = max(house[i][0], house[j][0]) - min(house[i][0], house[j][0]) + max(house[i][1], house[j][1]) - min(house[i][1], house[j][1]);
		}
	}

	if (K == 1)
	{
		for (int i = 0; i < N; i++)
		{
			ans = min(ans, findDist(i, i, i, N));
		}
	}
	else if (K == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ans = min(ans, findDist(i, i, j, N));
			}
		}
	}
	else if (K == 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					ans = min(ans, findDist(i, j, k, N));
				}
			}
		}
	}
	cout << ans << "\n";
	//cout << "Elasped time : " << (double)(clock() - start_t) / CLOCKS_PER_SEC << "\n";
	return 0;
}

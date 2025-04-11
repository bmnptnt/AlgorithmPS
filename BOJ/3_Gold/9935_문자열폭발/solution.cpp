#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//clock_t start_t = clock();

	string st, bomb, ans;

	cin >> st >> bomb;
	//ans.push_back(st[0]);
	for (char ch : st)
	{
		ans.push_back(ch);
		bool same = true;
		if (ans.back() == bomb.back() && ans.size() >= bomb.size())
		{
			for (int j = 0; j < bomb.size(); j++)
			{
				if (ans[ans.size() - j - 1] != bomb[bomb.size() - j - 1])
				{
					same = false;
					break;
				}
			}
			if (same)
			{
				for (int j = 0; j < bomb.size(); j++)
				{
					ans.pop_back();
				}
			}
		}
		
	}
	if (ans.size())cout << ans << "\n";
	else cout << "FRULA\n";
	

	//cout << "Elasped time : " << (double)(clock() - start_t) / CLOCKS_PER_SEC << "\n";
	return 0;
}

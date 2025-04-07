#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <array>
#include <algorithm>
using namespace std;
using tu = array<int, 2>;


bool isPrime(int num)
{
	for (int i = 2; i <= sqrt(num) + 1; i++)
	{
		if (num % i == 0)return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int level = 1;
	vector<int> primes;
	vector<tu> stack;
	tu curr;
	int singlePrimes[4] = { 2,3,5,7 }, odds[5] = { 1,3,5,7,9 };
	//freopen("input.txt", "r", stdin);

	//clock_t start_t = clock();
	cin >> N;

	for (int singlePrime : singlePrimes)
	{
		level = 1;
		stack.push_back({ singlePrime, level });

		while (stack.size())
		{
			curr = stack.back();
			stack.pop_back();

			if (curr[1] == N)
			{
				primes.push_back(curr[0]);
			}

			for (int odd : odds)
			{
				if (isPrime(curr[0] * 10 + odd) && curr[1] < N) {
					stack.push_back({ curr[0] * 10 + odd,curr[1] + 1 });
				}
			}
		}
	}
	sort(primes.begin(), primes.end());
	for (int prime : primes)
	{
		cout << prime << "\n";
	}

	//cout << "Elasped time : " << (double)(clock() - start_t) / CLOCKS_PER_SEC << "\n";
	return 0;
}
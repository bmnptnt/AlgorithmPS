#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
using namespace std;

#define MAX_NUM 10000001

int nums[MAX_NUM] = { 0 };

void findPrime(int maxNum)
{
	for (int i = 2; i <= sqrt(maxNum); i++)
	{
		if (nums[i] != 0)continue;

		for (int j = i * i; j <= maxNum; j = j + i)
		{
			nums[j] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	unsigned long long minNum, maxNum, temp;
	int count = 0;

	cin >> minNum >> maxNum;

	findPrime(sqrt(maxNum));

	for (int i = 2; i < sqrt(maxNum); i++)
	{
		if (!nums[i])
		{	
			temp = i;
			while (i <= maxNum / temp)
			{
				temp *= i;
				if (temp >= minNum) count += 1;
			}
		}
	}

	cout << count << "\n";

	return 0;
}

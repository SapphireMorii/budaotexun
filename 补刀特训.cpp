#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mget(int mgroup[], vector<int> numbers, int len)
{
	mgroup[0] = 0;
	mgroup[1] = numbers[0];
	for (int i = 0; i < len; ++i)
	{
		if (numbers[i] > mgroup[0])
		{
			mgroup[0] = numbers[i];
		}
		if (numbers[i] < mgroup[1])
		{
			mgroup[1] = numbers[i];
		}
	}
}
int isingroup(int number, vector<int>numbers)
{
	int result = 0;
	for (auto element : numbers)
	{
		if (number == element)
		{
			result = 1;
		}
	}
	return result;
}

int main()
{
	int n = 0, m = 0, groupm[2];
	cin >> n;
	cin >> m;
	vector<int>cnt(m);
	for (int i1 = 0; i1 < m; ++i1)
	{
		cnt[i1] = 0;
	}
	vector<int>group(n);
	for (int i2 = 0; i2 < n; ++i2)
	{
		cin >> group[i2];
	}

	mget(groupm, group, n);;
	for (int j = 0; j < m; ++j)
	{
		for (int k = groupm[1]; k < groupm[0] + 1; k += m)
		{
			if (isingroup(k, group))
			{
				++cnt[j];
			}
			else
			{
				k -= m - 1;
			}
		}
	}
	cout << maxget(cnt, m) << endl;
	return 0;
}
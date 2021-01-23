#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int dp[501][501];
	int test_case;
	int i, j;
	int sum = 0;

	cin >> test_case;



	for (i = 1; i <= test_case; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (i = 2; i <= test_case; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				dp[i][j] = dp[i][j] + dp[i - 1][j];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i][j] + dp[i - 1][j], dp[i][j] + dp[i - 1][j - 1]);
			}
		}
	}

	for (i = 1; i <= test_case; i++)
	{
		sum = max(sum, dp[test_case][i]);
	}

	cout << sum << endl;
}
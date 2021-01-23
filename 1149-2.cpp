#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int arr[1001][3];
	int dp[1001][3] = { 0 };

	int test_case;

	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < test_case; i++)
	{
		dp[i][0] += min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
		dp[i][1] += min(dp[i - 1][0],dp[i - 1][2]) + arr[i][1];
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	int sum = min(dp[test_case - 1][2], min(dp[test_case - 1][0], dp[test_case - 1][1]));
	cout << sum << endl;

}
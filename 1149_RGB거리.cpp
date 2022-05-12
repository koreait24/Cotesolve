#pragma warning (disable : 4996)

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int dp[1001][3] = { {0} };
	int cost[3];

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[1];
		dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + cost[2];
	}
	printf("%d\n", min(dp[N][2], min(dp[N][0], dp[N][1])));

	return 0;
}
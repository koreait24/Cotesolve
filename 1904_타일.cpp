#pragma warning (disable : 4996)

#include <stdio.h>
#include <unordered_map>

int Tile(int n, std::unordered_map<int, int>& DP);

int main()
{
	int output = 0, N = 0;
	std::unordered_map<int, int> DP;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		Tile(i, DP);
	}
	printf("%d\n", DP[N]);
	return 0;
}

int Tile(int n, std::unordered_map<int, int>& DP)
{
	if (DP.size() > 0 && DP.find(n) != DP.end()) {
		return DP[n];
	}

	if (n == 1) {
		DP[n] = 1;
		return DP[n];
	}

	if (n == 2) {
		DP[n] = 2;
		return DP[n];
	}

	DP[n] = (Tile(n - 1, DP) + Tile(n - 2, DP)) % 15746;
	return DP[n];
}
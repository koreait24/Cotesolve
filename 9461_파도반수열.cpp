#pragma warning (disable : 4996)

#include <stdio.h>
#include <unordered_map>
#include <vector>

long long P(int n, std::unordered_map<long long, long long>& DP);

int main()
{
	long long N, T;
	std::unordered_map<long long, long long> DP;
	std::vector<int> input;
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld", &N);
		input.push_back(N);
	}

	for (const auto& it : input) {
		for (int j = 1; j <= it; j++) {
			P(j, DP);
		}
		printf("%lld\n", DP[it]);
	}

	return 0;
}

long long P(int n, std::unordered_map<long long, long long>& DP)
{
	if (DP.find(n) != DP.end()) {
		return DP[n];
	}

	if (n <= 3) {
		DP[n] = 1;
		return DP[n];
	}

	if (n <= 5) {
		DP[n] = 2;
		return DP[n];
	}

	DP[n] = P(n - 2, DP) + P(n - 3, DP);
	return DP[n];
}
#pragma warning (disable : 4996)
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	long long K, N, Cable;
	long long max = 0, CableRemain = 0;
	vector<long long> CableVec;

	scanf("%lld %lld", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%lld", &Cable);
		CableVec.push_back(Cable);
		max = max < CableVec[i] ? CableVec[i] : max;
	}

	long long left = 1;
	long long right = max;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < CableVec.size(); i++) {
			if (mid != 0)
				sum += CableVec[i] / mid;
		}
		if (sum >= N) {
			if (CableRemain < mid)
				CableRemain = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%lld", CableRemain);
	return 0;
}
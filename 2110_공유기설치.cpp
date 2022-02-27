#pragma warning (disable : 4996)

#include <stdio.h>

int main()
{
	int N, C, Input;
	int X[200001];
	int max = 0, left = 1, right = 0;
	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Input);
		if (max < Input) max = Input;
		X[i] = Input;
	}

	right = max;

	int mid = 0;

	while (left <= right) {
		mid = left + right / 2;
		if (mid * C > max) {
			right = mid;
			left++;
		}
		else
			break;
	}

	printf("%d\n", mid);

	return 0;
}
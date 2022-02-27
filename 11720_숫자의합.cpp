#pragma warning (disable : 4996)

#include <stdio.h>

int main()
{
	int N, input, sum = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%1d", &input);
		sum += input;
	}

	printf("%d", sum);
	return 0;
}
#pragma warning(disable:4996)
#include <stdio.h>
#include <unordered_set>
using namespace std;

int main()
{

	int N, M, input;
	unordered_set<int> A;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		A.insert(input);
	}

	scanf("%d", &M);
	for (int j = 0; j < M; j++) {
		scanf("%d", &input);
		if (A.find(input) != A.end())
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
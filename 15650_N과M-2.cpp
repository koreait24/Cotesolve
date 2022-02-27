#pragma warning (disable : 4996)

#include <stdio.h>

int N, M;
int graph[9];
bool visit[9] = { false };
int arr[9];

void DFS(int n, int cnt)
{
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = n; i <= N; i++) {
		if (!visit[i]) {
			arr[cnt] = i;
			visit[i] = true;
			DFS(i + 1, cnt + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	DFS(1, 0);

	return 0;
}
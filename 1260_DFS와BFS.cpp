#pragma warning (disable : 4996)
#include <stdio.h>
#include <queue>

void DFS(int V);

void BFS(int V);

bool visit_dfs[10001] = { false };
bool visit_bfs[10001] = { false };

int Vertex[1001][1001] = {0};

int N, M, V, X, Y;
int main()
{
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &X, &Y);
		Vertex[X][Y] = 1;
		Vertex[Y][X] = 1;
	}

	DFS(V);
	printf("\n");
	BFS(V);
	printf("\n");

	return 0;
}

void DFS(int V)
{
	visit_dfs[V] = true;
	printf("%d ", V);
	for (int i = 1; i <= N; i++) {
		if (Vertex[V][i]) {
			if (!visit_dfs[i]) {
				visit_dfs[i] = true;
				DFS(i);
			}
		}
	}
}

void BFS(int V)
{
	std::queue<int> que;
	que.push(V);
	visit_bfs[V] = true;

	while (!que.empty()) {
		int first = que.front();
		que.pop();
		printf("%d ", first);

		for (int i = 1; i <= N; i++) {
			if (Vertex[first][i]) {
				if (!visit_bfs[i]) {
					visit_bfs[i] = true;
					que.push(i);
				}
			}
		}
	}
}
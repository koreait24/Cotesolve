#pragma warning (disable:4996)

#include<stdio.h>
#include<queue>

int		livtomato[2];
bool	visit[1001][1001] = { false };
int		MAP[1001][1001];
int		M, N, result = 0;
int		mx[4] = {0, 1, 0, -1};
int		my[4] = {-1, 0, 1, 0};
std::queue<std::pair<int, int>> que;

void BFS();

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input = 0;
			scanf("%d", &input);
			MAP[i][j] = input;
			if (input == 1) {
				que.push({ i, j });
				visit[i][j] = true;
			};
		}
	}

	BFS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 0) {
				printf("-1\n");
				return 0;
			}

			if (result < MAP[i][j]) {
				result = MAP[i][j];
			}
		}
	}

	printf("%d\n", result - 1);

	return 0;
}

void BFS()
{

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int iy = y + my[i];
			int ix = x + mx[i];
			if (iy < 0 || ix < 0 || iy >= N || ix >= M) continue;
			if (!visit[iy][ix] && MAP[iy][ix] == 0) {
				que.push({ iy, ix });
				MAP[iy][ix] = MAP[y][x] + 1;
				visit[iy][ix] = true;
			}
		}
	}
}
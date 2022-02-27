#pragma warning (disable:4996)

#include<stdio.h>
#include<queue>
#include<vector>

int		livtomato[2];
bool	visit[101][101][101] = {false};
int		MAP[101][101][101];
int		M, N, H, result = 0;
int		mx[4] = { 0, 1, 0, -1 };
int		my[4] = { -1, 0, 1, 0 };
int		mz[3] = { -1, 0, 1 };
std::queue<std::vector<int>> que;

void BFS();

int main()
{
	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				int input = 0;
				scanf("%d", &input);
				MAP[k][i][j] = input;
				if (input == 1) {
					que.push({ k, i, j });
					visit[k][i][j] = true;
				};
			}
		}
	}

	BFS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				if (MAP[k][i][j] == 0) {
					printf("-1\n");
					return 0;
				}

				if (result < MAP[k][i][j]) {
					result = MAP[k][i][j];
				}
			}
		}
	}

	if(result == 1) printf("0\n");
	else printf("%d\n", result - 1);

	return 0;
}

void BFS()
{

	while (!que.empty()) {
		int y = que.front()[2];
		int x = que.front()[1];
		int z = que.front()[0];
		que.pop();

		for (int i = 0; i < 4; i++) {
			int iy = y + my[i];
			int ix = x + mx[i];
			for (int j = 0; j < 3; j++) {
				int iz = z + mz[j];
				if (iy < 0 || ix < 0 || iz < 0 || iy >= N || ix >= M || iz >= H) continue;
				if (!visit[iz][iy][ix] && MAP[iz][iy][ix] == 0) {
					que.push({ iz, iy, ix });
					MAP[iz][iy][ix] = MAP[z][y][x] + 1;
					visit[iz][iy][ix] = true;
				}
			}
		}
	}
}
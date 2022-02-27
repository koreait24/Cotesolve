#pragma warning (disable : 4996)

#include <stdio.h>

void DFS(int V);

int Vertex[101][101];
bool visit[101] = { false };
int nCom, X, Y, V, N;
int VirusCom = 0;

int main()
{
	scanf("%d %d", &nCom, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &X, &Y);
		Vertex[X][Y] = 1;
		Vertex[Y][X] = 1;
	}
	DFS(1);
	printf("%d", VirusCom);
	return 0;
}

void DFS(int V)
{
	visit[V] = true;
	for (int i = 1; i <= nCom; i++) {
		if (Vertex[V][i]) {
			if (!visit[i]) {
				DFS(i);
				VirusCom++;
			}
		}
	}
}
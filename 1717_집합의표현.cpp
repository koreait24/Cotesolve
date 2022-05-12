#include <stdio.h>

#define SWAP(a, b) {int t; t = a; a = b; b = t;}

using namespace std;

int parent[1000001];
int level[1000001];

int find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u != v) {
		if (level[u] > level[v]) SWAP(u, v);
		parent[u] = v;
		if (level[u] == level[v]) ++level[v];
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		level[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);

		int aParent = find(a);
		int bParent = find(b);

		if (cmd == 0) {
			merge(a, b);
		}

		if (cmd == 1) {
			aParent == bParent ? printf("YES\n") : printf("NO\n");
		}
	}
	return 0;
}
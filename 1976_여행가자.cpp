#include <stdio.h>
#define SWAP(a, b) {int t = a; a = b; b = t;}

int parent[1001];
int level[1001];

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b) {
		if (level[a] > level[b]) SWAP(a, b);
		parent[a] = b;
		if (level[a] == level[b]) ++level[b];
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int city;
			scanf("%d", &city);
			if (city == 1) {
				int iParent = find(i);
				int jParent = find(j);
				if (iParent == jParent) continue;
				merge(i, j);
			}
		}
	}
	bool result = true;

	int temp;
	scanf("%d", &temp);

	for (int i = 1; i < M; i++) {
		int next;
		scanf("%d", &next);

		int pnext = find(next);
		int ptemp = find(temp);
		temp = next;
		if (!result) continue;
		if (ptemp != pnext)result = false;
	}

	result ? printf("YES\n") : printf("NO\n");

	return 0;
}
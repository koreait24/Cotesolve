#pragma warning (disable : 4996)

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int V, E, K, u, v, w;
int dist[20002];
vector<vector<pair<int, int>>> vertex;

int main()
{
	scanf("%d %d %d", &V, &E, &K);
	vertex.resize(V + 1);
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		vertex[u].push_back({v, w});
	}

	priority_queue<pair<int, int>> pq;
	pq.push({0, K});
	while (pq.size()) {
		int current = pq.top().second; // w
		int cost = -pq.top().first; // v
		pq.pop();
		if (dist[current] != -1) continue;
		dist[current] = cost;
		for (const auto &it : vertex[current]) {
			int next = it.first;
			int sumDist = -it.second - cost;
			if (dist[next] != -1) continue;
			pq.push({sumDist, next});
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == -1) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}
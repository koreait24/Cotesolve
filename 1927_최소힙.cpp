#pragma warning (disable:4996)

#include <stdio.h>
#include <queue>
#include <vector>

int main()
{
	int N, Input, count = 0;
	int ans[100000];
	std::priority_queue<int, std::vector<int>, std::greater<int>> Que;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Input);
		if (Input != 0)
			Que.push(Input);
		else {
			if (Que.empty()) {
				ans[count] = 0;
			}
			else {
				ans[count] = Que.top();
				Que.pop();
			}
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		printf("%d\n", ans[i]);
	}
}
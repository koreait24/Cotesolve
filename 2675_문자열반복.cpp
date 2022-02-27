#pragma warning (disable:4996)

#include <stdio.h>
#include <cstring>
#include <vector>

int main()
{
	int N, R;
	std::vector<std::pair<char*, int>> S;
	char* str;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		str = new char[21];
		scanf("%d %s", &R, str);
		std::pair<char*, int> mpair = std::make_pair(str, R);
		S.push_back(mpair);
	}

	for (const auto &it : S) {
		for (int i = 0; i < strlen(it.first); i++) {
			for (int j = 0; j < it.second; j++) {
				printf("%c", it.first[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
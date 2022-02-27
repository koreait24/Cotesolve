#pragma warning (disable : 4996)

#include <stdio.h>
#include <vector>
#include <map>

int w(std::vector<int> input, std::map<std::vector<int>, int> &DP, int& output);

int main()
{
	int a = 0, b = 0, c = 0;
	std::map<std::vector<int>, int> DP;
	std::vector<std::vector<int>> input;
	do {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1)
			if(b == -1)
				if(c == -1)
					break;
		input.push_back({ a, b, c });
	} while (a != -1 || b != -1 || c != -1);

	for (const auto& it : input) {
		int output = 0;
		printf("w(%d, %d, %d) = %d\n", it[0], it[1], it[2], w(it, DP, output));
	}
	return 0;
}

int w(std::vector<int> input, std::map<std::vector<int>, int>& DP, int& output)
{
	int a = input[0], b = input[1], c = input[2];

	if (DP.size() > 0 && DP.find(input) != DP.end()) {		// DP�� ����� ���� ���� ��� DP�� ����
		output += DP[input];
		return DP[input];
	}

	if (a <= 0 || b <= 0 || c <= 0) {		// ���� ������ ��� 1�� output�� ����
		output += 1;
		return 1;
	}

	// w�� �����Ҷ� DP�� �Լ� ���� ���� �����ϰ� DP�� ������

	if (a > 20 || b > 20 || c > 20) {
		DP[input] = w({ 20, 20, 20 }, DP, output);
		return DP[input];
	}

	if (a < b && b < c) {
		DP[input] = w({ a, b, c-1 }, DP, output) +
			w({ a, b-1, c-1 }, DP, output) -
			w({ a, b-1, c }, DP, output);
		return DP[input];
	}

	DP[input] = w({ a-1, b, c }, DP, output) +
		w({ a-1, b-1, c }, DP, output) +
		w({ a-1, b, c-1 }, DP, output) -
		w({ a-1, b-1, c-1 }, DP, output);
	return DP[input];
}
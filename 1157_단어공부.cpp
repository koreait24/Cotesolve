#pragma warning (disable : 4996)

// strlen �� for���ȿ� �������� �ɸ� �������ϰ� �߻��Ѵ�.

#include <stdio.h>
#include <string>
#include <cstring>

int main()
{
	std::string input;
	char cinput[1000001] = "\0";
	int index[26] = { 0 };
	scanf("%s", cinput);
	int max = 0;
	char temp = '?';
	int len = strlen(cinput);
	for (int i = 0; i < len; i++) {
		input += std::toupper(cinput[i]);
	}

	for (int i = 0; i < len; i++) {
		char current = input[i];
		index[input[i] - 'A']++;
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		if (max == index[i - 'A']) temp = '?';
		if (max < index[i - 'A']) {
			max = index[i - 'A'];
			temp = i;
		}
	}

	printf("%c\n", temp);

	return 0;
}
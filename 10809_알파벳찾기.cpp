#pragma warning (disable : 4996)

#include <stdio.h>
#include <math.h>

int main()
{
	char str[100] = "\0";
	int index['z' - 'a' + 1] = { -1 };
	scanf("%s", str);

	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j < sizeof(str); j++) {
			index[abs('a' - i)] = -1;
			if (str[j] == i) {
				index[abs('a' - i)] = j;
				break;
			}
		}
	}

	for (int i = 0; i <= 'z' - 'a'; i++) {
		printf("%d ", index[i]);
	}
	return 0;
}
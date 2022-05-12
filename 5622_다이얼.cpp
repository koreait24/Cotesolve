#pragma warning (disable : 4996)

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input, swap;
	int answer = 0;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		switch (input[i])
		{
		default:
		case 'A': case 'B': case 'C':
			swap += '2';
			break;
		case 'D': case 'E': case 'F':
			swap += '3';
			break;
		case 'G': case 'H': case 'I':
			swap += '4';
			break;
		case 'J': case 'K': case 'L':
			swap += '5';
			break;
		case 'M': case 'N': case 'O':
			swap += '6';
			break;
		case 'P': case 'Q': case 'R': case 'S':
			swap += '7';
			break;
		case 'T': case 'U': case 'V':
			swap += '8';
			break;
		case 'W': case 'X': case 'Y': case 'Z':
			swap += '9';
			break;
		}
	}

	for (int i = 0; i < swap.size(); i++) {
		answer += (swap[i] - '0');
		answer += 1;
	}

	cout << answer << endl;

	return 0;
}
#include <iostream>
#include <set>

using namespace std;

void selfnum(int, std::set<int>&);

int main()
{
	std::set<int> number;
	for (int i = 1; i < 10000; i++) {
		selfnum(i, number);
	}

	for (int i = 1; i < 10000; i++) {
		std::set<int>::iterator iter = number.find(i);
		if (iter == number.end())
			cout << i << endl;
	}

	return 0;
}

void selfnum(int n, std::set<int> &number)
{
	std::set<int>::iterator iter = number.find(n);
	if (n > 10000)
		return;

	int thou = (n / 1000);
	int hund = (n % 1000) / 100;
	int ten = (n % 100) / 10;
	int one = n % 10;
	number.insert(n + thou + hund + ten + one);

	if (iter != number.end())
		return;

	return selfnum(n + thou + hund + ten + one, number);
}
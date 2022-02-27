#include <stdio.h>
#include <map>
#include <vector>

void RGBVector(int n, std::vector<int>& House, std::map<std::vector<int>, long long>& DP);

int main()
{
	return 0;
}

void RGBVector(int n, std::vector<int>& House, std::map<std::vector<int>, long long>& DP)
{
	House.push_back(n);

	if (House.at(n) == 0)
		DP[{0}] = House[n];

	if(House.at(n) % 3 == 0)
		return RGBVector(n + 1, House, DP), RGBVector(n + 2, House, DP);
	if(House.at(n) % 3 == 2)
		return RGBVector(n + 2, House, DP), RGBVector(n + 4, House, DP);
	if(House.at(n) % 3 == 1)
		return RGBVector(n + 4, House, DP), RGBVector(n + 5, House, DP);
}
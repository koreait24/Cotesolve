#pragma warning (disable : 4996)

#include <stdio.h>
#include <map>
#include <vector>

void fibonacci(int n, std::vector<int>& v, std::map<int, std::vector<int>> &DP);

int main()
{
    std::map<int, std::vector<int>> DP;
    std::vector<int> fibVec;
    int T = 0, N = 0;
    std::vector<int> NVec;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        NVec.push_back(N);
    }

    for (const auto &it : NVec) {           // 입력된 요소의 벡터만큼 반복
        for (int j = 0; j <= it; j++) {     // 반복자 만큼 반복 (바텀 업 방식으로 피보나치 DP 생성)
            fibVec = { 0, 0 };
            fibonacci(j, fibVec, DP);
            DP[j] = fibVec;                 // i번 피보나치의 0과 1의 개수를 DP에 저장
        }
        printf("%d %d\n", fibVec[0], fibVec[1]);
        DP.clear();
    }
}

void fibonacci(int n, std::vector<int>& v, std::map<int, std::vector<int>>& DP)
{
    if (n == 0) {
        v[0]++;
        return;
    }
    else if (n == 1) {
        v[1]++;
        return;
    }
    if (DP.size() > 0 && DP.find(n) != DP.end()) {          // DP가 존재하는 경우 해당 DP의 0과 1의 개수를 벡터에 더해준 후 리턴
        v[0] = v[0] + DP[n][0];
        v[1] = v[1] + DP[n][1];
        return;
    }

    else {
        return fibonacci(n-1, v, DP), fibonacci(n-2, v, DP);
    }
}
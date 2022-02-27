#pragma warning (disable : 4996)

#include <iostream>
#include <cstring>

using namespace std;

int n, m, cabbage;
bool a[51][51];
bool check[51][51];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool dfs(int y, int x) {
    if (check[y][x]) return false;
    check[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i]; // 3. 동, 서, 남, 북으로 1칸씩 이동
        int next_y = y + dy[i];

        if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && a[next_y][next_x]) // 4. 인근 지역에 배추 있을 경우, 해당 지역 방문 처리
            dfs(next_y, next_x);
    }
    return true;
}

int main(void) {
    int TC;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        scanf("%d %d %d", &m, &n, &cabbage);
        memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));

        for (int j = 0; j < cabbage; j++) {
            int x = 0, y = 0;
            scanf("%d %d", &x, &y);
            a[y][x] = 1; // 1. 행 - y축, 열 - x축
        }

        int bug_count = 0;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j][k] && !check[j][k]) { // 2. 탐색 안한 구역일 경우, dfs 수행 & count 추가 
                    if (dfs(j, k)) bug_count++;
                }
            }
        }
        printf("%d\n", bug_count);
    }
}
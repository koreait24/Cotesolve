#include <string>
#include <vector>

using namespace std;

int nN, nH, nW;
int result = 1;
int visited[1001][1001] = { false };
vector<string> graph;

void DFS(int x, int y, int dx = -1, int dy = -1);

void reset();

int solution(int h, int w, int n, vector<string> board) {
    int answer = 0;
    graph = board;
    nN = n;
    nH = h;
    nW = w;

    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x <= board[y].length(); x++) {
            if (!visited[y][x] && board[y][x] == '1') {
                DFS(x, y, 0, 1);
                if (result == n) {
                    visited[y][x] = true;
                    answer++;
                }
                result = 1;
            }
        }
    }

    reset();

    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x <= board[y].length(); x++) {
            if (!visited[y][x] && board[y][x] == '1') {
                DFS(x, y, 1, 0);
                if (result == n) {
                    visited[y][x] = true;
                    answer++;
                }
                result = 1;
            }
        }
    }

    reset();

    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x <= board[y].length(); x++) {
            if (!visited[y][x] && board[y][x] == '1') {
                DFS(x, y, 1, 1);
                if (result == n) {
                    visited[y][x] = true;
                    answer++;
                }
                result = 1;
            }
        }
    }

    reset();

    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x <= board[y].length(); x++) {
            if (!visited[y][x] && board[y][x] == '1') {
                DFS(x, y, -1, 1);
                if (result == n) {
                    visited[y][x] = true;
                    answer++;
                }
                result = 1;
            }
        }
    }

    return answer;
}

void reset() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            visited[i][j] = false;
        }
    }
}

void DFS(int x, int y, int dx, int dy) {
    visited[y][x] = true;

    int nx = x + dx;
    int ny = y + dy;

    if (nx >= 0 && ny >= 0 && nx < nW && ny < nH) {
        if (!visited[ny][nx] && graph[ny][nx] == '1') {
            DFS(nx, ny, dx, dy);
            result++;
        }
    }
}

int main() {
    printf("%d", solution(7, 9, 4, {"111100000", "000010011", "111100011", "111110011", "111100011", "111100010", "111100000"}));
}
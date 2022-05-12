#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, bool clockwise) {
    vector<vector<int>> answer(n, vector<int>(n, 0));

    if (clockwise) {
        for (int i = 0; i <= n * 0.5; i++) {
            for (int dx = 0; dx < n - (2 * i); dx++) {
                answer[i][dx] = (n * i) + dx;
                answer[n - i - 1][n - dx - 1] = (n * i) + dx;
            }
            for (int dy = 0; dy < n - (2 * i); dy++) {
                answer[dy][n - i - 1] = (n * i) + dy;
                answer[n - dy - 1][i] = (n * i) + dy;
            }
        }
    }

    return answer;
}

void main() {
    solution(5,true);
}
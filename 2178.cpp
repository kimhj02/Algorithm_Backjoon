#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1};  // 상하좌우
int dy[4] = {-1, 1, 0, 0};
int map[101][101];
bool visited[101][101];

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            // 범위 체크
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                // 방문하지 않았고, 길인 경우
                if (!visited[nx][ny] && map[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    map[nx][ny] = map[curX][curY] + 1;  // 거리 누적
                    q.push({nx, ny});
                }
            }
        }
    }

    return map[n - 1][m - 1];  // 도착 지점까지 거리
}

int main() {
    cin >> n >> m;

    // 미로 입력
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            map[i][j] = line[j] - '0';  // 문자 '1' → 정수 1
        }
    }

    cout << bfs(0, 0) << '\n';

    return 0;
}
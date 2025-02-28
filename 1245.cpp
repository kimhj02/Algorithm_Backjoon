#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> farm;
vector<vector<bool>> visited;
bool isPeak;

vector<int> dx = {-1, 1, 0, 0, 1, 1, -1, -1};
vector<int> dy = {0, 0, -1, 1, 1, -1, 1, -1};

void DFS(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

        // 인접한 칸에 더 높은 곳이 있으면 봉우리가 아님
        if (farm[ny][nx] > farm[y][x]) isPeak = false;

        // 같은 높이의 칸을 방문하여 탐색
        if (!visited[ny][nx] && farm[ny][nx] == farm[y][x]) {
            visited[ny][nx] = true;
            DFS(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    farm.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> farm[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                isPeak = true;
                visited[i][j] = true;  // 방문 처리
                DFS(i, j);
                if (isPeak) count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
}

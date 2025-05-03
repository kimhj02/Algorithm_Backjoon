#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> v(N, vector<int>(M));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cin >> v[i][j];

  int jump;
  cin >> jump;

  if (v[0][0] != v[N - 1][M - 1]) {
    cout << "DEAD";
    return 0;
  }

  vector<vector<bool>> visited(N, vector<bool>(M, false));
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = true;
  int target_color = v[0][0];

  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (x == N - 1 && y == M - 1) {
      cout << "ALIVE";
      return 0;
    }

    for (int dy = -jump; dy <= jump; ++dy) {
      for (int dx = -jump; dx <= jump; ++dx) {
        if (abs(dy) + abs(dx) > jump || abs(dy) + abs(dx) == 0)
          continue;
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
          if (!visited[nx][ny] && v[nx][ny] == target_color) {
            visited[nx][ny] = true;
            q.push({nx, ny});
          }
        }
      }
    }
  }

  cout << "DEAD";
  return 0;
}
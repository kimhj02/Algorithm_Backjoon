#include <iostream>
#include <vector>
using namespace std;

int W, H;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

int dx_even[6] = {-1, -1, 0, 0, 1, 1};
int dy_even[6] = {-1, 0, -1, 1, -1, 0};
int dx_odd[6]  = {-1, -1, 0, 0, 1, 1};
int dy_odd[6]  = {0, 1, -1, 1, 0, 1};

int dfs(int x, int y) {
  visited[x][y] = true;
  int wall = 0;
  for (int d = 0; d < 6; d++) {
    int nx = x + (x % 2 == 0 ? dx_even[d] : dx_odd[d]);
    int ny = y + (x % 2 == 0 ? dy_even[d] : dy_odd[d]);

    if (nx < 0 || ny < 0 || nx >= H + 2 || ny >= W + 2) continue;
    if (matrix[nx][ny] == 1) {
      wall++;
    } else if (!visited[nx][ny]) {
      wall += dfs(nx, ny);
    }
  }
  return wall;
}

int main() {
  cin >> W >> H;
  matrix.assign(H + 2, vector<int>(W + 2, 0)); // padding
  visited.assign(H + 2, vector<bool>(W + 2, false));

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> matrix[i][j];
    }
  }

  int result = dfs(0, 0); // guaranteed outside point
  cout << result << "\n";
  return 0;
}
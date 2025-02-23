#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> height;
vector<vector<int>> dp;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && height[nx][ny] < height[x][y]) {
            dp[x][y] += dfs(nx, ny);
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; //가로 세로
    height.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> height[i][j];

    cout << dfs(0, 0) << '\n';
    return 0;
}
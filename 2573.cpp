#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void DFS(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] > 0 && !visited[nx][ny]) {
            DFS(nx, ny);
        }
    }
}

int simulate() {
    vector<vector<int>> temp = graph;
    visited.assign(n, vector<bool>(m, false));
    int ice_count = 0;
    bool all_melted = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] > 0) {
                all_melted = false;
                int water_count = 0;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && graph[ni][nj] == 0) {
                        water_count++;
                    }
                }
                temp[i][j] = max(0, graph[i][j] - water_count);
            }
        }
    }

    graph = temp;

    if (all_melted) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] > 0 && !visited[i][j]) {
                DFS(i, j);
                ice_count++;
            }
        }
    }

    return ice_count;
}

int main() {
    cin >> n >> m;
    graph.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];

    int year = 0;

    while (true) {
        year++;
        int ice_count = simulate();

        if (ice_count >= 2) {
            cout << year << endl;
            return 0;
        }
        if (ice_count == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
}
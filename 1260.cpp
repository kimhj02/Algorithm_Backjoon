#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1001

int graph[MAX][MAX];
int visited[MAX];

void DFS(int v, int n);
void BFS(int v, int n);

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    memset(visited, 0, sizeof(visited));
    DFS(v, n);
    cout << endl;

    memset(visited, 0, sizeof(visited));
    BFS(v, n);

    return 0;
}

void DFS(int v, int n) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[v][i] == 1) {
            DFS(i, n);
        }
    }
}

void BFS(int v, int n) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && graph[cur][i] == 1) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

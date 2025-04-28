//
// Created by 김현진 on 25. 4. 28.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10;
int N, K;
int dist[MAX][MAX];
bool visited[MAX];
int result = 1e9;

void dfs(int current, int total, int count) {
    if (count == N) {
        result = min(result, total);
        return;
    }
    for (int next = 0; next < N; ++next) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(next, total + dist[current][next], count + 1);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> dist[i][j];

    // 플로이드-워셜 알고리즘
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    visited[K] = true;
    dfs(K, 0, 1);

    cout << result << endl;
    return 0;
}
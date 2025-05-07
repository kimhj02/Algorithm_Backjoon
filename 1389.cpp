#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
  int N, M; // N: 정점 수, M: 간선 수
  cin >> N >> M;

  // 거리 배열 초기화
  vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

  // 자기 자신까지는 거리 0
  for (int i = 1; i <= N; i++) {
    dist[i][i] = 0;
  }

  // 간선 입력
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }

  // 플로이드-워셜
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  // 케빈 베이컨 수 계산
  int min_sum = INF;
  int answer = 0;

  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += dist[i][j];
    }
    if (sum < min_sum) {
      min_sum = sum;
      answer = i;
    }
  }

  cout << answer << endl;
  return 0;
}
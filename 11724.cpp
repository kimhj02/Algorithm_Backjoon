#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;

void bfs(int start) { //시작 정점 요소로 방음
    queue<int> q;
    q.push(start); //큐에 넣기
    visited[start] = true; //방문 표시

    while (!q.empty()) { //큐가 빌때까지
        int node = q.front();
        q.pop();

        for (int side : arr[node]) { //반보하면 탐색
            if (!visited[side]) {
                visited[side] = true;
                q.push(side);
            }
        }
    }
}

int main() {
    int edge_num, vertex_num; //정점 수 간선 수
    cin >> edge_num >> vertex_num; //입력

    arr.resize(edge_num + 1); //크기 초기화
    visited.resize(edge_num + 1, false); // 크기 초기화 및 false로 초기화

    for (int i = 0; i < vertex_num; i++) { //간선 입력
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int count = 0; //요소 개수
    for (int i = 1; i <= edge_num; i++) {
        if (!visited[i]) { //방문한 적이 없으면
            bfs(i); //bfs
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
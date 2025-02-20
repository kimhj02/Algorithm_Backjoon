#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> arr; // 양방향 연결용 인접 리스트
vector<int> visited; // 방문 벡터는 1차원이어도 ㄱㅊ을듯
int max_distance = 0; // 최대 거리
int max_node = 0; // 아무 점에서나 가장 먼 노드의 번호

// DFS 함수: 시작점에서 가장 먼 노드를 찾는다.
void dfs(int start, int result) {
    visited[start] = 1; // 방문 처리

    if (result > max_distance) {
        max_distance = result;
        max_node = start;
    }

    for (auto next : arr[start]) {
        int next_node = next.first;
        int weight = next.second;
        if (!visited[next_node]) {
            dfs(next_node, result + weight);
        }
    }
}

int main() {
    int vertex_num = 0;
    cin >> vertex_num;
    arr.resize(vertex_num + 1);
    visited.resize(vertex_num + 1);

    for (int i = 0; i < vertex_num; i++) {
        // 시작 정점 번호, 그다음에는 연결된 정점의 번호와 거리가 주어짐
        // 이때 시작 정점에서 연결된 정점의 개수는 1개가 아닐 수 있음(여러 개 가능)
        // 마지막에는 -1 을 입력함
        // ex) 3 1 2 4 3 -1 이것의 의미는 3번 정점에 거리가 4인 2번 정점과, 거리가 3인 4번 정점이 연결되어 있다는 것을 의미
        int start_node = 0;
        cin >> start_node;
        while (true) {
            int node_num = 0, vertex_value = 0;
            cin >> node_num;
            if (node_num == -1) break; // 입력 종료

            cin >> vertex_value;
            arr[start_node].push_back({node_num, vertex_value}); // 양방향 연결
            arr[node_num].push_back({start_node, vertex_value}); // 양방향 연결
        }
    }

    // dfa로 시작점에서 가장 먼 점을 찾고
    fill(visited.begin(), visited.end(), 0);
    max_distance = 0;
    dfs(1, 0);

    // 거기서 한번 더 dfs를 돌려서 가장 먼 점을 찾자
    fill(visited.begin(), visited.end(), 0);
    max_distance = 0;
    dfs(max_node, 0);

    // 마지막에 트리의 지름을 출력하자
    cout << max_distance << endl;
    return 0;
}
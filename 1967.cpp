#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> visited;
int max_dist = 0; // 트리의 지름을 저장할 변수
int farthest_node = 0; // 가장 먼 노드 저장

void dfs(int node, int dist) {
    visited[node] = 1;

    if (dist > max_dist) {
        max_dist = dist;
        farthest_node = node;
    }

    for (auto next : adj[node]) {
        int next_node = next.first;
        int weight = next.second;
        if (!visited[next_node]) {
            dfs(next_node, dist + weight);
        }
    }
}

int main() {
    int node_num;
    cin >> node_num;

    if (node_num == 1) {
        cout << 0 << endl; // 노드가 1개일 경우 지름은 0
        return 0;
    }

    adj.resize(node_num + 1);
    visited.resize(node_num + 1);

    for (int i = 0; i < node_num - 1; i++) {
        int parent, child, value;
        cin >> parent >> child >> value;
        adj[parent].push_back({child, value});
        adj[child].push_back({parent, value});
    }

    fill(visited.begin(), visited.end(), 0);
    max_dist = 0;
    dfs(1, 0);

    fill(visited.begin(), visited.end(), 0);
    max_dist = 0;
    dfs(farthest_node, 0);

    cout << max_dist << endl;
}
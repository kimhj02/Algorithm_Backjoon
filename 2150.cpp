#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int vertex_num, edge_num;
vector<vector<int>> graph, rev_graph;
vector<bool> visited;
stack<int> stack1;
vector<vector<int>> scc;

void dfs1(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) dfs1(next);
    }
    stack1.push(node);
}

void dfs2(int node, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int next : rev_graph[node]) {
        if (!visited[next]) dfs2(next, component);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> vertex_num >> edge_num;
    graph.resize(vertex_num + 1);
    rev_graph.resize(vertex_num + 1);
    visited.resize(vertex_num + 1, false);

    for (int i = 0; i < edge_num; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        rev_graph[end].push_back(start);
    }

    for (int i = 1; i <= vertex_num; i++) {
        if (!visited[i]) dfs1(i);
    }

    for (int i = 1; i <= vertex_num; i++) {
        visited[i] = false;
    }

    while (!stack1.empty()) {
        int node = stack1.top();
        stack1.pop();
        if (!visited[node]) {
            vector<int> component;
            dfs2(node, component);
            sort(component.begin(), component.end());
            scc.push_back(component);
        }
    }

    sort(scc.begin(), scc.end());

    cout << scc.size() << '\n';
    for (auto& comp : scc) {
        for (int node : comp) {
            cout << node << ' ';
        }
        cout << "-1\n";
    }


    return 0;
}

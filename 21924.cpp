#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

vector<int> parent;

int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]);
}

void merge(int node_a, int node_b) {
    int a = find(node_a);
    int b = find(node_b);
    if (a != b) parent[b] = a;
}

int main() {
    int struct_num, road_num;
    cin >> struct_num >> road_num;

    vector<Edge> edges;
    parent.resize(struct_num + 1);

    long long total_cost = 0;

    for (int i = 1; i <= struct_num; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < road_num; i++) {
        int start, end, value;
        cin >> start >> end >> value;
        edges.push_back({start, end, value});
        total_cost += value;
    }

    sort(edges.begin(), edges.end(), compare);

    long long mst_cost = 0;
    int count = 0;

    for (const auto& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            merge(edge.u, edge.v);
            mst_cost += edge.w;
            count++;
        }
        if (count == struct_num - 1) break; // MST 완성
    }

    if (count != struct_num - 1) {
        cout << -1 << endl;
    } else {
        cout << total_cost - mst_cost << endl; // 절약된 비용 출력
    }

    return 0;
}
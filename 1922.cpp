#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, w;
};

vector<int> parent;

int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

int main() {
    int vertex_num, edge_num;
    cin >> vertex_num >> edge_num;

    parent.assign(vertex_num + 1, 0);
    vector<edge> edges;

    for (int i = 1; i <= vertex_num; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edge_num; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w;
    });

    long long total = 0;
    int count = 0;

    for (int i = 0; i < edge_num; i++) {
        edge edge1 = edges[i];

        if (find(edge1.u) != find(edge1.v)) {
            merge(edge1.u, edge1.v);
            total += edge1.w;
            count++;

            if (count == vertex_num - 1) break;
        }
    }

    cout << total << endl;
    return 0;
}
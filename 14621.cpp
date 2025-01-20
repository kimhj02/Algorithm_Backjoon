#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int size) {
        parent.resize(size + 1);
        rank.resize(size + 1, 0);
        for (int i = 1; i <= size; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        if (parent[n] != n) {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }

    void merge(int n1, int n2) {
        int root1 = find(n1);
        int root2 = find(n2);

        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

struct Edge {
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

bool compare(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> schools(n + 1);
    vector<Edge> edges;

    for (int i = 1; i <= n; i++) {
        cin >> schools[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        if (schools[u] != schools[v]) {
            edges.emplace_back(u, v, cost);
        }
    }

    sort(edges.begin(), edges.end(), compare);

    UnionFind uf(n);
    int mst_cost = 0, count = 0;

    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.merge(edge.u, edge.v);
            mst_cost += edge.cost;
            count++;

            if (count == n - 1) break;
        }
    }

    if (count == n - 1) {
        cout << mst_cost << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

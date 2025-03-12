#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent;

int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) parent[rootB] = rootA;
}

int kruskal(int n, vector<Edge>& edges, bool isMax) {
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;

    if (isMax) {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.w > b.w; // 내림차순 정렬
        });
    } else {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.w < b.w; // 오름차순 정렬
        });
    }

    int uphill_count = 0;
    int count = 0;

    for (auto& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            merge(edge.u, edge.v);
            if (edge.w == 0) uphill_count++; // 오르막길이면 카운트 증가
            count++;
            if (count == n) break; // MST 완성되면 종료
        }
    }
    return uphill_count;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i <= m; i++) { // 도로 개수는 m+1개
        int start, end, value;
        cin >> start >> end >> value;
        edges.push_back({start, end, value});
    }

    int min_uphill = kruskal(n, edges, false);
    int max_uphill = kruskal(n, edges, true);

    cout << abs((max_uphill * max_uphill) - (min_uphill * min_uphill)) << endl;

    return 0;
}
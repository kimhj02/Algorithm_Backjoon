//
// Created by 김현진 on 25. 5. 26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    int color; // 0 = red, 1 = blue
};

int parent[1001], rankArr[1001];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (rankArr[a] < rankArr[b]) {
        parent[a] = b;
    } else {
        parent[b] = a;
        if (rankArr[a] == rankArr[b]) rankArr[a]++;
    }
    return true;
}

int kruskal(int N, vector<Edge>& edges, bool blueIsExpensive) {
    vector<pair<int, int>> sortedEdges;

    for (int i = 0; i < edges.size(); i++) {
        int weight;
        if (blueIsExpensive) {
            weight = (edges[i].color == 1 ? 1 : 0);
        } else {
            weight = (edges[i].color == 1 ? 0 : 1);
        }
        sortedEdges.push_back({weight, i});
    }

    sort(sortedEdges.begin(), sortedEdges.end());

    init(N);
    int blueCount = 0, edgeCount = 0;

    for (auto &p : sortedEdges) {
        int idx = p.second;
        if (unionSets(edges[idx].u, edges[idx].v)) {
            edgeCount++;
            if (edges[idx].color == 1) blueCount++;
            if (edgeCount == N - 1) break;
        }
    }

    if (edgeCount < N - 1) return -1;
    return blueCount;
}

int main() {
    while (true) {
        int N, M, K;
        cin >> N >> M >> K;
        if (N == 0 && M == 0 && K == 0) break;

        vector<Edge> edges(M);
        for (int i = 0; i < M; i++) {
            int u, v;
            char c;
            cin >> c >> u >> v;
            edges[i] = {u, v, (c == 'B' ? 1 : 0)};
        }

        int minBlue = kruskal(N, edges, true);  // blue is expensive
        int maxBlue = kruskal(N, edges, false); // blue is cheap

        if (minBlue == -1 || maxBlue == -1) {
            cout << 0 << endl;
        } else {
            cout << (minBlue <= K && K <= maxBlue ? 1 : 0) << endl;
        }
    }

    return 0;
}
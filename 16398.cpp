#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> parent;

// 정렬 기준 함수
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

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
    int case_num;
    cin >> case_num;

    vector<Edge> edges;
    parent.resize(case_num);

    for (int i = 0; i < case_num; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < case_num; i++) {
        for (int j = 0; j < case_num; j++) {
            int weight;
            cin >> weight;
            if (i < j) {
                edges.push_back({i, j, weight});
            }
        }
    }

    sort(edges.begin(), edges.end(), compare);

    long long total = 0;
    int count = 0;

    for (size_t i = 0; i < edges.size(); i++) {
        Edge edge = edges[i];
        if (find(edge.u) != find(edge.v)) {
            merge(edge.u, edge.v);
            total += edge.weight;
            count++;
            if (count == case_num - 1) break;
        }
    }

    cout << total << endl;

    return 0;
}
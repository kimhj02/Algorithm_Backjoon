#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, w;
};

vector<int> parent;

bool compare(edge a, edge b) {
    return a.w < b.w;
}

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
    while (true) {
        int house_num, road_num;
        cin >> house_num >> road_num;

        if (house_num == 0 && road_num == 0) break;

        parent.resize(house_num + 1);
        for (int i = 0; i <= house_num; i++) parent[i] = i;

        vector<edge> edges;
        long long total_value = 0;

        for (int i = 0; i < road_num; i++) {
            int start, end, value;
            cin >> start >> end >> value;
            edges.push_back({start, end, value});
            total_value += value;
        }

        sort(edges.begin(), edges.end(), compare);

        long long mst_cost = 0;
        int count = 0;

        for (int i = 0; i < edges.size(); i++) {
            edge e = edges[i];
            if (find(e.u) != find(e.v)) {
                merge(e.u, e.v);
                mst_cost += e.w;
                count++;
            }
            if (count == house_num - 1) break;
        }

        cout << total_value - mst_cost << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int u, v;
    double w;
};

struct Star {
    double x, y;
};

vector<int> parent;

bool compare(Edge a, Edge b) {
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
    int star_num;
    cin >> star_num;

    vector<Star> stars(star_num);
    vector<Edge> edges;
    parent.resize(star_num);

    for (int i = 0; i < star_num; i++) {
        cin >> stars[i].x >> stars[i].y;
        parent[i] = i;
    }

    for (int i = 0; i < star_num; i++) {
        for (int j = i + 1; j < star_num; j++) {
            double dist = sqrt(pow(stars[i].x - stars[j].x, 2) + pow(stars[i].y - stars[j].y, 2));
            edges.push_back({i, j, dist});
        }
    }

    sort(edges.begin(), edges.end(), compare);

    double mst_cost = 0;
    int count = 0;

    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            mst_cost += e.w;
            count++;
        }
        if (count == star_num - 1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << mst_cost << endl;

    return 0;
}
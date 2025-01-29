#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent;
vector<int> power;

int find(int num) {
    if (parent[num] == num) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

// 간선 정렬 기준 (가중치 오름차순)
bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int city_num, cable_num, electric_num;
    cin >> city_num >> cable_num >> electric_num;

    parent.resize(city_num + 1);
    vector<Edge> edges;

    for (int i = 1; i <= city_num; i++) {
        parent[i] = i;
    }

    power.resize(electric_num);
    for (int i = 0; i < electric_num; i++) {
        cin >> power[i];
        parent[power[i]] = 0; // 발전소가 있는 도시들은 같은 집합(0번 집합)으로 설정
    }

    for (int i = 0; i < cable_num; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // 간선을 가중치 기준으로 정렬
    sort(edges.begin(), edges.end(), compare);

    int total_cost = 0, used_edges = 0;

    // 크루스칼 알고리즘
    for (const auto &e : edges) {
        if (find(e.u) != find(e.v)) { // 사이클이 발생하지 않는 경우
            merge(e.u, e.v);
            total_cost += e.w;
            used_edges++;

            if (used_edges == city_num - electric_num) break;
        }
    }

    cout << total_cost << endl;
    return 0;
}
//
// Created by 김현진 on 2025. 4. 12..
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, w;
};

vector<int> parent;

// find 함수 - 경로 압축
int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

// union 함수
void merge(int node_a, int node_b) {
    int a = find(node_a);
    int b = find(node_b);
    if (a != b) parent[a] = b;
}

// 내림차순 정렬을 위해 비교 함수 정의
bool compare(edge a, edge b) {
    return a.w > b.w;
}

int main() {
    int island_num = 0, bridge_num = 0;
    cin >> island_num >> bridge_num;

    int start, end;
    cin >> start >> end;

    vector<edge> edges;

    for (int i = 0; i < bridge_num; i++) {
        int start_point, end_point, weight;
        cin >> start_point >> end_point >> weight;
        edges.push_back({start_point, end_point, weight});
    }

    // 부모 배열 초기화
    parent.resize(island_num + 1);
    for (int i = 1; i <= island_num; i++) parent[i] = i;

    // 간선 내림차순 정렬
    sort(edges.begin(), edges.end(), compare);

    // 가장 큰 간선부터 연결하면서 연결되면 그 가중치가 최대 중량
    for (auto e : edges) {
        merge(e.u, e.v);
        if (find(start) == find(end)) {
            cout << e.w << '\n';
            return 0;
        }
    }

    // 연결이 안 되는 경우
    cout << "0\n";
}
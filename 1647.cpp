#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
    int start, end, value;
};

typedef long long ll;
vector<int> parent;

int find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void merge(int n1, int n2) {
    n1 = find(n1);
    n2 = find(n2);
    if (n1 != n2) parent[n1] = n2;
}

bool compare(edge n1, edge n2) {
    return n1.value < n2.value;
}

int main() {
    int house_num, test_case;
    cin >> house_num >> test_case;

    vector<edge> edges;
    parent.resize(house_num);

    for (int i = 0; i < house_num; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < test_case; i++) {
        int start_num, end_num, weight;
        cin >> start_num >> end_num >> weight;
        edges.push_back({start_num, end_num, weight});
    }

    sort(edges.begin(), edges.end(), compare);

    ll total = 0;
    int cnt = 0;
    int max_edge_cost = 0;

    for (const auto& e : edges) {
        if (find(e.start) != find(e.end)) {
            merge(e.start, e.end);
            total += e.value;
            max_edge_cost = e.value; // 가장 최근에 추가된 간선의 비용
            cnt++;
            if (cnt == house_num - 1) break;
        }
    }

    cout << total - max_edge_cost << endl;

    return 0;
}
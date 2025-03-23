#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;

struct edge {
    int u,v,w;
};

bool compare(edge a, edge b) {
    return a.w < b.w;
}

int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

void merge(int node_a, int node_b) {
    int a = find(node_a);
    int b = find(node_b);
    if (a != b) parent[b] = a;
}

int main() {
    int city_num = 0, road_num = 0, road_val = 0;
    cin >> city_num >> road_num >> road_val;
    parent.resize(city_num + 1);
    vector<edge> edges;

    for (int i = 1; i <= city_num; i++) { //자기 자신이랑 연결
        parent[i] = i;
    }
    for (int i = 1; i <= road_num; i++) { // a 와 b 도로 사이에 c가 있음
        int start, end, weight;
        cin >> start >> end >> weight;
        edges.push_back({start, end, weight}); //들어가 있음
    }

    sort(edges.begin(), edges.end(), compare);
    /*for (int i = 0; i < edges.size(); i++) { 정렬은 잘 되어 있음
        cout << edges[i].w << " ";
    }
    cout << endl; //예제 기준 1 2 2 3 4
    */

    long long total = 0;
    int count = 0;
    int plus_value = 0;
    //하나가 열결되면 weight를 road_val 만큼 증가시켜야 함
    for (int i = 0; i < edges.size(); i++) { //1번에서 시작해서 확인
        edge e = edges[i];
        if (find(e.u) != find(e.v)) { //ed
            //cout << e.u << " " << e.v << " " << e.w << endl;
            merge(e.u, e.v); //병합하고
            total += e.w + plus_value; //값 증가
            count++;
            plus_value += road_val;
        }
        if (count == road_num - 1) break;
    }
    cout << total << endl;
    return 0;
}
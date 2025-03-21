#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip> // 소수점 출력을 위한 헤더
using namespace std;

struct edge {
    int u, v;
    double w;
};

vector<int> parent;

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
    int god_num = 0, road_num = 0;
    vector<edge> edges;
    cin >> god_num >> road_num;

    vector<pair<int,int>> x_y(god_num + 1); //좌표 입력용
    parent.resize(god_num + 1);
    for (int i = 1; i <= god_num; i++) parent[i] = i;

    vector<vector<double>> matrix(god_num+1,vector<double>(god_num+1,0)); //각 신끼리의 거리

    //좌표 입력
    for (int i = 1; i <= god_num; i++) {
        int x, y;
        cin >> x >> y; //좌표 입력
        x_y[i] = make_pair(x,y); //신들이 있는 좌표 입력
    }

    //좌표에 대한 각 신끼리의 거리 입력
    for (int i = 1; i <= god_num; i++) {
        for (int j = i+1; j <= god_num; j++) {
            //거리를 matrix에 입력
            double dx = x_y[i].first - x_y[j].first;
            double dy = x_y[i].second - x_y[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            matrix[i][j] = matrix[j][i] = dist;

            // 간선 목록에 추가
            edges.push_back({i, j, dist});
        }
    }

    for (int i = 1; i <= road_num; i++) {
        int start, end;
        cin >> start >> end;
        //이 연결 도로는 무조건 사용하고
        merge(start, end); // 미리 유니온으로 합쳐줌
    }

    long long count = 0;
    double total = 0;
    //Union find를 통해 mst 구성
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w;
    });

    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            total += e.w;
            count++;
            if (count == god_num - 1) break;
        }
    }

    // 값 출력
    cout << fixed << setprecision(2) << total << endl;
    return 0;
}
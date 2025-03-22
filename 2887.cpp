#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //abs 사용 용도
using namespace std;

struct coordinate {
    int x, y, z;
    int idx; // 행성 번호 저장
};

struct edge {
    int u, v, w; // 시작 도착 거리
};

vector<int> parent;

int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

void merge(int node_a, int node_b) {
    int a = find(node_a);
    int b = find(node_b);
    if (a != b) parent[b] = a;
}

bool compare(edge a, edge b) {
    return a.w < b.w;
}

int main() {
    int planet_num = 0;
    cin >> planet_num;
    parent.assign(planet_num, 0);

    for (int i = 0; i < planet_num; i++) {
        parent[i] = i;
    }
    vector<coordinate> coordinates(planet_num); //각 행성의 좌표를 입력하기 위한 좌표
    vector<edge> edges; // 각 행상 간의 거리를 저장하기 위한 벡터

    for (int i = 0; i < planet_num; i++) {
        int x, y, z;
        cin >> x >> y >> z; //x, y, z 좌표
        coordinates[i] = {x, y, z, i}; // 좌표 + 인덱스
    }

    // x, y, z 축 각각 정렬해서 인접한 것만 간선으로 연결
    for (int dim = 0; dim < 3; dim++) {
        if (dim == 0)//x 정렬
            sort(coordinates.begin(), coordinates.end(), [](coordinate a, coordinate b) { return a.x < b.x; });
        else if (dim == 1) //y 정렬
            sort(coordinates.begin(), coordinates.end(), [](coordinate a, coordinate b) { return a.y < b.y; });
        else //z 정렬
            sort(coordinates.begin(), coordinates.end(), [](coordinate a, coordinate b) { return a.z < b.z; });

        for (int i = 0; i < planet_num - 1; i++) {
            int cost;
            if (dim == 0) //x만
                cost = abs(coordinates[i].x - coordinates[i + 1].x);
            else if (dim == 1) //y만
                cost = abs(coordinates[i].y - coordinates[i + 1].y);
            else //z만
                cost = abs(coordinates[i].z - coordinates[i + 1].z);

            edges.push_back({coordinates[i].idx, coordinates[i + 1].idx, cost}); //시작 도착 거리
        }
    }

    sort(edges.begin(), edges.end(), compare); //edges에 값이 저장되어 있음

    long long total = 0;
    int count = 0;
    for (int i = 0; i < edges.size(); i++) { //
        edge e = edges[i];
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            total += e.w;
            count++;
        }
        if (count == planet_num - 1) break;
    }
    cout << total << endl;
    return 0;
}

//3차원상의 위치
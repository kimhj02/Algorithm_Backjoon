#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

vector<int> parent;

int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

void merge(int a_node, int b_node) {
    int a = find(a_node);
    int b = find(b_node);
    if (a != b) parent[a] = b;
}

int main() {
    int edge_num, vertex_num, turn_num;
    cin >> edge_num >> vertex_num >> turn_num;

    vector<Edge> edges;
    for (int i = 0; i < vertex_num; i++) {
        int start, end;
        cin >> start >> end; //간선의 시작 끝 입력
        edges.push_back({start, end, i + 1}); // 가중치를 입력 순서로 설정
    }

    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < turn_num; i++) { //턴 횟수만큼 반복
        bool is_zero = false; //

        parent.assign(edge_num + 1, 0); // parent 초기화
        for (int k = 1; k <= edge_num; k++) {
            parent[k] = k;
        }

        int min_weight = 2147483647; //가장 작은 값 기억
        int min_weight_index = -1; //가장 작은 값의 인덱스 확인
        int count = 0; //간선 개수 count
        long long total = 0; //전체 비용 계산

        for (int j = 0; j < edges.size(); j++) {
            Edge e = edges[j];
            if (find(e.u) != find(e.v)) { //대표 정점이 다르다면
                merge(e.u, e.v); //병합
                total += e.w; //비용 추가
                count++; //count 증가
                if (min_weight > e.w) { //가장 작은 값 찾기
                    min_weight = e.w;
                    min_weight_index = j; //가장 작은 값 인덱스 기록
                }
            }
        }

        if (is_zero == true) { //이전게 0이라면
            for (int k = i; k < turn_num; k++) {
                cout << "0 ";
            }
        }

        if (count == edge_num - 1) {
            cout << total << " ";
            if (min_weight_index != -1) {
                edges.erase(edges.begin() + min_weight_index);
            }
        } else {
            cout << "0 "; //0으로 출력
            is_zero = true;
        }


    }
    return 0;
}
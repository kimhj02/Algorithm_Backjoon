#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// **간선 정보를 저장하는 구조체**
struct edge {
    int u, v, w; // u: 시작 정점, v: 도착 정점, w: 가중치
};

// **부모 노드를 저장하는 벡터 (Union-Find)**
vector<int> parent;

// **Find 연산 (경로 압축 적용)**
// - 노드의 대표(parent)를 찾음 (경로 압축 기법 사용)
int find(int node) {
    if (parent[node] == node) return node; // 자기 자신이 루트이면 반환
    return parent[node] = find(parent[node]); // 경로 압축 (재귀로 루트 갱신)
}

// **Union 연산 (두 집합을 합침)**
void merge(int a, int b) {
    a = find(a); // a의 루트 찾기
    b = find(b); // b의 루트 찾기
    if (a != b) parent[a] = b; // 서로 다른 집합이면 합치기
}

int main() {
    int vertex_num, edge_num; // 정점 개수, 간선 개수
    cin >> vertex_num >> edge_num;

    // **1-based index 사용 (정점 번호 1부터 시작)**
    parent.assign(vertex_num + 1, 0);
    vector<edge> edges; // 간선 리스트

    // **부모 노드 초기화 (자기 자신을 부모로 설정)**
    for (int i = 1; i <= vertex_num; i++) {
        parent[i] = i;
    }

    // **간선 정보 입력**
    for (int i = 0; i < edge_num; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // 간선 정보 저장
    }

    // **크루스칼 알고리즘을 위한 간선 정렬 (오름차순)**
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w; // 가중치를 기준으로 정렬
    });

    long long total = 0; // 최소 신장 트리(MST)의 총 가중치
    int count = 0; // 선택된 간선 개수

    // **MST 구성 (크루스칼 알고리즘)**
    for (int i = 0; i < edge_num; i++) {
        edge edge1 = edges[i];

        // **두 정점이 서로 다른 집합에 속하면 (즉, 사이클이 아니면)**
        if (find(edge1.u) != find(edge1.v)) {
            merge(edge1.u, edge1.v); // 두 정점을 연결 (Union-Find)
            total += edge1.w; // 최소 신장 트리의 가중치 합산
            count++; // 선택된 간선 개수 증가

            if (count == vertex_num - 1) break; // 모든 정점이 연결되면 종료
        }
    }

    cout << total << endl; // 최소 신장 트리의 총 가중치 출력
    return 0;
}
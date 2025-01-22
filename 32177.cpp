#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int parent;
    int rank;
};

struct Person {
    int x, y, version, have_picture;
};

Node nodes[3001];
Person persons[3001];

// Union-Find에서 부모 노드를 찾는 함수
int find(int n) {
    if (n == nodes[n].parent) return n;
    return nodes[n].parent = find(nodes[n].parent);
}

// Union-Find에서 두 노드를 합치는 함수
void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        if (nodes[rootA].rank > nodes[rootB].rank) {
            nodes[rootB].parent = rootA;
        } else if (nodes[rootA].rank < nodes[rootB].rank) {
            nodes[rootA].parent = rootB;
        } else {
            nodes[rootB].parent = rootA;
            nodes[rootA].rank++;
        }
    }
}

// 두 좌표 간 거리가 최대 거리를 초과하지 않는지 확인하는 함수
bool is_within_distance(int x1, int y1, int x2, int y2, int max_distance) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy <= max_distance * max_distance;
}

int main() {
    int friend_num, max_distance, max_version_diff;
    int x, y, version;

    cin >> friend_num >> max_distance >> max_version_diff;
    cin >> x >> y >> version;

    // Union-Find 초기화
    for (int i = 0; i <= friend_num; i++) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }

    // 친구 정보 입력
    for (int i = 1; i <= friend_num; i++) {
        cin >> persons[i].x >> persons[i].y >> persons[i].version >> persons[i].have_picture;
    }

    // 조건에 따라 노드를 연결
    for (int i = 1; i <= friend_num; i++) {
        for (int j = i + 1; j <= friend_num; j++) {
            if (is_within_distance(persons[i].x, persons[i].y, persons[j].x, persons[j].y, max_distance) &&
                abs(persons[i].version - persons[j].version) <= max_version_diff) {
                merge(i, j);
            }
        }

        // 주인공과 친구들 간의 연결 조건 확인
        if (is_within_distance(x, y, persons[i].x, persons[i].y, max_distance) &&
            abs(version - persons[i].version) <= max_version_diff) {
            merge(0, i);
        }
    }

    vector<int> result;
    for (int i = 1; i <= friend_num; i++) {
        if (persons[i].have_picture && find(0) == find(i)) {
            result.push_back(i);
        }
    }

    // 결과 출력
    if (result.empty()) {
        cout << "0";
    } else {
        sort(result.begin(), result.end());
        for (int i : result) {
            cout << i << " ";
        }
    }

    return 0;
}

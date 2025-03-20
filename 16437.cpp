#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct island {
    char t; // 섬 정보 W면 늑대, S면 양
    int num; // 양, 늑대의 개수
    int connect; // 연결되어 있는 섬 정보
};

vector<vector<int>> tree; // 트리
vector<island> islands; // 섬 정보 저장
vector<long long> sheep_count; // 각 섬의 양 개수 저장

void DFS(int node) {
    for (int next : tree[node]) { // 트리에 연결된 섬 찾기
        DFS(next); // DFS 수행

        if (islands[next].t == 'W') { // 늑대 섬이라면
            sheep_count[next] = max(0LL, sheep_count[next] - islands[next].num); // 늑대가 양을 잡아먹음, 이게 Long Long 타입끼리 비교해야함
        }
        sheep_count[node] += sheep_count[next]; // 부모 섬으로 양을 전달
    }
}

int main() {
    int island_num = 0;
    cin >> island_num;

    islands.resize(island_num + 1);
    sheep_count.resize(island_num + 1, 0); //
    tree.assign(island_num + 1, vector<int>()); //

    for (int i = 2; i < island_num + 1; i++) { // 1번 섬은 탈출용 섬, 1번으로 이동하면 탈출
        char type;
        int num, connect;
        cin >> type >> num >> connect;

        islands[i].t = type;
        islands[i].num = num;
        islands[i].connect = connect; // 입력

        tree[connect].push_back(i); // 트리 연결
        if (type == 'S') { //양이 있는 섬이라면
            sheep_count[i] = num; // 양 개수 저장
        }
    }

    DFS(1); // 1번 섬에서 DFS 시작, 연결된 부분을 찾음

    cout << sheep_count[1]<< endl; // 1번 섬에 도착한 양의 개수 출력
}
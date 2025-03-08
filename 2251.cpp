#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 물통의 용량
int a, b, c;

// 방문 체크 배열 (A와 B만 있으면 C는 자동 결정됨)
bool visited[201][201];

// A가 비어있을 때 C에 담길 수 있는 물의 양을 저장하는 집합 (자동 정렬)
set<int> results;

void dfs(int A, int B, int C) {
    // 이미 방문한 상태라면 리턴
    if (visited[A][B]) return;
    visited[A][B] = true;

    // A가 비어있는 경우, C의 값을 결과에 추가
    if (A == 0) results.insert(C);

    // 각 물통의 최대 용량 저장
    int max_water[3] = {a, b, c};

    // 현재 물 상태 저장
    int cur_water[3] = {A, B, C};

    // 6가지 물 이동 경우 탐색 (i → j)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue; // 같은 물통끼리 이동 불가능

            // 다음 상태를 저장할 배열 (현재 상태를 복사)
            int next_water[3] = {cur_water[0], cur_water[1], cur_water[2]};

            // i에서 j로 이동할 수 있는 최대 물의 양 계산
            int move_amount = min(cur_water[i], max_water[j] - cur_water[j]);

            // 물 이동 (i → j)
            next_water[i] -= move_amount;
            next_water[j] += move_amount;

            // 새로운 상태로 DFS 탐색
            dfs(next_water[0], next_water[1], next_water[2]);
        }
    }
}

int main() {
    // 물통 용량 입력
    cin >> a >> b >> c;

    // 초기 상태 (A=0, B=0, C=c)에서 DFS 시작
    dfs(0, 0, c);

    // 결과 출력 (자동 정렬된 상태로 출력)
    for (int i : results) cout << i << " ";

    return 0;
}
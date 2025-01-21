#include <iostream>
#include <algorithm>
using namespace std;

int N, M, T, result = 0; // N: 사람 수, M: 파티 수, T: 진실을 아는 사람 수, result: 거짓말 가능 파티 수

// 분리 집합을 위한 노드 구조체
typedef struct node {
    int parent; // 부모 노드
    int Rank;   // 진실을 아는 사람인지 표시 (1이면 진실을 앎)
} NODE;

int party[51][51] = { 0 }; // 파티 정보 저장 배열 (파티당 최대 50명)
NODE div_set[51];              // 사람들의 분리 집합 노드 배열

// 분리 집합에서 루트 노드(대표자)를 찾는 함수
int Find(int a) {
    if (a == div_set[a].parent) // 자신이 루트 노드라면
        return a;
    return div_set[a].parent = Find(div_set[a].parent); // 경로 압축을 적용하며 루트 노드 반환
}

// 두 분리 집합을 병합하는 함수
void merge(int a, int b) {
    int x = Find(a); // a의 대표자 찾기
    int y = Find(b); // b의 대표자 찾기
    if (x == y) // 이미 같은 집합이라면 병합할 필요 없음
        return;
    if (div_set[x].Rank == 1) { // x가 진실을 아는 집합이라면
        div_set[y].parent = x; // y를 x에 병합
    } else {
        div_set[x].parent = y; // 그렇지 않으면 x를 y에 병합
    }
}

int main() {
    cin >> N >> M; // 사람 수와 파티 수 입력
    cin >> T;      // 진실을 아는 사람 수 입력

    // 진실을 아는 사람 입력
    for (int i = 0; i < T; i++) {
        int tmp;
        cin >> tmp;
        div_set[tmp].Rank = 1; // 진실을 아는 사람 표시
    }

    // 초기화: 각 사람의 부모를 자기 자신으로 설정
    for (int i = 1; i <= N; i++) {
        div_set[i].parent = i;
    }

    // 각 파티의 참가자 정보 입력
    for (int i = 0; i < M; i++) {
        cin >> party[i][0]; // 파티에 참가하는 사람 수
        for (int j = 1; j <= party[i][0]; j++) {
            cin >> party[i][j]; // 참가자 ID 입력
        }
    }

    // 진실을 아는 사람이 없으면 모든 파티에서 거짓말 가능
    if (T == 0) {
        cout << M;
        return 0;
    }

    // 파티 내 참가자들을 같은 집합으로 병합
    for (int i = 0; i < M; i++) {
        for (int j = 2; j <= party[i][0]; j++) {
            merge(party[i][1], party[i][j]); // 첫 번째 사람과 나머지 사람들을 병합
        }
    }

    // 각 파티가 거짓말이 가능한지 검사
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= party[i][0]; j++) {
            if (div_set[Find(party[i][j])].Rank) {
                // 파티 참가자가 진실을 아는 집합에 속하면 거짓말 불가능
                break;
            } else if (j == party[i][0]) {
                // 모든 참가자가 진실을 모르면 거짓말 가능
                result++;
            }
        }
    }

    // 거짓말이 가능한 파티 수 출력
    cout << result;
    return 0;
}

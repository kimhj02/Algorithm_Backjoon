#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 퍼즐의 크기 (NxN)
vector<int> adj[1000 * 1000 + 1]; // 인접 리스트 (그래프)
int in_degree[1000 * 1000 + 1]; // 진입 차수 배열
int puzzle[1001][1001]; // 결과를 저장할 퍼즐 배열
queue<int> q; // 위상 정렬을 위한 큐

// 퍼즐 배열을 채우는 함수
void fill_puzzle(int loc, int num) {
    int x = (loc - 1) / N + 1; // 현재 위치의 행 번호
    int y = (loc - 1) % N + 1; // 현재 위치의 열 번호
    puzzle[x][y] = num; // 해당 위치에 숫자 배치
}

// 위상 정렬을 수행하는 함수
void topological_sort() {
    int num = 1; // 퍼즐에 넣을 숫자 (1부터 시작)
    while (!q.empty()) {
        int curr = q.front(); // 현재 처리할 노드
        q.pop();
        fill_puzzle(curr, num++); // 퍼즐에 숫자 채우기

        // 현재 노드와 연결된 노드들의 진입 차수 감소
        for (int next : adj[curr]) {
            in_degree[next]--;
            if (in_degree[next] == 0) q.push(next); // 진입 차수가 0이면 큐에 추가
        }
    }
}

int main() {
    cin >> N; // 퍼즐 크기 입력

    // 가로 방향 부등호 입력 처리
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            char sign;
            cin >> sign; // 부등호 입력
            int curr = (i - 1) * N + j; // 현재 위치 인덱스
            int right = curr + 1; // 오른쪽 위치 인덱스

            if (sign == '>') {
                adj[right].push_back(curr); // 오른쪽 값이 더 크므로 현재 위치로 가는 간선 추가
                in_degree[curr]++; // 현재 위치의 진입 차수 증가
            } else {
                adj[curr].push_back(right); // 현재 위치 값이 더 크므로 오른쪽으로 가는 간선 추가
                in_degree[right]++; // 오른쪽 위치의 진입 차수 증가
            }
        }
    }

    // 세로 방향 부등호 입력 처리
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            char sign;
            cin >> sign; // 부등호 입력
            int curr = (i - 1) * N + j; // 현재 위치 인덱스
            int down = curr + N; // 아래 위치 인덱스

            if (sign == '>') {
                adj[down].push_back(curr); // 아래 값이 더 크므로 현재 위치로 가는 간선 추가
                in_degree[curr]++; // 현재 위치의 진입 차수 증가
            } else {
                adj[curr].push_back(down); // 현재 위치 값이 더 크므로 아래로 가는 간선 추가
                in_degree[down]++; // 아래 위치의 진입 차수 증가
            }
        }
    }

    // 진입 차수가 0인 노드를 큐에 추가
    for (int i = 1; i <= N * N; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    // 위상 정렬 수행
    topological_sort();

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << puzzle[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
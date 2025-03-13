#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

// 이동 방향 설정 (L, R, U, D)
struct Direction {
    int dx, dy;
};
map<char, Direction> dxdy = {
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}}
};

void ward(int R, int C, vector<vector<char>> &board, vector<vector<char>> &answer, char check, int N, int M) {
    queue<pair<int, int>> queue;
    queue.push({R, C});
    board[R][C] = 'X';
    answer[R][C] = '.';

    while (!queue.empty()) {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();

        for (auto d : dxdy) {
            int ax = x + d.second.dx;
            int ay = y + d.second.dy;

            if (ax >= 0 && ax < N && ay >= 0 && ay < M && board[ax][ay] == check) {
                board[ax][ay] = 'X';
                answer[ax][ay] = '.';
                queue.push({ax, ay});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    vector<vector<char>> answer(N, vector<char>(M, '#'));

    // 맵 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 시작 위치 입력 (1-based index를 0-based index로 변환)
    int R, C;
    cin >> R >> C;
    R--; C--;

    string command;
    cin >> command;

    // 명령 실행
    for (char c : command) {
        if (c == 'W') {
            if (board[R][C] != 'X') {  // 이미 와드를 설치한 곳이 아니라면 설치
                ward(R, C, board, answer, board[R][C], N, M);
            }
        } else { // L, R, U, D
            R += dxdy[c].dx;
            C += dxdy[c].dy;
        }
    }

    // 모든 명령이 종료된 후, 현재 위치와 사방의 시야 확보
    answer[R][C] = '.';
    for (auto d : dxdy) {
        int ax = R + d.second.dx;
        int ay = C + d.second.dy;
        if (ax >= 0 && ax < N && ay >= 0 && ay < M) {
            answer[ax][ay] = '.';
        }
    }

    // 정답 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << answer[i][j];
        }
        cout << endl;
    }

    return 0;
}
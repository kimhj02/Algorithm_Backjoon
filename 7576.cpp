#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int row, column;
    cin >> column >> row;

    vector<vector<int>> box(row, vector<int>(column));
    queue<pair<int, int>> q;

    int total = 0; // 전체 토마토 개수
    int suc_tomato = 0;  // 익은 토마토 개수
    int empty = 0;   // 빈 공간 개수

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j}); // 익은 토마토를 큐에 추가
                suc_tomato++;
            } else if (box[i][j] == -1) {
                empty++;
            }
            total++;
        }
    }

    if (suc_tomato + empty == total) {
        cout << 0 << endl;
        return 0;
    }

    int days = -1;

    while (!q.empty()) {
        int size = q.size();
        days++;

        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) { // 4 방향으로 주변 토마토 익음 처리
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < row && ny >= 0 && ny < column && box[nx][ny] == 0) {
                    box[nx][ny] = 1;
                    q.push({nx, ny});
                    suc_tomato++;
                }
            }
        }
    }

    if (suc_tomato + empty == total) {
        cout << days << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> visited;
int row, col;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

// DFS를 사용하여 외부 공기를 2로 설정
void DFS_air(int x, int y) {
    visited[x][y] = 1;
    matrix[x][y] = 2; // 외부 공기로 설정

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
            // 0인 경우만 탐색 (외부 공기로 아직 설정되지 않은 경우)
            if (matrix[nx][ny] == 0 && !visited[nx][ny]) {
                DFS_air(nx, ny);
            }
        }
    }
}

// 치즈 녹이기 (외부 공기와 2면 이상 접촉한 치즈만 녹음)
bool melt_cheese() {
    vector<vector<int>> next_matrix = matrix; // 현재 상태 복사
    bool has_cheese = false; // 치즈가 남아있는지 확인하는 변수

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 1) { // 치즈인 경우
                int air_contact = 0; // 공기 접촉 면적 확인용

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        if (matrix[nx][ny] == 2) air_contact++; // 외부 공기와 접촉 확인
                    }
                }

                if (air_contact >= 2) next_matrix[i][j] = 0; // 두 면 이상 노출되면 녹음
                else has_cheese = true; // 치즈가 남아있음
            }
        }
    }

    matrix = next_matrix; // 갱신
    return has_cheese; // 치즈가 남아있는지 반환
}

int main() {
    cin >> row >> col;
    matrix.assign(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    int count = 0; // 걸리는 시간

    while (true) {
        // 이전 반복에서 2로 표시된 외부 공기를 0으로 초기화
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 2) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 방문 배열 초기화 후 외부 공기 DFS 실행
        visited.assign(row, vector<int>(col, 0));
        DFS_air(0, 0); // (0,0)에서 외부 공기 탐색 시작

        if (!melt_cheese()) break; // 치즈가 모두 녹으면 종료
        count++; // 시간 증가
    }

    cout << count+1 << endl; // 최종 결과 출력
    return 0;
}
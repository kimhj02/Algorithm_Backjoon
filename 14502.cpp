#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Position {
    int x, y;
};

vector<vector<int>> arr;       // 연구소 지도
vector<vector<int>> temp_arr;  // 바이러스 확산을 테스트할 임시 지도
vector<Position> empty_positions; // 빈 칸의 좌표
vector<Position> virus_positions; // 바이러스 좌표
int max_safe_count = 0;         // 최대 안전 영역 크기
int row, column;

// 상하좌우 이동을 위한 방향 배열
int dx[4] = {-1, 1, 0, 0}; //-1 왼쪽 1 오른쪽 0 가로 이동 없음
int dy[4] = {0, 0, -1, 1}; //-1 위쪽 1 아래쪽 0 세로 이동 없음

// 바이러스 확산 함수 (BFS 사용)
void spread_virus() {
    queue<Position> q; //x y 좌표를 저장할 수 있는 큐
    temp_arr = arr; //임시 큐를 현재 큐로 덮어씀 (여기에서 바이러스 뿌림)

    // 바이러스 시작 지점을 큐에 삽입
    for (const auto& virus : virus_positions) { //바이러스가 있는 위치를 큐에 넣음
        q.push(virus);
    }

    while (!q.empty()) { //모든 바이러스가 확산될 때 까지
        Position current = q.front();
        q.pop();//꺼내기

        // 상하좌우로 바이러스 확산
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < row && ny >= 0 && ny < column && temp_arr[nx][ny] == 0) {
                temp_arr[nx][ny] = 2; // 바이러스 확산
                q.push({nx, ny});
            }
        }
    }
}

// 안전 영역 크기 계산 함수
int calculate_safe_area() {
    int safe_count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (temp_arr[i][j] == 0) {
                safe_count++;
            }
        }
    }
    return safe_count;
}

// 벽 세우기 조합
void build_walls(int count) {
    if (count == 3) { // 벽을 3개 세운 경우
        spread_virus(); // 바이러스 확산
        max_safe_count = max(max_safe_count, calculate_safe_area()); // 최대 안전 영역 갱신
        return;
    }

    for (size_t i = 0; i < empty_positions.size(); i++) {
        int x = empty_positions[i].x;
        int y = empty_positions[i].y;

        if (arr[x][y] == 0) {
            arr[x][y] = 1; // 벽 세우기
            build_walls(count + 1); // 재귀 호출
            arr[x][y] = 0; // 벽 제거 (백트래킹)
        }
    }
}

int main() {
    cin >> row >> column;
    arr.resize(row, vector<int>(column));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                empty_positions.push_back({i, j}); // 빈 칸 좌표 저장
            } else if (arr[i][j] == 2) {
                virus_positions.push_back({i, j}); // 바이러스 좌표 저장
            }
        }
    }

    build_walls(0); // 벽 세우기 시작

    cout << max_safe_count << "\n"; // 최대 안전 영역 출력
    return 0;
}
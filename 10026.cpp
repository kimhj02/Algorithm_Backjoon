#include <iostream>
#include <vector>

using namespace std;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

vector<vector<char>> arr; // 원본 그림 배열
vector<vector<bool>> visited; // 방문 여부 저장

int n; // 그리드 크기

// DFS 탐색 함수 (일반인 & 적록색약 구분 X)
void dfs(int x, int y, char color) {
    visited[x][y] = true; //방문표시

    for (int i = 0; i < 4; i++) { // 4방향 탐색
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) { // 범위 내에 있고
            if (!visited[nx][ny] && arr[nx][ny] == color) { // 같은 색상이면 탐색
                dfs(nx, ny, color);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n, vector<char>(n));
    visited.resize(n, vector<bool>(n, false));

    // 그림 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int count1 = 0, count2 = 0;

    //일반인 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) { // 방문하지 않은 구역이면 DFS 실행
                dfs(i, j, arr[i][j]);
                count1++;
            }
        }
    }
    for (int i = 0; i < n; i++) { //초기화
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) { //적록색약 용으로 변환
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'G') {
                arr[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j, arr[i][j]);
                count2++;
            }
        }
    }

    cout << count1 << " " << count2 << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0}; //x축 이동 정의 (대각선까지 포함)
vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1}; //y축 이동 정의 (대각선까지 포함)

vector<vector<int>> map;
vector<vector<bool>> visited;
int width = -1, height = -1;

void dfs(int x, int y) { //dfs 함수
    visited[x][y] = true; //현재 지점 방문 처리

    for (int i = 0; i < 8; i++) { //탐색
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < height && ny >= 0 && ny < width) { //지도 안에 있으며
            if (map[nx][ny] == 1 && !visited[nx][ny]) { //방문되지 않은 섬인 경우 dfs 재귀로 탐색
                dfs(nx, ny);
            }
        }
    }
}

int get_count() { //지도에 있는 총 섬의 개수 count
    int count = 0;
    visited.assign(height, vector<bool>(width, false)); //방문 배열 초기화

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 1 && !visited[i][j]) { //땅이면서 방문되지 않은 것을 찾음
                dfs(i, j); //찾았다면 dfs로 주변에 연결되어 있는 섬들을 찾음(이건 하나로 처리할거임)
                count++; //그리고 1 증가
            }
        }
    }
    return count; //다 찾으면 count 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> width >> height;
        if (width == 0 && height == 0) break;
        map.assign(height, vector<int>(width));

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cin >> map[i][j];
            }
        }

        cout << get_count() << endl;
    }

    return 0;
}
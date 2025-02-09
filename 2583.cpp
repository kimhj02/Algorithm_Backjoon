#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> visited;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

int row, column, num, area_size;

void dfs(int x, int y) {
    visited[x][y] = true;
    area_size++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < row && ny >= 0 && ny < column) {
            if (!visited[nx][ny] && arr[nx][ny] == 0) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> column >> num;

    arr.resize(row, vector<int>(column, 0));
    visited.resize(row, vector<bool>(column, false));

    for (int i = 0; i < num; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                arr[y][x] = 1;
            }
        }
    }

    vector<int> areas; //크기 저장용
    int count = 0;

    // 모든 영역 탐색
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (!visited[i][j] && arr[i][j] == 0) {
                area_size = 0;
                dfs(i, j);
                areas.push_back(area_size);
                count++;
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << count << endl;
    for (int size : areas) {
        cout << size << " ";
    }

    return 0;
}
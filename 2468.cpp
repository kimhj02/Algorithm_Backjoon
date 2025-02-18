#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};

vector<vector<int>> arr;
vector<vector<bool>> visited;

void dfs(int x,int y, int num) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < num && ny < num) {
            if (!visited[nx][ny]) {
                dfs(nx, ny, num);
            }
        }
    }
}

int main() {
    int num = 0;
    cin >> num;
    arr.resize(num);
    for (int i = 0; i < num; i++) {
        arr[i].resize(num);
    }
    visited.resize(num);
    for (int i = 0; i < num; i++) {
        visited[i].resize(num,false);
    }

    int max_height = 0;
    for (int i = 0; i < num; i++) { //visited 배열 초기화
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
            max_height = max(max_height, arr[i][j]);
        }
    }

    int result = 1;
    for (int height = 1; height <= max_height; height++) {
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                visited[i][j] = arr[i][j] <= height;
            }
        }

        int count = 0;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                if (!visited[i][j]) {
                    dfs(i, j, num);
                    count++;
                }
            }
        }
        result = max(result, count);
    }

    cout << result << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> dx = {-1, 0, 1, 0}; // 좌우 이동
vector<int> dy = {0, 1, 0, -1}; // 상하 이동

vector<vector<char>> arr; // 알파벳 배열
set<char> visited; // 방문한 알파벳 집합 (중복 방지)

int R, C; // 행, 열 크기

int DFS(int i, int j, int count) {
    int max_count = count;

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
            // 방문한 적 없는 알파벳이면 이동
            if (visited.count(arr[ni][nj]) == 0) {  // 방문하지 않은 알파벳이라면
                visited.insert(arr[ni][nj]);  // 방문 처리
                max_count = max(max_count, DFS(ni, nj, count + 1));  // DFS 탐색
                visited.erase(arr[ni][nj]);  //방문 해제
            }
        }
    }

    return max_count;
}

int main() {
    // 세로 R, 가로 C칸으로 된 모드 존재
    // 각 칸에는 대문자 알파벳이 하나씩 존재, 좌측 상단(1행1열)에는 말이 있음
    // 말을 상하좌우 인접한 네 칸 중 한 칸으로 이동 가능
    // 새로운 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀있는 알파벳과 달라야 함
    // 좌측 상단에서 시작해서 말이 최대한 몇 칸을 지날 수 있는지 구하는 프로그램 작성
    // 시작 칸도 1칸으로 포함임

    cin >> R >> C;
    arr.resize(R, vector<char>(C));

    for (int i = 0; i < R; i++) { // 행을 입력
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    visited.insert(arr[0][0]); // 시작점 알파벳 저장
    int result = DFS(0, 0, 1); // (0,0)에서 시작하며 1칸 이동했다고 초기화

    cout << result << endl;
    return 0;
}
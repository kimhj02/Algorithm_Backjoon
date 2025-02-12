#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS 함수 정의
void dfs(vector<vector<int>>& map, int x, int y, int row, int column)
{
    // 방향 벡터 (상, 하, 좌, 우)
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    // 현재 위치 방문 처리
    map[x][y] = 0;

    // 인접한 4방향 탐색
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 다음 좌표가 유효 범위 내에 있고 배추가 있는 경우
        if (nx >= 0 && nx < row && ny >= 0 && ny < column && map[nx][ny] == 1)
        {
            dfs(map, nx, ny, row, column);
        }
    }
}

int main(void)
{
    int test_case, row, column, num;
    int x, y;
    cin >> test_case; // test_case 입력

    for (int i = 0; i < test_case; i++)
    {
        cin >> row >> column >> num; // 가로, 세로, 숫자 입력 받기

        vector<vector<int>> map(row, vector<int>(column, 0)); // 0으로 초기화된 2D 벡터

        for (int j = 0; j < num; j++) { // 사용자가 입력한 위치의 값 1로 설정
            cin >> x >> y;
            if (x >= 0 && x < row && y >= 0 && y < column) { // 벡터 인덱스 범위 검사
                map[x][y] = 1;
            }
        }

        int bug_count = 0; // 벌레 수 초기화

        // 모든 위치 탐색하여 연결된 컴포넌트 수 구하기
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < column; c++)
            {
                if (map[r][c] == 1) { // 배추가 있는 경우
                    dfs(map, r, c, row, column); // DFS 호출
                    bug_count++; // 벌레 수 증가
                }
            }
        }

        cout << bug_count << endl; // 결과 출력
    }

    return 0;
}

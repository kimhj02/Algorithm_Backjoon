#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix(9, vector<int>(9));
vector<pair<int, int>> blanks; //0 저장용

bool is_valid(int x, int y, int num) {
    // 행 검사
    for (int i = 0; i < 9; i++) {
        if (matrix[x][i] == num) return false;
    }

    // 열 검사
    for (int i = 0; i < 9; i++) {
        if (matrix[i][y] == num) return false;
    }

    // 3x3 박스 검사
    int start_x = (x / 3) * 3;
    int start_y = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[start_x + i][start_y + j] == num) return false;
        }
    }

    return true;
}

void solve(int index) {
    if (index == blanks.size()) { // 모든 빈 칸을 채운 경우 출력 후 종료
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        exit(0); // 정답을 찾으면 프로그램 종료
    }

    int x = blanks[index].first; //0인 좌표 x
    int y = blanks[index].second;//0인 좌표 y

    for (int num = 1; num <= 9; num++) {
        if (is_valid(x, y, num)) { //유효한지 확인
            matrix[x][y] = num; // 숫자 넣기
            solve(index + 1);   // 다음 빈 칸 탐색
            matrix[x][y] = 0;   // 백트래킹 (되돌리기)
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> matrix[i][j]; //스도쿠 입력
            if (matrix[i][j] == 0) {
                blanks.push_back({i, j}); //빈칸 위치 저장
            }
        }
    }

    solve(0); // 백트래킹 시작

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int row, col;
bool is_valid = true;
vector<vector<char>> matrix;

void check(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue; //범위 밖이므로 무시

        if (matrix[nx][ny] == 'W') { //주변에 늑대가 있다면 불가능
            is_valid = false;
            return;
        }
    }
}

int main() {
    cin >> row >> col;
    matrix.assign(row, vector<char>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < row && is_valid; i++) {
        for (int j = 0; j < col && is_valid; j++) {
            if (matrix[i][j] == 'S') { //양이 있으면 확인
                check(i, j);
            }
        }
    }

    if (!is_valid) { //무조건 만나면 0
        cout << 0 << endl;
    } else { //아니라면 출력
        for (int i = 0; i < row; i++) { //나머지를 울타리로 변환
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '.') {
                    matrix[i][j] = 'D';
                }
            }
        }

        cout << 1 << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
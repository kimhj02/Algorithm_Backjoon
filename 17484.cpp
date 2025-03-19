#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2147483647; // 큰 값 설정

int main() {
    int row, column;
    cin >> row >> column;

    vector<vector<int>> matrix(row, vector<int>(column, 0));

    for (int i = 0; i < row; i++) { //입력
        for (int j = 0; j < column; j++) {
            cin >> matrix[i][j];
        }
    }

    // DP 배열 정의
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(column, vector<int>(3, INF)));

    // 첫 번째 행 초기화
    for (int j = 0; j < column; j++) {
        for (int d = 0; d < 3; d++) { //3방향으로 초기화
            dp[0][j][d] = matrix[0][j];
        }
    }

    // DP 진행
    for (int i = 1; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (j > 0) { // 왼쪽
                dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + matrix[i][j];
            }
            // 아래
            dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + matrix[i][j];

            if (j < column - 1) { // 오른쪽
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + matrix[i][j];
            }
        }
    }

    int result = INF;
    for (int j = 0; j < column; j++) {
        for (int d = 0; d < 3; d++) {
            result = min(result, dp[row-1][j][d]);
        }
    }

    cout << result << endl;
    return 0;
}
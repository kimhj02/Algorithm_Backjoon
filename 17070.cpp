//
// Created by 김현진 on 25. 6. 4.
//
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;
vector<vector<vector<int>>> dp;

int main() {
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n));
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(3, 0)));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    // 초기 상태: (0, 1)에 가로 파이프
    dp[0][1][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) continue;

            if (j - 1 >= 0) {
                dp[i][j][0] += dp[i][j - 1][0];
                dp[i][j][0] += dp[i][j - 1][2];
            }

            if (i - 1 >= 0) {
                dp[i][j][1] += dp[i - 1][j][1];
                dp[i][j][1] += dp[i - 1][j][2];
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                if (board[i - 1][j] == 0 && board[i][j - 1] == 0 && board[i - 1][j - 1] == 0) {
                    dp[i][j][2] += dp[i - 1][j - 1][0];
                    dp[i][j][2] += dp[i - 1][j - 1][1];
                    dp[i][j][2] += dp[i - 1][j - 1][2];
                }
            }
        }
    }

    int result = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
    cout << result << endl;

    return 0;
}
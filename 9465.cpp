//
// Created by 김현진 on 25. 5. 15.
//
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int sticker[2][MAX];
int dp[2][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; // 테스트 케이스 수
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        // 스티커 점수 입력
        for (int i = 0; i < n; i++)
            cin >> sticker[0][i];
        for (int i = 0; i < n; i++)
            cin >> sticker[1][i];

        // 초기값 설정
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        if (n > 1) {
            dp[0][1] = sticker[0][1] + dp[1][0];
            dp[1][1] = sticker[1][1] + dp[0][0];
        }

        // DP 점화식 적용
        for (int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }

        // 결과 출력
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
}
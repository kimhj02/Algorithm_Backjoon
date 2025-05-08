#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000000;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    // 초기화: 정수 1개로 합 만드는 경우는 모두 1가지
    for (int j = 0; j <= n; j++) {
        dp[1][j] = 1;
    }

    // 점화식 적용
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MAX;
            }
        }
    }

    cout << dp[k][n] << endl;
    return 0;
}
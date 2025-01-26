#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    for (int j = 1; j <= 9; ++j) { //초기 dp 테이블 채우기
        dp[1][j] = 1;
    }

    for (int i = 2; i <= N; ++i) { //나머지 채우기
        for (int j = 0; j <= 9; ++j) {
            if (j > 0) dp[i][j] += dp[i-1][j-1];
            if (j < 9) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }

    int result = 0;
    for (int j = 0; j <= 9; ++j) {
        result = (result + dp[N][j]) % MOD;
    }

    cout << result << endl;
    return 0;
}
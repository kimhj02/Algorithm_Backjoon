#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    // 홀수인 경우는 절대로 채울 수 없음
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    // 초기 상태
    dp[0] = 1;      // 타일이 하나도 없는 경우 = 1가지 (기저)
    dp[2] = 3;      // 기본 3가지 채우기 방법

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }

    cout << dp[n] << endl;

    return 0;
}

/*
예시:
n = 0 → 1          // 아무 것도 없는 경우
n = 1 → 0          // 홀수라서 불가
n = 2 → 3          // 기본 구조 3가지능
n = 3 → 0          // 홀수는 항상 0
n = 4 → 11
n = 5 → 0
n = 6 → 41         // dp[4]*3 + dp[2]*2 + dp[0]*2 = 11*3 + 3*2 + 1*2 = 41
n = 8 → 153
n = 10 → 571
*/
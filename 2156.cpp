#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> grape(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> grape[i];
    }

    if (N == 1) {
        cout << grape[1] << endl;
        return 0;
    }

    vector<int> dp(N + 1, 0);

    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];

    for (int i = 3; i <= N; ++i) {
        dp[i] = max({dp[i-1], dp[i-2] + grape[i], dp[i-3] + grape[i-1] + grape[i]});
    }

    cout << dp[N] << endl;
    return 0;
}
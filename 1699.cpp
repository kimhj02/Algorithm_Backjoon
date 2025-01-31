#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int case_num;
    cin >> case_num;

    vector<int> dp(case_num + 1, 0);

    for (int i = 1; i <= case_num; ++i) {
        dp[i] = i;
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[case_num] << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct day {
    int date;
    int pay;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int case_num = 0;
    cin >> case_num;

    vector<day> days(case_num);
    for (int i = 0; i < case_num; i++) {
        cin >> days[i].date >> days[i].pay;
    }
    vector<long long> dp(case_num + 2, 0);

    long long max_profit = 0;

    for (int i = 1; i <= case_num; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        int next_day = i + days[i - 1].date;

        if (next_day <= case_num + 1) {
            dp[next_day] = max(dp[next_day], dp[i] + days[i - 1].pay);
        }

        max_profit = max(max_profit, dp[i]);
    }

    cout << max(max_profit, dp[case_num + 1]) << endl;

    return 0;
}
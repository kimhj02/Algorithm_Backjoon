#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

struct computer {
    double w;
    double t;
};

int main() {
    int case_num = 0;
    int c1 = 0, c2 = 0;

    cin >> case_num;
    vector<computer> com(case_num);
    vector<int> power(case_num); // 전기료 저장 벡터

    for (int i = 0; i < case_num; i++) {
        int w, t;
        cin >> w >> t;
        double change_w, change_t;
        change_w = w / 1000.0;
        change_t = t / 60.0;

        com[i].w = change_w;
        com[i].t = change_t;
        power[i] = round(change_w * change_t * 96);
    }

    cin >> c1 >> c2;

    vector<int> dp(c2 + 1, 0);
    dp[0] = 1;

    for (int cost : power) {
        for (int j = c2; j >= cost; --j) {
            dp[j] = (dp[j] + dp[j - cost]) % MOD;
        }
    }

    int result = 0;
    for (int i = c1; i <= c2; i++) {
        result = (result + dp[i]) % MOD;
    }

    cout << result << endl;
    return 0;
}
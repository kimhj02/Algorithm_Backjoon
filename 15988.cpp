#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int case_num;
    cin >> case_num;

    vector<long long> dp;
    dp.resize(1000 + 1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;  // (1+1+1), (1+2), (2+1), (3)

    for (int i = 4; i <= 1001; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000009;
    }

    for (int i = 0; i < case_num; i++) {
        int cases;
        cin >> cases;
        cout << dp[cases]%1000000009 << endl;
    }

    return 0;
}

//1 : 1 (1)
//2 : 1 1, 2 (2)
//3 : 1 1 1, 2 1, 1 2, 3 (4)
//4 : 1 1 1 1, 2 1 1, 1 2 1, 1 1 2, 3 1, 1 3, 2 2 (7)
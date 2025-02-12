#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int person_num, choice_person_num, stat;
    cin >> person_num >> choice_person_num >> stat;

    vector<int> arr(person_num);
    vector<vector<bool>> dp(choice_person_num + 1, vector<bool>(stat * choice_person_num + 1, false));

    for (int i = 0; i < person_num; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = a;
    }

    for (int p : arr) {
        for (int i = choice_person_num - 1; i >= 1; i--) {
            for (int j = stat * choice_person_num; j >= p; j--) {
                dp[i + 1][j] = dp[i + 1][j] || dp[i][j - p]; // j-p가 가능하면 현재도 가능
            }
        }
        dp[1][p] = true;
    }

    int ans = 0;
    for (int i = 0; i <= stat * choice_person_num; i++) {
        if (dp[choice_person_num][i]) {
            ans = max(ans, i * (stat * choice_person_num - i));
        }
    }

    cout << ans << endl;
    return 0;
}
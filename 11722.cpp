//
// Created by 김현진 on 25. 5. 27.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int case_num = 0;
    cin >> case_num;
    vector<int> arr(case_num, 0);
    for (int i = 0; i < case_num; i++) {
        cin >> arr[i];
    }

    vector<int> dp(case_num, 1); // 각 위치에서의 최대 감소 수열 길이
    int max_len = 1;

    for (int i = 1; i < case_num; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) { // 감소하는 조건
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }

    cout << max_len << endl;
    return 0;
}
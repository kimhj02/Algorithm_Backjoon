//
// Created by 김현진 on 25. 5. 10.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> count(10, 0);

    if (N == 0) {
        count[0]++;
    }

    while (N > 0) {
        int digit = N % 10;
        if (digit == 6 || digit == 9) {
            count[6]++;
        } else {
            count[digit]++;
        }
        N /= 10;
    }

    // 6과 9는 서로 대체 가능하므로 합쳐서 계산
    count[6] = (count[6] + 1) / 2;

    // 최대값을 찾아 필요한 세트 수 결정
    int result = *max_element(count.begin(), count.end());
    cout << result;

    return 0;
}